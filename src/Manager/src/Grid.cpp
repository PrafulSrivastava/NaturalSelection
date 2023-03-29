#include "Grid.hpp"

namespace NaturalSelection::Manager
{
    void Grid::Init(const int32_t &width, const int32_t &height)
    {
        Log(Log::DEBUG, __func__);

        m_rows = height / MIN_HEIGHT;
        m_columns = width / MIN_WIDTH;
        int count = 0;
        for (int i = 0; i < height; i = i + MIN_HEIGHT)
        {
            for (int j = 0; j < width; j = j + MIN_WIDTH)
            {
                m_blocks.emplace_back(Block(Position(j, i), count++));
            }
        }
    }

    Grid::~Grid()
    {
        Log(Log::DEBUG, __func__);

        m_blocks.clear();
        m_entity.clear();
        m_orgs.clear();
    }

    BlockId Grid::findBlock(const Position &point)
    {
        Log(Log::VERBOSE, __func__);

        int xb = (point.x / MIN_WIDTH) + 1;
        int yb = (point.y / MIN_WIDTH) + 1;

        return (xb + (yb - 1) * m_columns) - 1;
    }

    void Grid::Register(std::reference_wrapper<Entity::CognitiveEntity<sf::CircleShape>> org)
    {
        Log(Log::DEBUG, __func__);

        m_orgs.emplace_back(org);

        auto &entity = org.get();
        auto index = findBlock(entity.GetDrawableEntity().getPosition());
        m_blocks[index].visit(entity.GetId());
        m_entity[entity.GetId()] = index;
    }

    void Grid::Update(const EntityId &id)
    {
        Log(Log::DEBUG, __func__, id);

        auto prev_gridIndex = m_entity[id];
        auto index = findBlock(m_orgs[id].get().GetDrawableEntity().getPosition());

        Log(Log::INFO, "organism", id, " is present in grid", index);

        if (index >= 0 && index < m_columns * m_rows)
        {
            if (prev_gridIndex != index)
            {
                m_blocks[prev_gridIndex].leave(id);
                m_blocks[index].visit(id);
                m_entity[id] = index;
            }
        }
    }

    std::vector<EntityId> Grid::Fetch(const EntityId &id)
    {
        Log(Log::VERBOSE, __func__);

        auto index = findBlock(m_orgs[id].get().GetDrawableEntity().getPosition());

        if (index >= 0 && index < m_columns * m_rows)
        {
            return m_blocks[index].getEntities();
        }
        return {};
    }

    void Grid::Reset()
    {
        Log(Log::DEBUG, __func__);
    }
    void Grid::Draw(std::reference_wrapper<sf::RenderWindow> window)
    {
        for (auto it : m_blocks)
        {
            window.get().draw(it);
        }
    }
}