#pragma once

#include <concepts>
#include <cstddef>
#include <functional>
#include <utility>
#include <vector>

namespace Core
{
    template <typename... Args>
    class Action final
    {
        using CallbackType = std::function<void(Args...)>;

    public:
        template <typename F>
            requires std::invocable<F &, Args...>
        void operator+=(F &&fn)
        {
            m_callbacks.emplace_back(std::forward<F>(fn));
        }

        void operator()(Args... args) const
        {
            for (const auto &callback : m_callbacks)
            {
                std::invoke(callback, std::forward<Args>(args)...);
            }
        }

    private:
        std::vector<CallbackType> m_callbacks;
    };
}