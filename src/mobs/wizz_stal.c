/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** wizz_stal
*/

#include "global.h"

animation_t *dup_animation(animation_t *base)
{
    animation_t *anim = malloc(sizeof(animation_t));

    anim->texture = sfTexture_copy(base->texture);
    anim->sprite = sfSprite_copy(base->sprite);
    anim->position = base->position;
    anim->scaling = base->scaling;
    anim->color = base->color;
    anim->sprite_nb = base->sprite_nb;
    anim->lines_nb = base->lines_nb;
    anim->texture_size = base->texture_size;
    anim->delay = base->delay;
    anim->pause = base->pause;
    anim->play_count = 0;
    init_animation(anim);
    sfSprite_setScale(anim->sprite, scale);
    return (anim);
}

stalactite_t *create_stalactite(mob_t *mob)
{
    stalactite_t *stal = malloc(sizeof(stalactite_t));

    stal->stalactite = sfSprite_copy(get_animation_w_name(mob->animation_list,
    "stalactite")->sprite);
    stal->shadow = sfSprite_copy(get_animation_w_name(mob->animation_list,
    "shadow")->sprite);
    stal->impact = dup_animation(get_animation_w_name(mob->animation_list,
    "impact"));
    stal->drop = dup_animation(get_animation_w_name(mob->animation_list,
    "drop"));
    stal->target = (sfVector2f){rand() % BASE_WIDTH, rand() % BASE_HEIGHT};
    stal->position = (sfVector2f){stal->target.x, stal->target.y - 96};
    sfSprite_setPosition(stal->impact->sprite, stal->target);
    sfSprite_setPosition(stal->shadow, stal->target);
    sfSprite_setPosition(stal->drop->sprite, stal->position);
    stal->position = (sfVector2f){stal->target.x, stal->target.y - 400};
    sfSprite_setPosition(stal->stalactite, stal->position);
    stal->clock = sfClock_create();
    stal->current = 0;
    return (stal);
}

node_t *create_stalactite_list(mob_t *mob)
{
    node_t *start = malloc(sizeof(node_t));
    node_t *tmp = start;
    node_t *previous = NULL;
    int max = rand() % 30 + 10;

    start->next = NULL;
    for (int i = 0; i < max; i++) {
        previous != NULL ? previous->next = tmp : (void)previous;
        tmp->data = create_stalactite(mob);
        tmp->next = NULL;
        previous = tmp;
        tmp = malloc(sizeof(node_t));
    }
    return (start);
}

void draw_stal(sfRenderWindow *window, stalactite_t *stal, game_t *game)
{
    if (stal->current < 11) {
        draw_animation(window, stal->drop, game);
        sfRenderWindow_drawSprite(window, stal->shadow, NULL);
        sfRenderWindow_drawSprite(window, stal->stalactite, NULL);
        if (sfClock_getElapsedTime(stal->clock).microseconds > 120000) {
            sfClock_restart(stal->clock);
            sfSprite_move(stal->stalactite, (sfVector2f){0, 400/11});
            stal->current++;
        }
    } else {
        draw_animation(window, stal->impact, game);
    }
}

void drop_stalactite(sfRenderWindow *window, game_t *game, mob_t *mob)
{
    animation_t *effect;
    stalactite_t *stal;
    sfFloatRect mob_rect = sfSprite_getGlobalBounds(mob->animation->sprite);

    if (mob->state != 4)
        return;
    effect = get_animation_w_name(mob->animation_list, "effect");
    center_origin_sprite(effect->sprite);
    sfSprite_setPosition(effect->sprite, (sfVector2f){
        mob_rect.left + mob_rect.width / 2,
        mob_rect.top + mob_rect.height / 2});
    draw_animation(window, effect, game);
    for (node_t *node = mob->misc; node != NULL; node = node->next) {
        stal = node->data;
        draw_stal(window, stal, game);
        handle_wizz_damage(game, stal, mob);
    }
}