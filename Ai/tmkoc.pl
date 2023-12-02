male(jethalal).
male(bhide).
male(sodhi).
male(hathi).
male(bapuji).
female(daya).
female(madhuri).
female(roshan).
female(komal).

parent(tappu,jethalal).
parent(tappu,daya).
parent(sonu,bhide).
parent(sonu,madhvi).
parent(gogi,sodhi).
parent(gogi,roshan).
parent(goli,hathi).
parent(goli,komal).
parent(jethalal,bapuji).
occupation(jethala,businessman).
occupation(bhide,teacher).
occupation(sodhi,mechanic).
occupation(hathi,doctor).
occupation(bapuji,retired).
occupation(iyer,scientist).
occupation(tarak,writer).
occupation(daya,housewife).
occupation(madhvi,housewife).
occupation(roshan,housewife).
occupation(komal,housewife).
occupation(babitaji,housewife).
occupation(anjali,housewife).
best_friends(jethalal,taarak).

child(X,Y):- parent(Y,X).
best_friend(X, Y) :- best_friends(X, Y).
mother(X, Y):- parent(X, Y), female(Y).
father(X, Y):- parent(X, Y), male(Y).
spouse(X, Y):- parent(Z, X), parent(Z, Y).
grandparent(X, Y):- parent(X, Z), parent(Z, Y).
