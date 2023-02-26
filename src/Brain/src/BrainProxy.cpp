#include "BrainProxy.hpp"

namespace SmartEvolution::Brain
{
    Common::ReactionType BrainProxy::getReactionToStimuli(const Common::GenomeSequenceId &id, const Common::StimuliType &stimuli)
    {
        Common::GenomeSequence sequence(id);
        if (m_brains[id] == nullptr)
        {
            m_brains[id] = std::make_shared<Brain>(sequence);
        }

        return m_brains[id]->getReaction(stimuli);
    }

}