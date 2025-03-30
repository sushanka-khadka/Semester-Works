% Facts about Prolog
language(prolog).
origin_year(1972).
creator('Alain Colmerauer').
purpose('Artificial Intelligence and computational linguistics').

% Rules to provide information about Prolog
about_language :-
    language(Lang),
    origin_year(Year),
    creator(Creator),
    purpose(Purpose),
    write('Language: '), write(Lang),nl,
    write('Origin Year: '), write(Year), nl,
    write('creator: '),write(Creator),nl,
    write('Purpose: '), write(Purpose), nl.

% Query to run the rule
% ?- about_language.
