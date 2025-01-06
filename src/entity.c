#include <entity.h>

const char *entity_get_name(const struct entity_t *entity) { return entity->_name; }

void entity_set_name(struct entity_t *entity, const char *name) { entity->_name = name; }
