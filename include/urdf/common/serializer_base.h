#ifndef INCLUDE_URDF_COMMON_SERIALIZER_BASE_H_
#define INCLUDE_URDF_COMMON_SERIALIZER_BASE_H_

// Copyright 2024-2026 Wissem CHIHA

#include <memory>

template <class T, typename P>
class SerializerBase
{
public:
    virtual int serialize(const T* object) = 0;
    virtual std::shared_ptr<P> get() { return Pptr; }
protected:
    SerializerBase() {};
    virtual ~SerializerBase(){};
    std::shared_ptr<P> Pptr;
};

#endif // INCLUDE_URDF_COMMON_SERIALIZER_BASE_H_