% Facts
bird(robin).
bird(sparrow).
bird(eagle).
bird(penguin).
bird(ostrich).
bird(peacock).
bird(hawk).
bird(parrot).
bird(crow).
bird(swallow).
bird(pelican).
bird(flamingo).
bird(owl).
bird(kiwi).
bird(toucan).

has_wings(robin).
has_wings(sparrow).
has_wings(eagle).
has_wings(penguin).
has_wings(ostrich).
has_wings(peacock).
has_wings(hawk).
has_wings(parrot).
has_wings(crow).
has_wings(swallow).
has_wings(pelican).
has_wings(flamingo).
has_wings(owl).
has_wings(kiwi).
has_wings(toucan).

can_fly(robin).
can_fly(sparrow).
can_fly(eagle).
can_fly(parrot).
can_fly(crow).
can_fly(swallow).

has_long_neck(ostrich).
has_long_neck(peacock).
has_long_neck(flamingo).

has_strong_beak(eagle).
has_strong_beak(parrot).
has_strong_beak(hawk).
has_strong_beak(crow).
has_strong_beak(pelican).
has_strong_beak(toucan).

has_colorful_feathers(peacock).
has_colorful_feathers(parrot).
has_colorful_feathers(flamingo).

% Rules
fly_bird(X) :- bird(X), can_fly(X).

large_bird(X) :- bird(X), has_wings(X), has_long_neck(X).

predator(X) :- bird(X), has_strong_beak(X), can_fly(X).

colorful_bird(X) :- bird(X), has_colorful_feathers(X).

% Queries
% 1. List all birds that can fly
% ?- fly_bird(X).
%
% 2. List all large birds
% ?- large_bird(X).
%
% 3. List all predators
% ?- predator(X).
%
% 4. List all colorful birds
% ?- colorful_bird(X).
%
% 5. Check if robin can fly
% ?- can_fly(robin).
%
% 6. Check if penguin can fly
% ?- can_fly(penguin).
%
% 7. Check if eagle is a predator
% ?- predator(eagle).
%
% 8. Check if kiwi is a large bird
% ?- large_bird(kiwi).
%
% 9. List all birds that have long necks
% ?- has_long_neck(X).
%
% 10. Check if crow is a colorful bird
% ?- colorful_bird(crow).