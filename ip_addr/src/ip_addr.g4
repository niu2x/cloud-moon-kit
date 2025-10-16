grammar ip_addr;   

ip_addr:   ':' port
        |  ip ':' port
        |  ip
        ;

ip: ipv4;

ipv4: NUM '.' NUM '.' NUM '.' NUM;

port: NUM;

NUM: [0-9]+;

NEWLINE: [\r\n]+ -> skip;

SPACE: [ \t]+ -> skip;