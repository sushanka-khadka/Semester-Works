% Facts about the family tree
parent(john, mary).
parent(mary, sam).
parent(sam, kate).
parent(kate, alice).

% Rule to define ancestor relationship
ancestor(X, Y) :- parent(X, Y).
ancestor(X, Y) :- parent(X, Z), ancestor(Z, Y).

% Queries to test the rule
% ?- ancestor(john, alice).
% ?- ancestor(mary, kate).
% ?- ancestor(sam, alice).
