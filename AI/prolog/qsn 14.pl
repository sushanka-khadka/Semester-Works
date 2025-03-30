% Facts
:- discontiguous is_a/2,has/2,likes/2.
is_a(mat1, mat).
is_a(cat1, cat).
is_a(tom, cat).
is_a(bird1, bird).
sat_on(cat1, mat1).
sat_on(the_cat, the_mat). % Assuming 'the_cat' is cat1 and 'the_mat' is mat1
caught(tom, bird1).
owned_by(tom, john).
color(tom, ginger).
likes(cat,cream).

is_a(cat, mammal).
is_a(bird, animal).
is_a(mammal, animal).
has(mammal, fur).

% Rules to infer relationships
likes(X, cream) :- is_a(X,cat).
is_a(X,mammal) :- is_a(X,cat).
is_a(X, animal) :- is_a(X, mammal).
is_a(X, animal) :- is_a(X, bird).
has(X,fur) :- is_a(X,mammal).


% Queries
% Check if Tom is an animal
%?- is_a(tom, animal).

% Find out who sat on the mat
%?- sat_on(X, mat1).


% Determine the color of Tom
%?- color(tom, Color).

% Check if Cat1 likes cream
%?- likes(cat1, cream).

% Find all animals in the Semantic Net
%?- is_a(X, animal).

% Check who caught Bird1
%?- caught(X, bird1).

% Find out who owns Tom
%?- owned_by(tom, Owner).

% Check if Mammals have fur
%?- has(mammal, fur).

% Find the relationships of Tom
%?- is_a(tom, X).

































