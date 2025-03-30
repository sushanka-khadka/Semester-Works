% Facts about a family
parent(john, mary).        % john is a parent of mary
parent(mary, sam).         % mary is a parent of sam
parent(john, mike).        % john is a parent of mike
parent(mike, sara).        % mike is a parent of sara

% Rule to define grandparent relationship
grandparent(X, Y) :- parent(X, Z), parent(Z, Y).

% Atoms and Variables:
% Atom: john, mary, sam, mike, sara
% Variable: X, Y, Z

% Queries to run the rule
% ?- parent(john, mary).
% ?- grandparent(john, sam).
