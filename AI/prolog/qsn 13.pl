% Facts about the family tree
parent(john, mary).
parent(john, mike).
parent(susan, mary).
parent(susan, mike).
parent(mary, sam).
parent(tom, sam).
parent(mike, kate).
parent(linda, kate).

% Rules to define relationships
father(X, Y) :- parent(X, Y), male(X).
mother(X, Y) :- parent(X, Y), female(X).
sibling(X, Y) :- parent(Z, X), parent(Z, Y), X \= Y.
brother(X, Y) :- sibling(X, Y), male(X).
sister(X, Y) :- sibling(X, Y), female(X).
grandparent(X, Y) :- parent(X, Z), parent(Z, Y).
grandfather(X, Y) :- grandparent(X, Y), male(X).
grandmother(X, Y) :- grandparent(X, Y), female(X).
ancestor(X, Y) :- parent(X, Y).
ancestor(X, Y) :- parent(X, Z), ancestor(Z, Y).
descendant(X, Y) :- ancestor(Y, X).
uncle(X, Y) :- brother(X, Z), parent(Z, Y).
aunt(X, Y) :- sister(X, Z), parent(Z, Y).

% Gender facts
male(john).
male(mike).
male(sam).
male(tom).
female(susan).
female(mary).
female(kate).
female(linda).

% Queries to test the rules
% ?- father(john, mary).
% ?- mother(susan, mike).
% ?- sibling(mary, mike).
% ?- brother(mike, mary).
% ?- sister(mary, mike).
% ?- grandfather(john, sam).
% ?- grandmother(susan, kate).
% ?- ancestor(john, sam).
% ?- descendant(sam, john).
% ?- uncle(mike, sam).
% ?- aunt(mary, kate).
