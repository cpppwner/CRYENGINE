// Copyright 2001-2018 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once

#include <IParameterConnection.h>
#include <PoolObject.h>
#include <CryAudio/IAudioInterfacesCommonData.h>

namespace CryAudio
{
namespace Impl
{
namespace Fmod
{
class CVca final : public IParameterConnection, public CPoolObject<CVca, stl::PSyncNone>
{
public:

	CVca() = delete;
	CVca(CVca const&) = delete;
	CVca(CVca&&) = delete;
	CVca& operator=(CVca const&) = delete;
	CVca& operator=(CVca&&) = delete;

#if defined(INCLUDE_FMOD_IMPL_PRODUCTION_CODE)
	explicit CVca(
		FMOD::Studio::VCA* const pVca,
		float const multiplier,
		float const shift,
		char const* const szName)
		: m_pVca(pVca)
		, m_multiplier(multiplier)
		, m_shift(shift)
		, m_name(szName)
	{}
#else
	explicit CVca(
		FMOD::Studio::VCA* const pVca,
		float const multiplier,
		float const shift)
		: m_pVca(pVca)
		, m_multiplier(multiplier)
		, m_shift(shift)
	{}
#endif  // INCLUDE_FMOD_IMPL_PRODUCTION_CODE

	virtual ~CVca() override = default;

	// IParameterConnection
	virtual void Set(IObject* const pIObject, float const value) override;
	virtual void SetGlobally(float const value) override;
	// ~IParameterConnection

private:

	FMOD::Studio::VCA* const m_pVca;
	float const              m_multiplier;
	float const              m_shift;

#if defined(INCLUDE_FMOD_IMPL_PRODUCTION_CODE)
	CryFixedStringT<MaxControlNameLength> const m_name;
#endif  // INCLUDE_FMOD_IMPL_PRODUCTION_CODE
};
} // namespace Fmod
} // namespace Impl
} // namespace CryAudio