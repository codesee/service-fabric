// ------------------------------------------------------------
// Copyright (c) Microsoft Corporation.  All rights reserved.
// Licensed under the MIT License (MIT). See License.txt in the repo root for license information.
// ------------------------------------------------------------

#pragma once

namespace Management
{
    namespace ClusterManager
    {
        class FabricUpgradeUpdateDescription 
            : public Serialization::FabricSerializable
            , public Common::IFabricJsonSerializable
        {
            DEFAULT_COPY_CONSTRUCTOR(FabricUpgradeUpdateDescription)
        public:

            FabricUpgradeUpdateDescription();
            FabricUpgradeUpdateDescription(FabricUpgradeUpdateDescription &&);

            __declspec(property(get=get_UpgradeType)) ServiceModel::UpgradeType::Enum const & UpgradeType;
            __declspec(property(get=get_UpdateDescription)) std::shared_ptr<ServiceModel::RollingUpgradeUpdateDescription> const & UpdateDescription;
            __declspec(property(get=get_HealthPolicy)) std::shared_ptr<ServiceModel::ClusterHealthPolicy> const & HealthPolicy;
            __declspec(property(get=get_EnableDeltaHealthEvaluation)) std::shared_ptr<bool> const & EnableDeltaHealthEvaluation;
            __declspec(property(get=get_UpgradeHealthPolicy)) std::shared_ptr<ServiceModel::ClusterUpgradeHealthPolicy> const & UpgradeHealthPolicy;
            __declspec(property(get=get_ApplicationHealthPolicies)) ServiceModel::ApplicationHealthPolicyMapSPtr const & ApplicationHealthPolicies;

            ServiceModel::UpgradeType::Enum const & get_UpgradeType() const { return upgradeType_; }
            std::shared_ptr<ServiceModel::RollingUpgradeUpdateDescription> const & get_UpdateDescription() const { return updateDescription_; }
            std::shared_ptr<ServiceModel::ClusterHealthPolicy> const & get_HealthPolicy() const { return healthPolicy_; }
            std::shared_ptr<bool> const & get_EnableDeltaHealthEvaluation() const { return enableDeltaHealthEvaluation_; }
            std::shared_ptr<ServiceModel::ClusterUpgradeHealthPolicy> const & get_UpgradeHealthPolicy() const { return upgradeHealthPolicy_; }
            ServiceModel::ApplicationHealthPolicyMapSPtr const& get_ApplicationHealthPolicies() const { return applicationHealthPolicies_; }

            bool operator == (FabricUpgradeUpdateDescription const & other) const;
            bool operator != (FabricUpgradeUpdateDescription const & other) const;

            void WriteTo(Common::TextWriter & w, Common::FormatOptions const &) const;

            bool HasUpdates() const;

            Common::ErrorCode FromPublicApi(FABRIC_UPGRADE_UPDATE_DESCRIPTION const &);

            BEGIN_JSON_SERIALIZABLE_PROPERTIES()
                SERIALIZABLE_PROPERTY_ENUM(ServiceModel::Constants::UpgradeKind, upgradeType_)
                SERIALIZABLE_PROPERTY_IF(ServiceModel::Constants::UpdateDescription, updateDescription_, upgradeType_ == FABRIC_UPGRADE_KIND_ROLLING)
                SERIALIZABLE_PROPERTY_IF(ServiceModel::Constants::ClusterHealthPolicy, healthPolicy_, upgradeType_ == FABRIC_UPGRADE_KIND_ROLLING)
                SERIALIZABLE_PROPERTY_IF(ServiceModel::Constants::EnableDeltaHealthEvaluation, enableDeltaHealthEvaluation_, upgradeType_ == FABRIC_UPGRADE_KIND_ROLLING)
                SERIALIZABLE_PROPERTY_IF(ServiceModel::Constants::ClusterUpgradeHealthPolicy, upgradeHealthPolicy_, upgradeType_ == FABRIC_UPGRADE_KIND_ROLLING)
                SERIALIZABLE_PROPERTY_IF(ServiceModel::Constants::ApplicationHealthPolicyMap, applicationHealthPolicies_, upgradeType_ == FABRIC_UPGRADE_KIND_ROLLING)
            END_JSON_SERIALIZABLE_PROPERTIES()

            FABRIC_FIELDS_06(
                upgradeType_, 
                updateDescription_,
                healthPolicy_,
                enableDeltaHealthEvaluation_,
                upgradeHealthPolicy_,
                applicationHealthPolicies_);

        private:

            friend class ModifyUpgradeHelper;

            ServiceModel::UpgradeType::Enum upgradeType_;
            std::shared_ptr<ServiceModel::RollingUpgradeUpdateDescription> updateDescription_;
            std::shared_ptr<ServiceModel::ClusterHealthPolicy> healthPolicy_;
            std::shared_ptr<bool> enableDeltaHealthEvaluation_;
            std::shared_ptr<ServiceModel::ClusterUpgradeHealthPolicy> upgradeHealthPolicy_;
            ServiceModel::ApplicationHealthPolicyMapSPtr applicationHealthPolicies_;
        };
    }
}
