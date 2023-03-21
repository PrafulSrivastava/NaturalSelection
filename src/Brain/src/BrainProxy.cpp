#include "BrainProxy.hpp"

namespace NaturalSelection::Brain
{
    void BrainProxy::AddBrain(const Common::GenomeSequence &sequence)
    {
        if (m_brains.end() == m_brains.find(sequence))
        {
            m_brains.emplace(sequence, std::move(Brain(sequence)));
        }
    }

    void BrainProxy::React(const Common::GenomeSequence &sequence, const Common::StimuliType &stimuli, std::reference_wrapper<sf::Shape> drawableEntity)
    {
        // Add brain if not added already
        AddBrain(sequence);
        // Forward Call to right Brain
        m_brains[sequence].React(stimuli, std::ref(drawableEntity));
    }

}
