#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "CommonTypes.hpp"
#include "Neuron.hpp"

namespace SmartEvolution::Brain
{
    class Brain
    {
    private:
        InputNeuron m_inputNeuron;

    public:
        Brain(const Common::GenomeSequence &);
        ~Brain() = default;

        Brain(const Brain &) = delete;
        Brain &operator=(const Brain &) = delete;
        Brain(Brain &&) = default;
        Brain &operator=(Brain &&) = delete;
        Common::ReactionType getReaction(const Common::StimuliType &);
    };
}

#endif