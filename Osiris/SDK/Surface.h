#pragma once

#include "Utils.h"

class Surface final {
public:
    constexpr void setDrawColor(int r, int g, int b, int a) noexcept
    {
        callVirtualFunction<void, int, int, int, int>(this, 15, r, g, b, a);
    }

    constexpr void setDrawColor(float color[3], int a) noexcept
    {
        callVirtualFunction<void, int, int, int, int>(this, 15, static_cast<int>(color[0] * 255), static_cast<int>(color[1] * 255), static_cast<int>(color[2] * 255), a);
    }

    constexpr void drawFilledRect(int x0, int y0, int x1, int y1) noexcept
    {
        callVirtualFunction<void, int, int, int, int>(this, 16, x0, y0, x1, y1);
    }

    template <typename T>
    constexpr void drawOutlinedRect(T x0, T y0, T x1, T y1) noexcept
    {
        callVirtualFunction<void, int, int, int, int>(this, 18, static_cast<int>(x0), static_cast<int>(y0), static_cast<int>(x1), static_cast<int>(y1));
    }

    template <typename T>
    constexpr void drawLine(T x0, T y0, T x1, T y1) noexcept
    {
        callVirtualFunction<void, int, int, int, int>(this, 19, static_cast<int>(x0), static_cast<int>(y0), static_cast<int>(x1), static_cast<int>(y1));
    }

    constexpr void setTextFont(unsigned font) noexcept
    {
        callVirtualFunction<void, unsigned>(this, 23, font);
    }

    constexpr void setTextColor(int r, int g, int b, int a) noexcept
    {
        callVirtualFunction<void, int, int, int, int>(this, 25, r, g, b, a);
    }

    constexpr void setTextColor(float color[3], int a) noexcept
    {
        callVirtualFunction<void, int, int, int, int>(this, 25, static_cast<int>(color[0] * 255), static_cast<int>(color[1] * 255), static_cast<int>(color[2] * 255), a);
    }

    template <typename T>
    constexpr void setTextPosition(T x, T y) noexcept
    {
        callVirtualFunction<void, int, int>(this, 26, static_cast<int>(x), static_cast<int>(y));
    }

    constexpr void printText(const std::wstring_view text, int drawType = 0) noexcept
    {
        callVirtualFunction<void, const wchar_t*, int, int>(this, 28, text.data(), text.length(), drawType);
    }

    constexpr auto getScreenSize() noexcept
    {
        int width{ }, height{ };
        callVirtualFunction<void, int&, int&>(this, 44, width, height);
        return std::make_pair(width, height);
    }

    constexpr void unlockCursor() noexcept
    {
        callVirtualFunction<void>(this, 66);
    }

    constexpr unsigned createFont() noexcept
    {
        return callVirtualFunction<unsigned>(this, 71);
    }

    constexpr bool setFontGlyphSet(unsigned font, const char* fontName, int tall, int weight, int blur, int scanlines, int flags, int rangeMin = 0, int rangeMax = 0) noexcept
    {
        return callVirtualFunction<bool, unsigned, const char*, int, int, int, int, int, int, int>(this, 72, font, fontName, tall, weight, blur, scanlines, flags, rangeMin, rangeMax);
    }

    constexpr auto getTextSize(unsigned font, const wchar_t* text) noexcept
    {
        int width{ }, height{ };
        callVirtualFunction<void, unsigned, const wchar_t*, int&, int&>(this, 79, font, text, width, height);
        return std::make_pair(width, height);
    }
};
