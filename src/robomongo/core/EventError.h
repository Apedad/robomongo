#pragma once
#include <QString>

namespace Robomongo
{
    /**
     * @brief Error object is a part of every Event in Robomongo. Before the
     * use of any event you should check whether error is detected by
     * calling Event::isError() method.
     */
    class EventError
    {
    public:
        /**
         * @brief Creates "null" (or, in other words, empty) error.
         * Subsequent call of isNull() on this object will return true.
         */
        EventError(){}

        /**
         * @brief Creates error object with specified error message.
         * Subsequent call of isNull() on this object will return false.
         */
        EventError(const QString &errorMessage) :
            _errorMessage(errorMessage) {}

        /**
         * @brief Tests whether error is "null" (or, in other words, empty).
         * Because Error object should be created on stack, this is the only
         * way to support "null" semantic for value objects.
         * @return true, if null or false otherwise.
         */
        bool isNull() const { return _errorMessage.isEmpty(); }

        /**
         * @brief Returns error message that describes this error.
         */
        QString errorMessage() const { return _errorMessage; }

    private:
        /**
         * @brief Error message
         */
        QString _errorMessage;
    };
}
