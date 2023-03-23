#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "IBrain.hpp"
#include "IActionFactory.hpp"

namespace NaturalSelection::Brain
{

    class Brain : public IBrain
    {
    public:
        Brain() = default;
        Brain(const Common::GenomeSequence &);
        ~Brain() override = default;
        void React(const Common::StimuliType &, std::reference_wrapper<sf::Shape>) override;

    private:
        Common::Operations Evaluate();

        Common::Operations m_neurons;
    };
}

#endif