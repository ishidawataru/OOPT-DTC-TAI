/**
 * @file    taimeta.h
 * @brief   This module defines the meta interface for the Transponder
 *          Abstraction Interface (TAI)
 *
 * @copyright Copyright (c) 2021 Nippon Telegraph and Telephone Corporation
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 *
 */

#if !defined (__TAIMETA_H_)
#define __TAIMETA_H_

#include <taitypes.h>
#include <taimetadatatypes.h>

/**
 * @defgroup TAIMETA TAI - Meta specific API definitions
 *
 * @{
 */

/**
 * @brief List metadata of the given oid object
 *
 * @param[in] oid Object id
 * @param[out] count Number of metadata
 * @param[out] list Array of metadata
 *
 * @return #TAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef tai_status_t (*tai_meta_list_metadata_fn)(
        _In_ tai_object_id_t oid,
        _Out_ uint32_t *count,
        _Out_ const tai_attr_metadata_t * const **list);

/**
 * @brief Get metadata of the given oid object
 *
 * @param[in] oid Object Id
 * @param[in] attr_id Attribute Id
 *
 * @return Pointer to object metadata or NULL in case of failure
 */
typedef const tai_attr_metadata_t* (*tai_meta_get_metadata_fn)(
        _In_ tai_object_id_t oid,
        _In_ tai_attr_id_t attr_id);


/**
 * @brief Meta methods table retrieved with tai_api_query()
 */
typedef struct _tai_meta_api_t
{
    tai_meta_list_metadata_fn               list_metadata;
    tai_meta_get_metadata_fn                get_metadata;
//   tai_meta_alloc_attr_value_fn            alloc;
//   tai_meta_free_attr_value_fn             free;
//   tai_meta_deserialize_attr_value_fn      deserialize;
//   tai_meta_serialize_attr_value_fn        serialize;
//   tai_meta_deepcopy_attr_value_fn         deepcopy_attr_value;
//   tai_meta_deepequal_attr_value_fn        deepequal_attr_value;
} tai_meta_api_t;

/**
 * @}
 */


#endif /** __TAIMETA_H_ */
