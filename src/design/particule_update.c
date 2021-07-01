/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** particule_update
*/

#include "global.h"

void update_particule(particle_settings_t settings, particle_t *info)
{
    info->delay = rand() % 50000;
    info->trace = settings.trace;
    info->angle = settings.angle;
    info->color = settings.color;
    info->speed = settings.speed;
    info->dissolve = settings.dissolve;
    info->dissolve_rate = settings.dissolve_rate;
    info->gravity = settings.gravity;
    info->bouncing = settings.bouncing;
    info->size = settings.size;
    info->origin_rect = settings.origin_rect;
    info->velocity = settings.velocity;
    sfCircleShape_setFillColor(info->shape, info->color);
    sfCircleShape_setOutlineColor(info->shape, info->color);
    sfCircleShape_setRadius(info->shape, info->size / 2);
    sfCircleShape_setPosition(info->shape, (sfVector2f){info->origin_rect.left
        + rand() % (int)info->origin_rect.width, info->origin_rect.top +
        (rand() % (int)info->origin_rect.height)});
}

void update_particule_engine(particle_engine_t *engine,
particle_settings_t settings)
{
    particle_t *data;

    for (node_t *node = engine->particles; node != NULL; node = node->next) {
        data = node->data;
        update_particule(settings, data);
    }
    engine->settings = settings;
}