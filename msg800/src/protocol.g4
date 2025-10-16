grammar protocol;   

protocol: none # protocol_none
        | bird # protocol_bird
        | xor # protocol_xor
        ;

none: 'none';

bird: 'bird' bird_params_part;

xor: 'xor' '(' U8  ')';

bird_params_part: '(' bird_params ')'
        |
        ;

bird_params: 
        | bird_param (',' bird_param) *
        ;

bird_param: 'key' '=' U8_16     # bird_param_key
        | 'iv' '=' U8_16        # bird_param_iv 
        | 'key_str' '=' STR     # bird_param_key_str 
        | 'iv_str' '=' STR      # bird_param_iv_str 
        ;

fragment F_HEX_DIGIT: [0-9a-fA-F];

fragment F_U8: F_HEX_DIGIT F_HEX_DIGIT;

U8: 'hex_' F_U8;

U8_16: 'hex_' F_U8 F_U8 F_U8 F_U8 F_U8 F_U8 F_U8 F_U8 F_U8 F_U8 F_U8 F_U8 F_U8 F_U8 F_U8 F_U8;

STR: [a-zA-Z0-9_]+;

NEWLINE: [\r\n]+ -> skip;

SPACE: [ \t]+ -> skip;