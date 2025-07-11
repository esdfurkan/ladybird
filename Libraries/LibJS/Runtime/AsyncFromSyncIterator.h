/*
 * Copyright (c) 2021, David Tuin <davidot@serenityos.org>
 * Copyright (c) 2022, Linus Groh <linusg@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibJS/Runtime/Iterator.h>
#include <LibJS/Runtime/Object.h>

namespace JS {

// 27.1.4.3 Properties of Async-from-Sync Iterator Instances, https://tc39.es/ecma262/#sec-properties-of-async-from-sync-iterator-instances
class JS_API AsyncFromSyncIterator final : public Object {
    JS_OBJECT(AsyncFromSyncIterator, Object);
    GC_DECLARE_ALLOCATOR(AsyncFromSyncIterator);

public:
    static GC::Ref<AsyncFromSyncIterator> create(Realm&, GC::Ref<IteratorRecord> sync_iterator_record);

    virtual ~AsyncFromSyncIterator() override = default;

    void visit_edges(Visitor& visitor) override;

    IteratorRecord& sync_iterator_record() { return m_sync_iterator_record; }
    IteratorRecord const& sync_iterator_record() const { return m_sync_iterator_record; }

private:
    AsyncFromSyncIterator(Realm&, GC::Ref<IteratorRecord> sync_iterator_record);

    GC::Ref<IteratorRecord> m_sync_iterator_record; // [[SyncIteratorRecord]]
};

}
