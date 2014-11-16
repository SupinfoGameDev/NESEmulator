#ifndef TOOLS_NONCOPYABLE_H
#define TOOLS_NONCOPYABLE_H

class NonCopyable
{
public:
    NonCopyable() = default;
    NonCopyable(const NonCopyable&) = delete;
    NonCopyable& operator=(const NonCopyable&) = delete;
};

#endif
