#ifndef IBRAIN_PROXY_HPP
#define IBRAIN_PROXY_HPP

#include "CommonTypes.hpp"

namespace NaturalSelection::Brain
{

    class IBrainProxy
    {
    public:
        virtual ~IBrainProxy() = default;
        virtual void React(const Common::GenomeSequence &, const Common::StimuliType &, std::reference_wrapper<sf::Shape>) = 0;
    };

}

#endif