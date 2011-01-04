
#include "sector.hpp"

#include <data/manager.hpp>
#include <data/staticsloader.hpp>
#include <data/maploader.hpp>

namespace uome {
namespace world {

Sector::Sector(unsigned int id, unsigned int locX, unsigned int locY) : id_(id), location_(locX, locY), visible_(true) {
    LOGARG_DEBUG(LOGTYPE_WORLD, "Sector construct, x=%u y=%u", location_[0u], location_[1u]);

    mapBlock_ = data::Manager::getMapLoader(0)->get(locX, locY);
    staticBlock_ = data::Manager::getStaticsLoader(0)->get(locX, locY);
}

Sector::~Sector() {
    LOGARG_DEBUG(LOGTYPE_WORLD, "Sector destroy, x=%u y=%u", location_[0u], location_[1u]);
}

}
}