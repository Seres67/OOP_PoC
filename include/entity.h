#ifndef ENTITY_H
#define ENTITY_H

typedef struct entity_t
{
    // private
    char *_name;
    struct
    {
        int x;
        int y;
    } _position;

    // getters
    const char *(*get_name)(const struct entity_t *entity);

    // setters
    void (*set_name)(struct entity_t *entity, const char *name);
} Entity;

const char *entity_get_name(const struct entity_t *entity);
void entity_set_name(struct entity_t *entity, const char *name);

#endif // ENTITY_H
