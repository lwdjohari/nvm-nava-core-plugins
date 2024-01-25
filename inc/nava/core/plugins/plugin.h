#ifndef NAVA_CORE_UTILS_V2_PLUGIN_H
#define NAVA_CORE_UTILS_V2_PLUGIN_H

namespace nava {
namespace core {
namespace plugins {
    class IPlugin{
        public:
        virtual ~IPlugin(){};
    }

    class Plugin:public IPlugin{
        public:
            virtual ~IPlugin() override {}
    }

}
}  // namespace core
}  // namespace nava

#endif  // NAVA_CORE_UTILS_V2_PLUGIN_H
