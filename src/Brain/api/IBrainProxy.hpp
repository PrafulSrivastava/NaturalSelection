#ifndef IBRAIN_PROXY_HPP
#define IBRAIN_PROXY_HPP

#include "CommonTypes.hpp"

namespace SmartEvolution::Brain
{
    class IBrainProxy
    {
    public:
        IBrainProxy() = default;
        virtual ~IBrainProxy() = default;

        virtual Common::ReactionType getReactionToStimuli(const Common::GenomeSequenceId &, const Common::StimuliType &) = 0;
    };
}

#endif