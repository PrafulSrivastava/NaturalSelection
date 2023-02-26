#include "Brain.hpp"
#include "Utility.hpp"

namespace SmartEvolution::Brain
{
    Brain::Brain(const Common::GenomeSequence &sequence)
    {
        for (size_t i = 0; i < Common::GenomeSequenceLength; i++)
        {
            if (sequence[i] == 1)
            {
                m_inputNeuron.m_nextNeurons.push_back({static_cast<Common::ReactionType>(Common::GenomeSequenceLength - i),
                                                       Common::Utility::getRandomNumberInRange<Common::FResolution>(-10.5, 10.5)});
            }
        }
    }

    Common::ReactionType Brain::getReaction(const Common::StimuliType &stimuli)
    {
        auto maxSize = m_inputNeuron.m_nextNeurons.size();
        return m_inputNeuron.m_nextNeurons[Common::Utility::getRandomNumberInRange<Common::NFResolution>(0, maxSize - 1)].m_reaction;
    }

}