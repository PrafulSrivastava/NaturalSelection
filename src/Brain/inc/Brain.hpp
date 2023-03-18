#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "IBrain.hpp"

namespace NaturalSelection::Brain
{

    class Brain : public IBrain
    {
    public:
        Brain() = default;
        Brain(const Common::GenomeSequence &);
        ~Brain() override = default;
        void React(const Common::StimuliType &, std::reference_wrapper<sf::CircleShape>) override;

    private:
        Common::Actions Evaluate();

        std::vector<Common::NeuronType> m_neurons;
        // Add ActionFactory
    };

}

#endif