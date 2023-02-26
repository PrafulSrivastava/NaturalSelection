#ifndef BRAIN_PROXY_HPP
#define BRAIN_PROXY_HPP

#include "CommonTypes.hpp"
#include "IBrainProxy.hpp"
#include "Brain.hpp"

namespace SmartEvolution::Brain
{
    class BrainProxy : public IBrainProxy
    {
    public:
        BrainProxy() = default;
        virtual ~BrainProxy() = default;

        BrainProxy(const BrainProxy &) = delete;
        BrainProxy &operator=(const BrainProxy &) = delete;
        BrainProxy(BrainProxy &&) = default;
        BrainProxy &operator=(BrainProxy &&) = delete;

        Common::ReactionType getReactionToStimuli(const Common::GenomeSequenceId &, const Common::StimuliType &) override;

    private:
        std::unordered_map<Common::GenomeSequenceId, std::shared_ptr<Brain>> m_brains;
    };
}

#endif