import typer

app = typer.Typer()

def flipping_puzzle(init_state, get_flip_vector, size):
    target_state = (True,) * size

    def get_next_state(state, action):
        flip_arr = get_flip_vector(action)
        new_state = tuple(map(lambda a,b:a^b, flip_arr, state))
        return new_state

    def get_action_list(state):
        return [i for i in range(size)]

    path = {}
    path[init_state] = (None, None, 0)

    closed_states = set()
    open_states = [init_state]

    while len(open_states) > 0:
        open_states = sorted(open_states, key = lambda x: - path[x][2] )
        state = open_states.pop()        
        if state == target_state:
            print("Success")

            answer = []
            the_state = target_state
            while the_state != init_state:
                parent = path[the_state]
                the_state = parent[0]
                answer.append(parent[1])

            answer.reverse()
            print(answer)
            return


        closed_states.add(state)

        for action in get_action_list(state):
            next_state = get_next_state(state, action)
            if not next_state in closed_states:
                if not next_state in open_states:
                    open_states.append(next_state)
                    path[next_state] = (state, action, path[state][2]+1)

                else:
                    old_cost = path[next_state][2]
                    new_cost = path[state][2]+1
                    if new_cost < old_cost:
                        path[next_state] = (state, action, new_cost)

    print("Fail")


@app.command()
def puzzle8(s0:bool, s1:bool, s2:bool, s3:bool, s4:bool, s5:bool, s6:bool, s7:bool):

    def get_flip_vector(action):
        flip_arr = [False] * 8
        flip_arr[action] = True
        flip_arr[(action+1) % 8] = True
        flip_arr[(action+7) % 8] = True
        return flip_arr
    init_state = (s0, s1, s2, s3, s4, s5, s6, s7)
    flipping_puzzle(init_state, get_flip_vector, 8)
    

@app.command()
def puzzle5(s0:bool, s1:bool, s2:bool, s3:bool, s4:bool):

    def get_flip_vector(action):
        flip_arr = [False] * 8
        flip_arr[action] = True
        flip_arr[(action+2) % 5] = True
        flip_arr[(action+3) % 5] = True
        return flip_arr
    init_state = (s0, s1, s2, s3, s4)
    flipping_puzzle(init_state, get_flip_vector, 5)
