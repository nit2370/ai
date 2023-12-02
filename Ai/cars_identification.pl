% Facts about cars
car(mercedes, luxury, sedan, germany).
car(toyota, economy, sedan, japan).
car(ford, standard, suv, usa).
car(honda, economy, coupe, japan).
car(bmw, luxury, coupe, germany).
car(chevrolet, standard, suv, usa).

% Rules for categorizing cars
is_luxury(Car) :- car(Car, luxury, _, _).
is_economy(Car) :- car(Car, economy, _, _).
is_standard(Car) :- car(Car, standard, _, _).

is_sedan(Car) :- car(Car, _, sedan, _).
is_suv(Car) :- car(Car, _, suv, _).
is_coupe(Car) :- car(Car, _, coupe, _).

made_in_country(Car, Country) :- car(Car, _, _, Country).

% Example queries
% To find luxury cars:
% ?- is_luxury(X).
%
% To find cars made in Japan:
% ?- made_in_country(X, japan).
%
% To find economy sedans:
% ?- is_economy(X), is_sedan(X).
