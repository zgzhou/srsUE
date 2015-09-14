/**
 *
 * \section COPYRIGHT
 *
 * Copyright 2015 The srsUE Developers. See the
 * COPYRIGHT file at the top-level directory of this distribution.
 *
 * \section LICENSE
 *
 * This file is part of the srsUE library.
 *
 * srsUE is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * srsUE is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * A copy of the GNU Affero General Public License can be found in
 * the LICENSE file in the top-level directory of this distribution
 * and at http://www.gnu.org/licenses/.
 *
 */

#ifndef NAS_H
#define NAS_H

#include "common/log.h"
#include "common/common.h"
#include "common/interfaces.h"

namespace srsue {

// EMM states (3GPP 24.302 v10.0.0)
typedef enum{
    EMM_STATE_NULL = 0,
    EMM_STATE_DEREGISTERED,
    EMM_STATE_REGISTERED_INITIATED,
    EMM_STATE_REGISTERED,
    EMM_STATE_SERVICE_REQUEST_INITIATED,
    EMM_STATE_DEREGISTERED_INITIATED,
    EMM_STATE_TAU_INITIATED,
    EMM_STATE_N_ITEMS,
}emm_state_t;
static const char emm_state_text[EMM_STATE_N_ITEMS][100] = {"NULL",
                                                            "DEREGISTERED",
                                                            "REGISTERED INITIATED",
                                                            "REGISTERED",
                                                            "SERVICE REQUEST INITIATED",
                                                            "DEREGISTERED INITIATED",
                                                            "TRACKING AREA UPDATE INITIATED"};

class nas
    :public nas_interface_rrc
{
public:
  nas();
  void init(rrc_interface_nas *rrc_, srslte::log *nas_log_);

private:
  srslte::log       *nas_log;
  rrc_interface_nas *rrc;

  emm_state_t        state;
};

} // namespace srsue


#endif // NAS_H
