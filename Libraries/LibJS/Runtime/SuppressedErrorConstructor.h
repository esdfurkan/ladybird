/*
 * Copyright (c) 2022, David Tuin <davidot@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibJS/Runtime/NativeFunction.h>

namespace JS {

class JS_API SuppressedErrorConstructor final : public NativeFunction {
    JS_OBJECT(SuppressedErrorConstructor, NativeFunction);
    GC_DECLARE_ALLOCATOR(SuppressedErrorConstructor);

public:
    virtual void initialize(Realm&) override;
    virtual ~SuppressedErrorConstructor() override = default;

    virtual ThrowCompletionOr<Value> call() override;
    virtual ThrowCompletionOr<GC::Ref<Object>> construct(FunctionObject& new_target) override;

private:
    explicit SuppressedErrorConstructor(Realm&);
    virtual bool has_constructor() const override { return true; }
};

}
