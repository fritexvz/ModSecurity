/*
 * ModSecurity, http://www.modsecurity.org/
 * Copyright (c) 2015 - 2020 Trustwave Holdings, Inc. (http://www.trustwave.com/)
 *
 * You may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * If any of the files related to licensing are missing or if you have any
 * other questions related to licensing please contact Trustwave Holdings, Inc.
 * directly using the email address security@modsecurity.org.
 *
 */

#include <string>
#include <memory>

#include "modsecurity/rules_set.h"
#include "modsecurity/actions/action.h"
#include "modsecurity/transaction.h"
#include "modsecurity/rule_message.h"

#ifndef SRC_ACTIONS_DISRUPTIVE_DENY_H_
#define SRC_ACTIONS_DISRUPTIVE_DENY_H_

namespace modsecurity {
namespace actions {
namespace disruptive {


class Deny : public Action {
 public:
    explicit Deny(const std::string &action) : Action(action) { }

    bool execute(RuleWithActions *rule, Transaction *transaction,
        RuleMessage &rm) override;
    bool isDisruptive() override { return true; }
};


}  // namespace disruptive
}  // namespace actions
}  // namespace modsecurity

#endif  // SRC_ACTIONS_DISRUPTIVE_DENY_H_
