/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** cinematic
*/

#include "global.h"

cinematic_t *init_cinematic(void)
{
    cinematic_t *cinematic = malloc(sizeof(cinematic_t));
    sfFont *font = sfFont_createFromFile(TITLE_FONT);

    cinematic->sprite = NULL;
    cinematic->loaded = 0;
    cinematic->played = 0;
    cinematic->pos = (sfVector2f) {0, 600};
    cinematic->movement = (sfVector2f) {15, 0};
    cinematic->delay = 10000;
    cinematic->movement_clock = sfClock_create();
    cinematic->pause_clock = sfClock_create();
    cinematic->text = create_text(font, 100);
    sfText_setColor(cinematic->text, sfWhite);
    return (cinematic);
}

void load_cinematic(__attribute__((unused))sfRenderWindow *window,
cinematic_t *cinematic, game_t *game)
{
    sfFloatRect rect;

    if (cinematic->loaded == 0) {
        cinematic->sprite =
        load_sprite(get_property(game->map->tag, "img_path"));
        sfSprite_setPosition(cinematic->sprite, cinematic->pos);
        sfText_setPosition(cinematic->text, (sfVector2f){0, 170});
        sfText_setString(cinematic->text,
        get_property(game->map->tag, "boss_name"));
        cinematic->loaded = 1;
        center_origin_sprite(cinematic->sprite);
        rect = sfText_getGlobalBounds(cinematic->text);
        sfText_setOrigin(cinematic->text,
        (sfVector2f){rect.width/2, rect.height/2});
    }
}

void draw_cinematic_background(sfRenderWindow *window)
{
    sfRectangleShape *background = sfRectangleShape_create();
    sfRectangleShape *bg_text = sfRectangleShape_create();

    sfRectangleShape_setFillColor(background, sfColor_fromRGBA(0, 0, 0, 120));
    sfRectangleShape_setFillColor(bg_text, sfColor_fromRGBA(0, 0, 0, 200));
    sfRectangleShape_setSize(background, (sfVector2f){2000, 2000});
    sfRectangleShape_setSize(bg_text, (sfVector2f){2000, 200});
    sfRectangleShape_setPosition(bg_text, (sfVector2f){0, 100});
    sfRenderWindow_drawRectangleShape(window, background, NULL);
    sfRenderWindow_drawRectangleShape(window, bg_text, NULL);
    sfRectangleShape_destroy(background);
    sfRectangleShape_destroy(bg_text);
}

void reset_cinematic(cinematic_t *cinematic)
{
    cinematic->played = 1;
    cinematic->loaded = 0;
    cinematic->movement = (sfVector2f) {15, 0};
}

void handle_cinematic(sfRenderWindow *window, cinematic_t *cinematic,
game_t *game)
{
    if (cinematic->played == 1)
        return;
    load_cinematic(window, cinematic, game);
    draw_cinematic_background(window);
    if (sfClock_getElapsedTime(cinematic->movement_clock).microseconds >
    cinematic->delay && cinematic->movement.x != 0) {
        sfText_move(cinematic->text, cinematic->movement);
        sfSprite_move(cinematic->sprite, cinematic->movement);
        sfClock_restart(cinematic->movement_clock);
    }
    if (sfSprite_getPosition(cinematic->sprite).x >= BASE_WIDTH / 2 && \
        cinematic->movement.x != 0)
        cinematic->movement = (sfVector2f) {0, 0};
    if (sfClock_getElapsedTime(cinematic->movement_clock).microseconds >
        5000000)
        reset_cinematic(cinematic);
    sfRenderWindow_drawSprite(window, cinematic->sprite, NULL);
    sfRenderWindow_drawText(window, cinematic->text, NULL);
}