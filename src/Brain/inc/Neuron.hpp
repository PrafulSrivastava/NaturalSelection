#ifndef NEURON_HPP
#define NEURON_HPP

#include "CommonTypes.hpp"
#include "Utility.hpp"

namespace SmartEvolution::Brain
{
    struct Neuron;
    struct InputNeuron
    {
        InputNeuron() = default;
        virtual ~InputNeuron() = default;

        std::vector<Neuron> m_nextNeurons{};
    };

    struct Neuron : public InputNeuron
    {
        Neuron(const Common::ReactionType &reaction, const Common::FResolution &weight)
            : m_reaction(reaction),
              m_weight(weight)
        {
            std::cout << __func__ << " Adding " << Common::Utility::translateReaction(reaction) << std::endl;
        }

        ~Neuron() override{};
        Common::ReactionType m_reaction{Common::ReactionType::Invalid};
        Common::FResolution m_weight{0.0f};
    };
}

#endif