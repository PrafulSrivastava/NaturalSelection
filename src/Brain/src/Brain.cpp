#include "Brain.hpp"

namespace NaturalSelection::Brain
{
    Brain::Brain(const Common::GenomeSequence &sequence)
    {
        for (size_t i = 0; i < Common::GenomeSequenceLength; i++)
        {
            if (sequence[i] == '1')
                m_neurons.emplace_back(static_cast<Common::NeuronType>(i));
        }
    }

    Common::Actions Brain::Evaluate()
    {
        int16_t choice = (not m_neurons.empty()) ? (rand() % m_neurons.size()) : -1;
        std::cout << __func__ << " Reaction : " << static_cast<int>(m_neurons[choice]) << std::endl;
        return {m_neurons[choice]};
    }

    void Brain::React(const Common::StimuliType &stimuli, std::reference_wrapper<sf::CircleShape> drawableEntity)
    {
        auto actions = Evaluate();

        for (auto &action : actions)
        {
            // Perform action
        }

        // Dummy Action
        drawableEntity.get().move(1, 0); // Replace this with choice of reaction.
    }
}
