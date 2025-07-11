/*
 * Copyright (c) 2021, David Tuin <davidot@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibJS/Runtime/NativeFunction.h>

namespace JS {

class JS_API AsyncGeneratorFunctionConstructor final : public NativeFunction {
    JS_OBJECT(AsyncGeneratorFunctionConstructor, NativeFunction);
    GC_DECLARE_ALLOCATOR(AsyncGeneratorFunctionConstructor);

public:
    virtual void initialize(Realm&) override;
    virtual ~AsyncGeneratorFunctionConstructor() override = default;

    virtual ThrowCompletionOr<Value> call() override;
    virtual ThrowCompletionOr<GC::Ref<Object>> construct(FunctionObject& new_target) override;

private:
    explicit AsyncGeneratorFunctionConstructor(Realm&);

    virtual bool has_constructor() const override { return true; }
};

}
