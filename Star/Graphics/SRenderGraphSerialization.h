// Copyright (C) 2019-2020 star.engine at outlook dot com
//
// This file is part of StarEngine
//
// StarEngine is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as published
// by the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// StarEngine is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public License
// along with StarEngine.  If not, see <https://www.gnu.org/licenses/>.

#pragma once
#include <Star/Graphics/SRenderGraphTypes.h>
#include <Star/Graphics/SRenderSerialization.h>

namespace boost {

namespace serialization {

STAR_CLASS_IMPLEMENTATION(Star::Graphics::Render::Linear_, object_serializable);
STAR_CLASS_TRACKING(Star::Graphics::Render::Linear_, track_never);
template<class Archive>
void serialize(Archive& ar, Star::Graphics::Render::Linear_& v, const uint32_t version) {
}

STAR_CLASS_IMPLEMENTATION(Star::Graphics::Render::Device_, object_serializable);
STAR_CLASS_TRACKING(Star::Graphics::Render::Device_, track_never);
template<class Archive>
void serialize(Archive& ar, Star::Graphics::Render::Device_& v, const uint32_t version) {
}

STAR_CLASS_IMPLEMENTATION(Star::Graphics::Render::Load_, object_serializable);
STAR_CLASS_TRACKING(Star::Graphics::Render::Load_, track_never);
template<class Archive>
void serialize(Archive& ar, Star::Graphics::Render::Load_& v, const uint32_t version) {
}

STAR_CLASS_IMPLEMENTATION(Star::Graphics::Render::DontRead_, object_serializable);
STAR_CLASS_TRACKING(Star::Graphics::Render::DontRead_, track_never);
template<class Archive>
void serialize(Archive& ar, Star::Graphics::Render::DontRead_& v, const uint32_t version) {
}

STAR_CLASS_IMPLEMENTATION(Star::Graphics::Render::Store_, object_serializable);
STAR_CLASS_TRACKING(Star::Graphics::Render::Store_, track_never);
template<class Archive>
void serialize(Archive& ar, Star::Graphics::Render::Store_& v, const uint32_t version) {
}

STAR_CLASS_IMPLEMENTATION(Star::Graphics::Render::Discard_, object_serializable);
STAR_CLASS_TRACKING(Star::Graphics::Render::Discard_, track_never);
template<class Archive>
void serialize(Archive& ar, Star::Graphics::Render::Discard_& v, const uint32_t version) {
}

STAR_CLASS_IMPLEMENTATION(Star::Graphics::Render::ClearColor, object_serializable);
STAR_CLASS_TRACKING(Star::Graphics::Render::ClearColor, track_never);
template<class Archive>
void serialize(Archive& ar, Star::Graphics::Render::ClearColor& v, const uint32_t version) {
    ar & v.mClearColor;
    ar & v.mClearFormat;
}

STAR_CLASS_IMPLEMENTATION(Star::Graphics::Render::ClearDepthStencil, object_serializable);
STAR_CLASS_TRACKING(Star::Graphics::Render::ClearDepthStencil, track_never);
template<class Archive>
void serialize(Archive& ar, Star::Graphics::Render::ClearDepthStencil& v, const uint32_t version) {
    ar & v.mDepthClearValue;
    ar & v.mStencilClearValue;
    ar & v.mClearDepth;
    ar & v.mClearStencil;
    ar & v.mUnused;
    ar & v.mClearFormat;
}

STAR_CLASS_IMPLEMENTATION(Star::Graphics::Render::FramebufferHandle, object_serializable);
STAR_CLASS_TRACKING(Star::Graphics::Render::FramebufferHandle, track_never);
template<class Archive>
void serialize(Archive& ar, Star::Graphics::Render::FramebufferHandle& v, const uint32_t version) {
    ar & v.mHandle;
}

STAR_CLASS_IMPLEMENTATION(Star::Graphics::Render::DescriptorHandle, object_serializable);
STAR_CLASS_TRACKING(Star::Graphics::Render::DescriptorHandle, track_never);
template<class Archive>
void serialize(Archive& ar, Star::Graphics::Render::DescriptorHandle& v, const uint32_t version) {
    ar & v.mHandle;
}

STAR_CLASS_IMPLEMENTATION(Star::Graphics::Render::Attachment, object_serializable);
STAR_CLASS_TRACKING(Star::Graphics::Render::Attachment, track_never);
template<class Archive>
void serialize(Archive& ar, Star::Graphics::Render::Attachment& v, const uint32_t version) {
    ar & v.mFramebuffer;
    ar & v.mDescriptor;
    ar & v.mStoreOp;
    ar & v.mLoadOp;
}

STAR_CLASS_IMPLEMENTATION(Star::Graphics::Render::RenderViewTransition, object_serializable);
STAR_CLASS_TRACKING(Star::Graphics::Render::RenderViewTransition, track_never);
template<class Archive>
void serialize(Archive& ar, Star::Graphics::Render::RenderViewTransition& v, const uint32_t version) {
    ar & v.mFramebuffer;
    ar & v.mSource;
    ar & v.mTarget;
}

STAR_CLASS_IMPLEMENTATION(Star::Graphics::Render::UnorderedRenderQueue, object_serializable);
STAR_CLASS_TRACKING(Star::Graphics::Render::UnorderedRenderQueue, track_never);
template<class Archive>
void serialize(Archive& ar, Star::Graphics::Render::UnorderedRenderQueue& v, const uint32_t version) {
    ar & v.mContents;
}

template<class Archive>
inline void load_construct_data(
    Archive& ar, std::pair<const std::pmr::string, Star::Graphics::Render::UnorderedRenderQueue>* t, const unsigned int file_version
) {
    ::new(t) std::pair<const std::pmr::string, Star::Graphics::Render::UnorderedRenderQueue>(std::piecewise_construct, std::forward_as_tuple(ar.resource()), std::forward_as_tuple(ar.resource()));
}

template<class Archive, class K>
inline void load_construct_data(
    Archive& ar, std::pair<K, Star::Graphics::Render::UnorderedRenderQueue>* t, const unsigned int file_version
) {
    ::new(t) std::pair<K, Star::Graphics::Render::UnorderedRenderQueue>(std::piecewise_construct, std::forward_as_tuple(), std::forward_as_tuple(ar.resource()));
}

STAR_CLASS_IMPLEMENTATION(Star::Graphics::Render::RenderSubpass, object_serializable);
STAR_CLASS_TRACKING(Star::Graphics::Render::RenderSubpass, track_never);
template<class Archive>
void serialize(Archive& ar, Star::Graphics::Render::RenderSubpass& v, const uint32_t version) {
    ar & v.mSampleDesc;
    ar & v.mInputAttachments;
    ar & v.mOutputAttachments;
    ar & v.mResolveAttachments;
    ar & v.mDepthStencilAttachment;
    ar & v.mPreserveAttachments;
    ar & v.mSRVs;
    ar & v.mUAVs;
    ar & v.mPostViewTransitions;
    ar & v.mOrderedRenderQueue;
    ar & v.mRootSignature;
    ar & v.mConstantBuffer;
}

template<class Archive>
inline void load_construct_data(
    Archive& ar, std::pair<const std::pmr::string, Star::Graphics::Render::RenderSubpass>* t, const unsigned int file_version
) {
    ::new(t) std::pair<const std::pmr::string, Star::Graphics::Render::RenderSubpass>(std::piecewise_construct, std::forward_as_tuple(ar.resource()), std::forward_as_tuple(ar.resource()));
}

template<class Archive, class K>
inline void load_construct_data(
    Archive& ar, std::pair<K, Star::Graphics::Render::RenderSubpass>* t, const unsigned int file_version
) {
    ::new(t) std::pair<K, Star::Graphics::Render::RenderSubpass>(std::piecewise_construct, std::forward_as_tuple(), std::forward_as_tuple(ar.resource()));
}

STAR_CLASS_IMPLEMENTATION(Star::Graphics::Render::RenderSubpassDependency, object_serializable);
STAR_CLASS_TRACKING(Star::Graphics::Render::RenderSubpassDependency, track_never);
template<class Archive>
void serialize(Archive& ar, Star::Graphics::Render::RenderSubpassDependency& v, const uint32_t version) {
    ar & v.mSrcSubpass;
    ar & v.mDstSubpass;
}

STAR_CLASS_IMPLEMENTATION(Star::Graphics::Render::RenderPass, object_serializable);
STAR_CLASS_TRACKING(Star::Graphics::Render::RenderPass, track_never);
template<class Archive>
void serialize(Archive& ar, Star::Graphics::Render::RenderPass& v, const uint32_t version) {
    ar & v.mViewports;
    ar & v.mScissorRects;
    ar & v.mFramebuffers;
    ar & v.mSubpasses;
    ar & v.mDependencies;
}

template<class Archive>
inline void load_construct_data(
    Archive& ar, std::pair<const std::pmr::string, Star::Graphics::Render::RenderPass>* t, const unsigned int file_version
) {
    ::new(t) std::pair<const std::pmr::string, Star::Graphics::Render::RenderPass>(std::piecewise_construct, std::forward_as_tuple(ar.resource()), std::forward_as_tuple(ar.resource()));
}

template<class Archive, class K>
inline void load_construct_data(
    Archive& ar, std::pair<K, Star::Graphics::Render::RenderPass>* t, const unsigned int file_version
) {
    ::new(t) std::pair<K, Star::Graphics::Render::RenderPass>(std::piecewise_construct, std::forward_as_tuple(), std::forward_as_tuple(ar.resource()));
}

STAR_CLASS_IMPLEMENTATION(Star::Graphics::Render::RenderPassDependency, object_serializable);
STAR_CLASS_TRACKING(Star::Graphics::Render::RenderPassDependency, track_never);
template<class Archive>
void serialize(Archive& ar, Star::Graphics::Render::RenderPassDependency& v, const uint32_t version) {
    ar & v.mSrcPass;
    ar & v.mDstPass;
}

STAR_CLASS_IMPLEMENTATION(Star::Graphics::Render::RenderSubpassDesc, object_serializable);
STAR_CLASS_TRACKING(Star::Graphics::Render::RenderSubpassDesc, track_never);
template<class Archive>
void serialize(Archive& ar, Star::Graphics::Render::RenderSubpassDesc& v, const uint32_t version) {
    ar & v.mPassID;
    ar & v.mSubpassID;
}

STAR_CLASS_IMPLEMENTATION(Star::Graphics::Render::RenderPipeline, object_serializable);
STAR_CLASS_TRACKING(Star::Graphics::Render::RenderPipeline, track_never);
template<class Archive>
void serialize(Archive& ar, Star::Graphics::Render::RenderPipeline& v, const uint32_t version) {
    ar & v.mPasses;
    ar & v.mDependencies;
    ar & v.mRTVInitialStates;
    ar & v.mDSVInitialStates;
    ar & v.mConstantBuffer;
    ar & v.mSubpassIndex;
}

template<class Archive>
inline void load_construct_data(
    Archive& ar, std::pair<const std::pmr::string, Star::Graphics::Render::RenderPipeline>* t, const unsigned int file_version
) {
    ::new(t) std::pair<const std::pmr::string, Star::Graphics::Render::RenderPipeline>(std::piecewise_construct, std::forward_as_tuple(ar.resource()), std::forward_as_tuple(ar.resource()));
}

template<class Archive, class K>
inline void load_construct_data(
    Archive& ar, std::pair<K, Star::Graphics::Render::RenderPipeline>* t, const unsigned int file_version
) {
    ::new(t) std::pair<K, Star::Graphics::Render::RenderPipeline>(std::piecewise_construct, std::forward_as_tuple(), std::forward_as_tuple(ar.resource()));
}

STAR_CLASS_IMPLEMENTATION(Star::Graphics::Render::Framebuffer, object_serializable);
STAR_CLASS_TRACKING(Star::Graphics::Render::Framebuffer, track_never);
template<class Archive>
void serialize(Archive& ar, Star::Graphics::Render::Framebuffer& v, const uint32_t version) {
    ar & v.mResource;
    ar & v.mClear;
}

STAR_CLASS_IMPLEMENTATION(Star::Graphics::Render::RenderSolution, object_serializable);
STAR_CLASS_TRACKING(Star::Graphics::Render::RenderSolution, track_never);
template<class Archive>
void serialize(Archive& ar, Star::Graphics::Render::RenderSolution& v, const uint32_t version) {
    ar & v.mPipelines;
    ar & v.mFramebuffers;
    ar & v.mRTVSources;
    ar & v.mDSVSources;
    ar & v.mRTVs;
    ar & v.mDSVs;
    ar & v.mPipelineIndex;
}

template<class Archive>
inline void load_construct_data(
    Archive& ar, std::pair<const std::pmr::string, Star::Graphics::Render::RenderSolution>* t, const unsigned int file_version
) {
    ::new(t) std::pair<const std::pmr::string, Star::Graphics::Render::RenderSolution>(std::piecewise_construct, std::forward_as_tuple(ar.resource()), std::forward_as_tuple(ar.resource()));
}

template<class Archive, class K>
inline void load_construct_data(
    Archive& ar, std::pair<K, Star::Graphics::Render::RenderSolution>* t, const unsigned int file_version
) {
    ::new(t) std::pair<K, Star::Graphics::Render::RenderSolution>(std::piecewise_construct, std::forward_as_tuple(), std::forward_as_tuple(ar.resource()));
}

STAR_CLASS_IMPLEMENTATION(Star::Graphics::Render::SwapChain, object_serializable);
STAR_CLASS_TRACKING(Star::Graphics::Render::SwapChain, track_never);
template<class Archive>
void serialize(Archive& ar, Star::Graphics::Render::SwapChain& v, const uint32_t version) {
    ar & v.mWidth;
    ar & v.mHeight;
}

STAR_CLASS_IMPLEMENTATION(Star::Graphics::Render::RenderSwapChain, object_serializable);
STAR_CLASS_TRACKING(Star::Graphics::Render::RenderSwapChain, track_never);
template<class Archive>
void serialize(Archive& ar, Star::Graphics::Render::RenderSwapChain& v, const uint32_t version) {
    ar & v.mName;
    ar & v.mWidth;
    ar & v.mHeight;
    ar & v.mSolutions;
    ar & v.mNumBackBuffers;
    ar & v.mNumReserveFramebuffers;
    ar & v.mNumReserveSRVs;
    ar & v.mNumReserveUAVs;
    ar & v.mNumReserveDSVs;
    ar & v.mNumReserveRTVs;
    ar & v.mConstantBuffer;
    ar & v.mSolutionIndex;
}

template<class Archive>
inline void load_construct_data(
    Archive& ar, std::pair<const std::pmr::string, Star::Graphics::Render::RenderSwapChain>* t, const unsigned int file_version
) {
    ::new(t) std::pair<const std::pmr::string, Star::Graphics::Render::RenderSwapChain>(std::piecewise_construct, std::forward_as_tuple(ar.resource()), std::forward_as_tuple(ar.resource()));
}

template<class Archive, class K>
inline void load_construct_data(
    Archive& ar, std::pair<K, Star::Graphics::Render::RenderSwapChain>* t, const unsigned int file_version
) {
    ::new(t) std::pair<K, Star::Graphics::Render::RenderSwapChain>(std::piecewise_construct, std::forward_as_tuple(), std::forward_as_tuple(ar.resource()));
}

} // namespace serialization

} // namespace boost