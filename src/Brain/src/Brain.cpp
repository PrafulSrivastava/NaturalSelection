#include "Brain.hpp"

namespace NaturalSelection::Brain
{
    Brain::Brain(const Common::GenomeSequence &sequence)
    {
        for (size_t i = 0; i < Common::GenomeSequenceLength; i++)
        {
            if (sequence[i] == '1')
                m_neurons.emplace_back(static_cast<Common::Operation>(i));
        }
    }

    Common::Actions Brain::Evaluate()
    {
        int16_t choice = (not m_neurons.empty()) ? (rand() % m_neurons.size()) : -1;
        if (choice == -1)
        {
            return {};
        }
        return {m_neurons[choice]};
    }

    void Brain::React(const Common::StimuliType &stimuli, std::reference_wrapper<sf::Shape> drawableEntity)
    {
        auto actions = Evaluate();
        Action::IActionFactory<sf::Shape> m_action(drawableEntity);

        for (auto &operation : actions)
        {
            // Perform action
            switch (operation)
            {
            case Common::Operation::MvNorth:
                m_action.execute<Common::Operation::MvNorth>();
                break;

            case Common::Operation::MvSouth:
                m_action.execute<Common::Operation::MvSouth>();
                break;

            case Common::Operation::MvEast:
                m_action.execute<Common::Operation::MvEast>();
                break;

            case Common::Operation::MvWest:
                m_action.execute<Common::Operation::MvWest>();
                break;

            case Common::Operation::MvRandom:
                m_action.execute<Common::Operation::MvRandom>();
                break;
            };
        }
    }
}
