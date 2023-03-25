#ifndef QUAD_TREE
#define QUAD_TREE

#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace NaturalSelection::Common;
namespace NaturalSelection::Manager
{

    const sf::Color QuadTreeBorder = sf::Color::Cyan;
    const sf::Color QuadTreeInterior = sf::Color::Black;
    constexpr auto QuadTreeBorderThickness = 5;
    template <typename Unit>
    struct Node
    {
        Node(sf::Vector2f coor, sf::Vector2f size)
        {
            visionBox.setPosition(coor);
            visionBox.setOutlineColor(QuadTreeBorder);
            visionBox.setFillColor(QuadTreeInterior);
            visionBox.setOutlineThickness(QuadTreeBorderThickness);
            visionBox.setSize(size);

            Common::Utility::SetOriginToCenter(visionBox);
        }

        void Flush()
        {
            points.clear();
            childNodes.clear();
        }

        bool isFull()
        {
            return points.size() >= Capacity;
        }

        bool isDivided()
        {
            return childNodes.size() == Quadrants;
        }

        std::vector<Unit> points;
        sf::RectangleShape visionBox;
        std::vector<Node<Unit>> childNodes;
    };

    template <typename Unit>
    class QuadTree
    {

    public:
        static SpaceType FindQuad(const sf::Vector2f &coorRoot, const sf::Vector2f &coorNewNode)
        {
            if (coorRoot.x <= coorNewNode.x)
            {
                if (coorRoot.y <= coorNewNode.y)
                {
                    return SpaceType::SE;
                }
                else
                {
                    return SpaceType::NE;
                }
            }
            else
            {
                if (coorRoot.y <= coorNewNode.y)
                {
                    return SpaceType::SW;
                }
                else
                {
                    return SpaceType::NW;
                }
            }
        }

        static void Divide(Node<Unit> &root)
        {
            auto rect = root.visionBox.getGlobalBounds();
            auto basePos = root.visionBox.getPosition();
            auto origin = root.visionBox.getOrigin();
            auto baseSize = root.visionBox.getSize();

            // NW
            root.childNodes.emplace_back(
                Node<Unit>(
                    sf::Vector2f(basePos.x - rect.width / 4, basePos.y - rect.height / 4),
                    sf::Vector2f(baseSize.x / 2, baseSize.y / 2)));

            // NE
            root.childNodes.emplace_back(
                Node<Unit>(
                    sf::Vector2f(basePos.x + rect.width / 4, basePos.y - rect.height / 4),
                    sf::Vector2f(baseSize.x / 2, baseSize.y / 2)));

            // SW
            root.childNodes.emplace_back(
                Node<Unit>(
                    sf::Vector2f(basePos.x - rect.width / 4, basePos.y + rect.height / 4),
                    sf::Vector2f(baseSize.x / 2, baseSize.y / 2)));

            // SE
            root.childNodes.emplace_back(
                Node<Unit>(
                    sf::Vector2f(basePos.x + rect.width / 4, basePos.y + rect.height / 4),
                    sf::Vector2f(baseSize.x / 2, baseSize.y / 2)));
        }

        static void Insert(Node<Unit> &root, sf::Vector2f point, Unit val)
        {
            if (!root.visionBox.getGlobalBounds().contains(point))
            {
                return;
            }

            if (!root.isFull())
            {
                root.points.push_back(val);
            }
            else
            {
                if (!root.isDivided())
                {
                    Divide(root);
                }

                auto quad = FindQuad(root.visionBox.getPosition(), point);
                Insert(root.childNodes[static_cast<int>(quad)], point, val);
            }
        }

        static void Draw(Node<Unit> &root, std::reference_wrapper<sf::RenderWindow> window)
        {
            std::stack<std::reference_wrapper<Node<Unit>>> st;
            st.push(std::ref(root));

            while (!st.empty())
            {
                auto top = st.top();
                st.pop();
                window.get().draw(top.get().visionBox);
                for (int i = 0; i < top.get().childNodes.size(); i++)
                {
                    st.push(std::ref(top.get().childNodes[i]));
                }
            }
        }

        static void FindPoint(Node<Unit> &root, sf::Vector2f point)
        {
            std::stack<std::reference_wrapper<Node<Unit>>> st;
            st.push(std::ref(root));
            sf::Vector2f last;
            while (!st.empty())
            {
                auto top = st.top();
                st.pop();

                if (top.get().visionBox.getGlobalBounds().contains(point))
                {
                    last = top.get().visionBox.getPosition();

                    if (top.get().childNodes.size() == 0)
                    {
                        for (auto &point : top.get().points)
                        {
                            point.get().GetDrawableEntity().setFillColor(sf::Color::Red);
                        }
                    }

                    for (int i = 0; i < top.get().childNodes.size(); i++)
                    {
                        st.push(std::ref(top.get().childNodes[i]));
                    }
                }
            }
        }

        static void Display(Node<Unit> &root)
        {
            std::stack<std::reference_wrapper<Node<Unit>>> st;
            st.push(std::ref(root));

            while (!st.empty())
            {
                auto top = st.top();
                Log(Log::INFO, "Rectangle at : ", top.get().visionBox.getPosition().x, " , ", top.get().visionBox.getPosition().y);
                for (auto &point : top.get().points)
                {
                    Log(Log::INFO, "Found Entity : ", point.get().GetId(), " at : ", point.get().GetDrawableEntity().getPosition().x, " , ", point.get().GetDrawableEntity().getPosition().y);
                }
                st.pop();

                for (int i = 0; i < top.get().childNodes.size(); i++)
                {
                    st.push(std::ref(top.get().childNodes[i]));
                }
            }
        }

        // static void CheckAgainstAll(Node<Unit> &root)
        // {
        //     std::stack<std::reference_wrapper<Node<Unit>>> st;
        //     st.push(std::ref(root));

        //     std::vector<std::reference_wrapper<Node<Unit>>> temp;
        //     while (!st.empty())
        //     {
        //         auto top = st.top();
        //         for (auto point : top.get().points)
        //         {
        //             temp.push_back(point);
        //         }
        //         st.pop();

        //         if ()

        //             for (int i = 0; i < top.get().childNodes.size(); i++)
        //             {
        //                 st.push(std::ref(top.get().childNodes[i]));
        //             }
        //     }
        // }
    };

}

#endif