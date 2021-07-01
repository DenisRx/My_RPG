/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** dialog
*/

#include "global.h"

void show_dialog(sfRenderWindow *window, game_t *game)
{
    dialog_t *dialog = game->dialog;
    sfFloatRect rect;
    sfFloatRect sprite_rect;

    if (!dialog->displayed)
        return;
    rect = sfText_getGlobalBounds(dialog->text);
    sprite_rect = sfSprite_getGlobalBounds(dialog->sprite);
    sfText_setOrigin(dialog->text, (sfVector2f){rect.width/2, rect.height/2});
    sfText_setPosition(dialog->text, (sfVector2f) {sprite_rect.left +
        sprite_rect.width / 2, sprite_rect.top + sprite_rect.height / 2});
    if (sfClock_getElapsedTime(dialog->clock).microseconds < dialog->delay ||
    dialog->delay == 0) {
        sfRenderWindow_drawSprite(window, dialog->sprite, NULL);
        sfRenderWindow_drawText(window, dialog->text, NULL);
    } else {
        sfClock_restart(dialog->clock);
        dialog->displayed = 0;
        dialog->sprite = NULL;
        dialog->text = NULL;
    }
}

dialog_t *create_dialog(void)
{
    dialog_t *dialog = malloc(sizeof(dialog_t));

    dialog->sprite = NULL;
    dialog->clock = sfClock_create();
    dialog->text = NULL;
    dialog->delay = 0;
    dialog->displayed = 0;
    dialog->messages = NULL;
    dialog->current = 0;
    return (dialog);
}