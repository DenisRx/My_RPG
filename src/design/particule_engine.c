/*
** EPITECH PROJECT, 2021
** $
** File description:
** particule_engine
*/

#include "global.h"

const particle_settings_t settings_list[] = {
    { 45, {175, 195, 204, 170}, 10, 0, 1, 3, 0, 5, {0, -1000, 2500, 1000},
        {-.5, 0}, 0},
    { 45, {109, 193, 255, 150}, 10, 0, 1, 7, 0, 5, {0, -1000, 2500, 1000},
        {-2, 0}, 1},
    { 45, {255, 255, 255, 170}, 10, 0, 10, 10, 0, 5, {0, 0, 1600, 50},
        {0, 0}, 1}
};

node_t *delete_particle(particle_engine_t *engine, particle_t *particle)
{
    node_t *head = engine->particles;
    node_t *node = head;
    node_t *previous;
    node_t *tmp;

    if (node != NULL && node->data == particle) {
        tmp = node->next;
        return tmp;
    }
    while (node != NULL && node->data != particle) {
        previous = node;
        node = node->next;
    }
    if (node == NULL)
        return (NULL);
    previous->next = node->next;
    return (head);
}

particle_t *create_particle(particle_settings_t settings)
{
    particle_t *info = malloc(sizeof(particle_t));

    info->delay_clock = sfClock_create();
    info->shape = sfCircleShape_create();
    info->dissolve_clock = sfClock_create();
    update_particule(settings, info);
    return (info);
}

node_t *create_particle_list(particle_settings_t settings, int count)
{
    node_t *node = NULL;
    node_t *first = NULL;
    node_t *previous = NULL;

    for (int i = 0; i < count; i++) {
        node = malloc(sizeof(node_t));
        node->data = create_particle(settings);
        node->next = NULL;
        if (first == NULL)
            first = node;
        if (previous != NULL)
            previous->next = node;
        previous = node;
    }
    return (first);
}

void fuel_engine(particle_engine_t *engine, int count)
{
    node_t *last = engine->particles;
    node_t *node;

    while (last->next != NULL)
        last = last->next;
    for (int i = 0; i < count; i++) {
        node = malloc(sizeof(node_t));
        node->data = create_particle(engine->settings);
        node->next = NULL;
        last->next = node;
        last = node;
    }
}

particle_engine_t *create_engine(particle_settings_t settings, int count)
{
    particle_engine_t *info = malloc(sizeof(particle_engine_t));

    info->nb_particles = count;
    info->particles = create_particle_list(settings, count);
    info->settings = settings;
    return (info);
}