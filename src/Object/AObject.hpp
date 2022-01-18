/*
** EPITECH PROJECT, 2024
** IndieStudio
** File description:
** Created by antoine,
*/

#include "Object/IObject.hpp"

#ifndef INDIESTUDIO_AOBJECT_HPP
#define INDIESTUDIO_AOBJECT_HPP

/**
 * @class AObject
 *
 * @brief Abstract class for objects
 */
class AObject: public IObject {
public:
    /**
     * @brief Construct a new AObject object
     *
     * @param pos
     * @param size
     * @param scale
     * @param colors
     */
    AObject(const coords &pos, const std::pair<int, int> &size, float scale, const std::pair<RGB, RGB> &colors);
    /**
     * @brief Construct a new AObject object
     *
     * @param pos
     * @param size
     * @param scale
     */
    AObject(const coords &pos, const std::pair<int, int> &size, float scale);
    /**
     * @brief Destroy the AObject object
     *
     */
    ~AObject() = default;

    /**
     * @brief Get the Type Field object
     *
     * @return const typeField&
     */
    [[nodiscard]] const typeField &getTypeField() const noexcept override;
    /**
     * @brief Get the Position object
     *
     * @return const coords&
     */
    [[nodiscard]] const coords &getPosition() const noexcept final;
    /**
     * @brief Get the Size object
     *
     * @return const std::pair<int, int>&
     */
    [[nodiscard]] const std::pair<int, int> &getSize() const noexcept final;
    /**
     * @brief Get the Colors object
     *
     * @return const std::pair<RGB, RGB>&
     */
    [[nodiscard]] const std::pair<RGB, RGB> &getColors() const noexcept final;
    /**
     * @brief Get the Scale object
     *
     * @return const float&
     */
    [[nodiscard]] const float &getScale() const noexcept final;
    /**
     * @brief
     *
     * @param is3d
     */
    void set3d(bool is3d) noexcept final;
    /**
     * @brief Set the Position object
     *
     * @param position
     */
    void setPosition(const coords &position) noexcept;
    /**
     * @brief Set the Size object
     *
     * @param size
     */
    void setSize(std::pair<int, int> size) noexcept final;
    /**
     * @brief Set the Scale object
     *
     * @param scale
     */
    void setScale(float scale) noexcept final;
    /**
     * @brief Get the Rotation Angle object
     * 
     * @return const float 
     */
    [[nodiscard]] const float getRotationAngle() const noexcept;
    /**
     * @brief Get the Rotation Axis object
     * 
     * @return const coords& 
     */
    [[nodiscard]] const coords &getRotationAxis() const noexcept;
    /**
     * @brief Set the Color object
     * 
     * @param color 
     */
    void setColor(const std::pair<RGB, RGB> &color);

    protected:
    /**
     * @brief position
     * 
     */
    coords _pos;
    /**
     * @brief size
     * 
     */
    std::pair<int, int> _size;
    /**
     * @brief color
     * 
     */
    std::pair<RGB, RGB> _color;
    /**
     * @brief rotation
     * 
     */
    float _rotation;
    /**
     * @brief rotation angle
     * 
     */
    float _rotationAngle;
    /**
     * @brief rotation axis
     * 
     */
    coords _rotationAxis;
    /**
     * @brief typefields
     * 
     */
    typeField _typeField;
    /**
     * @brief scale
     * 
     */
    float _scale;
};

#endif //INDIESTUDIO_AOBJECT_HPP
