#include "MoodleAPICalls.h"
#include "JsonUtilities/Public/JsonUtilities.h"

FString UMoodleAPIHelpers::GetValueFromJsonString(const FString& JsonString, const FString& Key)
{
	FString Value;
	TSharedPtr<FJsonObject> JsonObject;
	TSharedPtr<FJsonValue> JsonValue;

	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(JsonString);
	if (FJsonSerializer::Deserialize(JsonReader, JsonValue) && JsonValue.IsValid())
	{
		if (JsonValue->Type == EJson::Object)
		{
			JsonObject = JsonValue->AsObject();
		}
		else if (JsonValue->Type == EJson::Array)
		{
			const TArray<TSharedPtr<FJsonValue>>& JsonArray = JsonValue->AsArray();
			if (JsonArray.Num() > 0 && JsonArray[0]->Type == EJson::Object)
			{
				JsonObject = JsonArray[0]->AsObject();
			}
		}

		if (JsonObject.IsValid())
		{
			if (JsonObject->TryGetStringField(Key, Value))
			{
				return Value;
			}
		}
	}

	return FString();
}

// --- Moodle API Calls --- //

Uquery_token_from_user* Uquery_token_from_user::query_token_from_user(
			const FString ServerURL,
			const FString _username,
			const FString _password)
{
	Uquery_token_from_user* Node = NewObject<Uquery_token_from_user>();

	FString url = "https://" + ServerURL + "/login/token.php?service=cieh_cap160_es&username=" + _username + "&password=" + _password;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Uquery_token_from_user::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Uquery_token_from_user::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Uquery_token_from_user::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Uauth_email_get_signup_settings* Uauth_email_get_signup_settings::auth_email_get_signup_settings(
			const FString ServerURL,
			const FString Token)
{
	Uauth_email_get_signup_settings* Node = NewObject<Uauth_email_get_signup_settings>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=auth_email_get_signup_settings";

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Uauth_email_get_signup_settings::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Uauth_email_get_signup_settings::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Uauth_email_get_signup_settings::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Uauth_email_signup_user* Uauth_email_signup_user::auth_email_signup_user(
			const FString ServerURL,
			const FString Token,
			const FString _username,
			const FString _password,
			const FString _firstname,
			const FString _lastname,
			const FString _email,
			const FString _customprofilefieldstype,
			const FString _customprofilefieldsname,
			const FString _customprofilefieldsvalue,
			const FString _city,
			const FString _country,
			const FString _recaptchachallengehash,
			const FString _recaptcharesponse,
			const FString _redirect)
{
	Uauth_email_signup_user* Node = NewObject<Uauth_email_signup_user>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=auth_email_signup_user&username=" + _username + "&password=" + _password + "&firstname=" + _firstname + "&lastname=" + _lastname + "&email=" + _email + "&city=" + _city + "&country=" + _country + "&recaptchachallengehash=" + _recaptchachallengehash + "&recaptcharesponse=" + _recaptcharesponse + "&customprofilefields[0][type]=" + _customprofilefieldstype + "&customprofilefields[0][name]=" + _customprofilefieldsname + "&customprofilefields[0][value]=" + _customprofilefieldsvalue + "&redirect=" + _redirect;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Uauth_email_signup_user::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Uauth_email_signup_user::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Uauth_email_signup_user::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ublock_accessreview_get_module_data* Ublock_accessreview_get_module_data::block_accessreview_get_module_data(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid)
{
	Ublock_accessreview_get_module_data* Node = NewObject<Ublock_accessreview_get_module_data>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=block_accessreview_get_module_data&courseid=" + FString::FromInt(_courseid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ublock_accessreview_get_module_data::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ublock_accessreview_get_module_data::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ublock_accessreview_get_module_data::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ublock_accessreview_get_section_data* Ublock_accessreview_get_section_data::block_accessreview_get_section_data(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid)
{
	Ublock_accessreview_get_section_data* Node = NewObject<Ublock_accessreview_get_section_data>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=block_accessreview_get_section_data&courseid=" + FString::FromInt(_courseid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ublock_accessreview_get_section_data::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ublock_accessreview_get_section_data::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ublock_accessreview_get_section_data::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ublock_recentlyaccesseditems_get_recent_items* Ublock_recentlyaccesseditems_get_recent_items::block_recentlyaccesseditems_get_recent_items(
			const FString ServerURL,
			const FString Token,
			const int32 _limit)
{
	Ublock_recentlyaccesseditems_get_recent_items* Node = NewObject<Ublock_recentlyaccesseditems_get_recent_items>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=block_recentlyaccesseditems_get_recent_items&limit=" + FString::FromInt(_limit);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ublock_recentlyaccesseditems_get_recent_items::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ublock_recentlyaccesseditems_get_recent_items::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ublock_recentlyaccesseditems_get_recent_items::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ublock_starredcourses_get_starred_courses* Ublock_starredcourses_get_starred_courses::block_starredcourses_get_starred_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _limit,
			const int32 _offset)
{
	Ublock_starredcourses_get_starred_courses* Node = NewObject<Ublock_starredcourses_get_starred_courses>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=block_starredcourses_get_starred_courses&limit=" + FString::FromInt(_limit) + "&offset=" + FString::FromInt(_offset);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ublock_starredcourses_get_starred_courses::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ublock_starredcourses_get_starred_courses::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ublock_starredcourses_get_starred_courses::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_auth_confirm_user* Ucore_auth_confirm_user::core_auth_confirm_user(
			const FString ServerURL,
			const FString Token,
			const FString _username,
			const FString _secret)
{
	Ucore_auth_confirm_user* Node = NewObject<Ucore_auth_confirm_user>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_auth_confirm_user&username=" + _username + "&secret=" + _secret;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_auth_confirm_user::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_auth_confirm_user::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_auth_confirm_user::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_auth_is_age_digital_consent_verification_enabled* Ucore_auth_is_age_digital_consent_verification_enabled::core_auth_is_age_digital_consent_verification_enabled(
			const FString ServerURL,
			const FString Token)
{
	Ucore_auth_is_age_digital_consent_verification_enabled* Node = NewObject<Ucore_auth_is_age_digital_consent_verification_enabled>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_auth_is_age_digital_consent_verification_enabled";

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_auth_is_age_digital_consent_verification_enabled::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_auth_is_age_digital_consent_verification_enabled::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_auth_is_age_digital_consent_verification_enabled::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_auth_is_minor* Ucore_auth_is_minor::core_auth_is_minor(
			const FString ServerURL,
			const FString Token,
			const int32 _age,
			const FString _country)
{
	Ucore_auth_is_minor* Node = NewObject<Ucore_auth_is_minor>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_auth_is_minor&age=" + FString::FromInt(_age) + "&country=" + _country;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_auth_is_minor::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_auth_is_minor::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_auth_is_minor::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_auth_request_password_reset* Ucore_auth_request_password_reset::core_auth_request_password_reset(
			const FString ServerURL,
			const FString Token,
			const FString _username,
			const FString _email)
{
	Ucore_auth_request_password_reset* Node = NewObject<Ucore_auth_request_password_reset>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_auth_request_password_reset&username=" + _username + "&email=" + _email;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_auth_request_password_reset::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_auth_request_password_reset::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_auth_request_password_reset::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_auth_resend_confirmation_email* Ucore_auth_resend_confirmation_email::core_auth_resend_confirmation_email(
			const FString ServerURL,
			const FString Token,
			const FString _username,
			const FString _password,
			const FString _redirect)
{
	Ucore_auth_resend_confirmation_email* Node = NewObject<Ucore_auth_resend_confirmation_email>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_auth_resend_confirmation_email&username=" + _username + "&password=" + _password + "&redirect=" + _redirect;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_auth_resend_confirmation_email::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_auth_resend_confirmation_email::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_auth_resend_confirmation_email::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_backup_get_async_backup_links_backup* Ucore_backup_get_async_backup_links_backup::core_backup_get_async_backup_links_backup(
			const FString ServerURL,
			const FString Token,
			const FString _filename,
			const int32 _contextid)
{
	Ucore_backup_get_async_backup_links_backup* Node = NewObject<Ucore_backup_get_async_backup_links_backup>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_backup_get_async_backup_links_backup&filename=" + _filename + "&contextid=" + FString::FromInt(_contextid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_backup_get_async_backup_links_backup::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_backup_get_async_backup_links_backup::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_backup_get_async_backup_links_backup::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_backup_get_async_backup_links_restore* Ucore_backup_get_async_backup_links_restore::core_backup_get_async_backup_links_restore(
			const FString ServerURL,
			const FString Token,
			const FString _backupid,
			const int32 _contextid)
{
	Ucore_backup_get_async_backup_links_restore* Node = NewObject<Ucore_backup_get_async_backup_links_restore>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_backup_get_async_backup_links_restore&backupid=" + _backupid + "&contextid=" + FString::FromInt(_contextid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_backup_get_async_backup_links_restore::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_backup_get_async_backup_links_restore::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_backup_get_async_backup_links_restore::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_backup_get_async_backup_progress* Ucore_backup_get_async_backup_progress::core_backup_get_async_backup_progress(
			const FString ServerURL,
			const FString Token,
			const FString _backupids,
			const int32 _contextid)
{
	Ucore_backup_get_async_backup_progress* Node = NewObject<Ucore_backup_get_async_backup_progress>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_backup_get_async_backup_progress&backupids[0]=" + _backupids + "&contextid=" + FString::FromInt(_contextid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_backup_get_async_backup_progress::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_backup_get_async_backup_progress::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_backup_get_async_backup_progress::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_backup_get_copy_progress* Ucore_backup_get_copy_progress::core_backup_get_copy_progress(
			const FString ServerURL,
			const FString Token,
			const FString _copiesbackupid,
			const FString _copiesrestoreid,
			const FString _copiesoperation)
{
	Ucore_backup_get_copy_progress* Node = NewObject<Ucore_backup_get_copy_progress>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_backup_get_copy_progress&copies[0][backupid]=" + _copiesbackupid + "&copies[0][restoreid]=" + _copiesrestoreid + "&copies[0][operation]=" + _copiesoperation;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_backup_get_copy_progress::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_backup_get_copy_progress::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_backup_get_copy_progress::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_backup_submit_copy_form* Ucore_backup_submit_copy_form::core_backup_submit_copy_form(
			const FString ServerURL,
			const FString Token,
			const FString _jsonformdata)
{
	Ucore_backup_submit_copy_form* Node = NewObject<Ucore_backup_submit_copy_form>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_backup_submit_copy_form&jsonformdata=" + _jsonformdata;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_backup_submit_copy_form::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_backup_submit_copy_form::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_backup_submit_copy_form::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_badges_get_user_badges* Ucore_badges_get_user_badges::core_badges_get_user_badges(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _courseid,
			const int32 _page,
			const int32 _perpage,
			const FString _search,
			const int32 _onlypublic)
{
	Ucore_badges_get_user_badges* Node = NewObject<Ucore_badges_get_user_badges>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_badges_get_user_badges&userid=" + FString::FromInt(_userid) + "&courseid=" + FString::FromInt(_courseid) + "&page=" + FString::FromInt(_page) + "&perpage=" + FString::FromInt(_perpage) + "&search=" + _search + "&onlypublic=" + FString::FromInt(_onlypublic);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_badges_get_user_badges::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_badges_get_user_badges::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_badges_get_user_badges::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_block_fetch_addable_blocks* Ucore_block_fetch_addable_blocks::core_block_fetch_addable_blocks(
			const FString ServerURL,
			const FString Token,
			const int32 _pagecontextid,
			const FString _pagetype,
			const FString _pagelayout,
			const FString _subpage)
{
	Ucore_block_fetch_addable_blocks* Node = NewObject<Ucore_block_fetch_addable_blocks>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_block_fetch_addable_blocks&pagecontextid=" + FString::FromInt(_pagecontextid) + "&pagetype=" + _pagetype + "&pagelayout=" + _pagelayout + "&subpage=" + _subpage;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_block_fetch_addable_blocks::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_block_fetch_addable_blocks::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_block_fetch_addable_blocks::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_block_get_course_blocks* Ucore_block_get_course_blocks::core_block_get_course_blocks(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _returncontents)
{
	Ucore_block_get_course_blocks* Node = NewObject<Ucore_block_get_course_blocks>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_block_get_course_blocks&courseid=" + FString::FromInt(_courseid) + "&returncontents=" + FString::FromInt(_returncontents);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_block_get_course_blocks::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_block_get_course_blocks::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_block_get_course_blocks::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_block_get_dashboard_blocks* Ucore_block_get_dashboard_blocks::core_block_get_dashboard_blocks(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _returncontents,
			const FString _mypage)
{
	Ucore_block_get_dashboard_blocks* Node = NewObject<Ucore_block_get_dashboard_blocks>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_block_get_dashboard_blocks&userid=" + FString::FromInt(_userid) + "&returncontents=" + FString::FromInt(_returncontents) + "&mypage=" + _mypage;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_block_get_dashboard_blocks::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_block_get_dashboard_blocks::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_block_get_dashboard_blocks::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_blog_get_entries* Ucore_blog_get_entries::core_blog_get_entries(
			const FString ServerURL,
			const FString Token,
			const FString _filtersname,
			const FString _filtersvalue,
			const int32 _page,
			const int32 _perpage)
{
	Ucore_blog_get_entries* Node = NewObject<Ucore_blog_get_entries>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_blog_get_entries&filters[0][name]=" + _filtersname + "&filters[0][value]=" + _filtersvalue + "&page=" + FString::FromInt(_page) + "&perpage=" + FString::FromInt(_perpage);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_blog_get_entries::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_blog_get_entries::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_blog_get_entries::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_blog_view_entries* Ucore_blog_view_entries::core_blog_view_entries(
			const FString ServerURL,
			const FString Token,
			const FString _filtersname,
			const FString _filtersvalue)
{
	Ucore_blog_view_entries* Node = NewObject<Ucore_blog_view_entries>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_blog_view_entries&filters[0][name]=" + _filtersname + "&filters[0][value]=" + _filtersvalue;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_blog_view_entries::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_blog_view_entries::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_blog_view_entries::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_calendar_create_calendar_events* Ucore_calendar_create_calendar_events::core_calendar_create_calendar_events(
			const FString ServerURL,
			const FString Token,
			const FString _eventsname,
			const FString _eventsdescription,
			const int32 _eventsformat,
			const int32 _eventscourseid,
			const int32 _eventsgroupid,
			const int32 _eventsrepeats,
			const FString _eventseventtype,
			const int32 _eventstimestart,
			const int32 _eventstimeduration,
			const int32 _eventsvisible,
			const int32 _eventssequence)
{
	Ucore_calendar_create_calendar_events* Node = NewObject<Ucore_calendar_create_calendar_events>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_calendar_create_calendar_events&events[0][name]=" + _eventsname + "&events[0][description]=" + _eventsdescription + "&events[0][format]=" + FString::FromInt(_eventsformat) + "&events[0][courseid]=" + FString::FromInt(_eventscourseid) + "&events[0][groupid]=" + FString::FromInt(_eventsgroupid) + "&events[0][repeats]=" + FString::FromInt(_eventsrepeats) + "&events[0][eventtype]=" + _eventseventtype + "&events[0][timestart]=" + FString::FromInt(_eventstimestart) + "&events[0][timeduration]=" + FString::FromInt(_eventstimeduration) + "&events[0][visible]=" + FString::FromInt(_eventsvisible) + "&events[0][sequence]=" + FString::FromInt(_eventssequence);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_calendar_create_calendar_events::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_calendar_create_calendar_events::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_calendar_create_calendar_events::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_calendar_delete_calendar_events* Ucore_calendar_delete_calendar_events::core_calendar_delete_calendar_events(
			const FString ServerURL,
			const FString Token,
			const int32 _eventseventid,
			const int32 _eventsrepeat)
{
	Ucore_calendar_delete_calendar_events* Node = NewObject<Ucore_calendar_delete_calendar_events>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_calendar_delete_calendar_events&events[0][eventid]=" + FString::FromInt(_eventseventid) + "&events[0][repeat]=" + FString::FromInt(_eventsrepeat);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_calendar_delete_calendar_events::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_calendar_delete_calendar_events::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_calendar_delete_calendar_events::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_calendar_delete_subscription* Ucore_calendar_delete_subscription::core_calendar_delete_subscription(
			const FString ServerURL,
			const FString Token,
			const int32 _subscriptionid)
{
	Ucore_calendar_delete_subscription* Node = NewObject<Ucore_calendar_delete_subscription>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_calendar_delete_subscription&subscriptionid=" + FString::FromInt(_subscriptionid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_calendar_delete_subscription::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_calendar_delete_subscription::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_calendar_delete_subscription::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_calendar_get_action_events_by_course* Ucore_calendar_get_action_events_by_course::core_calendar_get_action_events_by_course(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _timesortfrom,
			const int32 _timesortto,
			const int32 _aftereventid,
			const int32 _limitnum,
			const FString _searchvalue)
{
	Ucore_calendar_get_action_events_by_course* Node = NewObject<Ucore_calendar_get_action_events_by_course>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_calendar_get_action_events_by_course&courseid=" + FString::FromInt(_courseid) + "&timesortfrom=" + FString::FromInt(_timesortfrom) + "&timesortto=" + FString::FromInt(_timesortto) + "&aftereventid=" + FString::FromInt(_aftereventid) + "&limitnum=" + FString::FromInt(_limitnum) + "&searchvalue=" + _searchvalue;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_calendar_get_action_events_by_course::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_calendar_get_action_events_by_course::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_calendar_get_action_events_by_course::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_calendar_get_action_events_by_courses* Ucore_calendar_get_action_events_by_courses::core_calendar_get_action_events_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids,
			const int32 _timesortfrom,
			const int32 _timesortto,
			const int32 _limitnum,
			const FString _searchvalue)
{
	Ucore_calendar_get_action_events_by_courses* Node = NewObject<Ucore_calendar_get_action_events_by_courses>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_calendar_get_action_events_by_courses&courseids[0]=" + FString::FromInt(_courseids) + "&timesortfrom=" + FString::FromInt(_timesortfrom) + "&timesortto=" + FString::FromInt(_timesortto) + "&limitnum=" + FString::FromInt(_limitnum) + "&searchvalue=" + _searchvalue;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_calendar_get_action_events_by_courses::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_calendar_get_action_events_by_courses::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_calendar_get_action_events_by_courses::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_calendar_get_action_events_by_timesort* Ucore_calendar_get_action_events_by_timesort::core_calendar_get_action_events_by_timesort(
			const FString ServerURL,
			const FString Token,
			const int32 _timesortfrom,
			const int32 _timesortto,
			const int32 _aftereventid,
			const int32 _limitnum,
			const int32 _limittononsuspendedevents,
			const int32 _userid,
			const FString _searchvalue)
{
	Ucore_calendar_get_action_events_by_timesort* Node = NewObject<Ucore_calendar_get_action_events_by_timesort>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_calendar_get_action_events_by_timesort&timesortfrom=" + FString::FromInt(_timesortfrom) + "&timesortto=" + FString::FromInt(_timesortto) + "&aftereventid=" + FString::FromInt(_aftereventid) + "&limitnum=" + FString::FromInt(_limitnum) + "&limittononsuspendedevents=" + FString::FromInt(_limittononsuspendedevents) + "&userid=" + FString::FromInt(_userid) + "&searchvalue=" + _searchvalue;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_calendar_get_action_events_by_timesort::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_calendar_get_action_events_by_timesort::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_calendar_get_action_events_by_timesort::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_calendar_get_allowed_event_types* Ucore_calendar_get_allowed_event_types::core_calendar_get_allowed_event_types(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid)
{
	Ucore_calendar_get_allowed_event_types* Node = NewObject<Ucore_calendar_get_allowed_event_types>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_calendar_get_allowed_event_types&courseid=" + FString::FromInt(_courseid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_calendar_get_allowed_event_types::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_calendar_get_allowed_event_types::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_calendar_get_allowed_event_types::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_calendar_get_calendar_access_information* Ucore_calendar_get_calendar_access_information::core_calendar_get_calendar_access_information(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid)
{
	Ucore_calendar_get_calendar_access_information* Node = NewObject<Ucore_calendar_get_calendar_access_information>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_calendar_get_calendar_access_information&courseid=" + FString::FromInt(_courseid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_calendar_get_calendar_access_information::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_calendar_get_calendar_access_information::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_calendar_get_calendar_access_information::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_calendar_get_calendar_day_view* Ucore_calendar_get_calendar_day_view::core_calendar_get_calendar_day_view(
			const FString ServerURL,
			const FString Token,
			const int32 _year,
			const int32 _month,
			const int32 _day,
			const int32 _courseid,
			const int32 _categoryid)
{
	Ucore_calendar_get_calendar_day_view* Node = NewObject<Ucore_calendar_get_calendar_day_view>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_calendar_get_calendar_day_view&year=" + FString::FromInt(_year) + "&month=" + FString::FromInt(_month) + "&day=" + FString::FromInt(_day) + "&courseid=" + FString::FromInt(_courseid) + "&categoryid=" + FString::FromInt(_categoryid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_calendar_get_calendar_day_view::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_calendar_get_calendar_day_view::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_calendar_get_calendar_day_view::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_calendar_get_calendar_event_by_id* Ucore_calendar_get_calendar_event_by_id::core_calendar_get_calendar_event_by_id(
			const FString ServerURL,
			const FString Token,
			const int32 _eventid)
{
	Ucore_calendar_get_calendar_event_by_id* Node = NewObject<Ucore_calendar_get_calendar_event_by_id>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_calendar_get_calendar_event_by_id&eventid=" + FString::FromInt(_eventid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_calendar_get_calendar_event_by_id::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_calendar_get_calendar_event_by_id::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_calendar_get_calendar_event_by_id::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_calendar_get_calendar_events* Ucore_calendar_get_calendar_events::core_calendar_get_calendar_events(
			const FString ServerURL,
			const FString Token,
			const int32 _eventscourseids,
			const int32 _eventsgroupids,
			const int32 _eventscategoryids,
			const int32 _eventseventids,
			const int32 _optionsuserevents,
			const int32 _optionssiteevents,
			const int32 _optionstimestart,
			const int32 _optionstimeend,
			const int32 _optionsignorehidden)
{
	Ucore_calendar_get_calendar_events* Node = NewObject<Ucore_calendar_get_calendar_events>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_calendar_get_calendar_events&events[eventids][0]=" + FString::FromInt(_eventseventids) + "&events[courseids][0]=" + FString::FromInt(_eventscourseids) + "&events[groupids][0]=" + FString::FromInt(_eventsgroupids) + "&events[categoryids][0]=" + FString::FromInt(_eventscategoryids) + "&options[userevents]=" + FString::FromInt(_optionsuserevents) + "&options[siteevents]=" + FString::FromInt(_optionssiteevents) + "&options[timestart]=" + FString::FromInt(_optionstimestart) + "&options[timeend]=" + FString::FromInt(_optionstimeend) + "&options[ignorehidden]=" + FString::FromInt(_optionsignorehidden);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_calendar_get_calendar_events::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_calendar_get_calendar_events::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_calendar_get_calendar_events::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_calendar_get_calendar_export_token* Ucore_calendar_get_calendar_export_token::core_calendar_get_calendar_export_token(
			const FString ServerURL,
			const FString Token)
{
	Ucore_calendar_get_calendar_export_token* Node = NewObject<Ucore_calendar_get_calendar_export_token>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_calendar_get_calendar_export_token";

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_calendar_get_calendar_export_token::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_calendar_get_calendar_export_token::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_calendar_get_calendar_export_token::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_calendar_get_calendar_monthly_view* Ucore_calendar_get_calendar_monthly_view::core_calendar_get_calendar_monthly_view(
			const FString ServerURL,
			const FString Token,
			const int32 _year,
			const int32 _month,
			const int32 _courseid,
			const int32 _categoryid,
			const int32 _includenavigation,
			const int32 _mini,
			const int32 _day,
			const FString _view)
{
	Ucore_calendar_get_calendar_monthly_view* Node = NewObject<Ucore_calendar_get_calendar_monthly_view>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_calendar_get_calendar_monthly_view&year=" + FString::FromInt(_year) + "&month=" + FString::FromInt(_month) + "&courseid=" + FString::FromInt(_courseid) + "&categoryid=" + FString::FromInt(_categoryid) + "&includenavigation=" + FString::FromInt(_includenavigation) + "&mini=" + FString::FromInt(_mini) + "&day=" + FString::FromInt(_day) + "&view=" + _view;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_calendar_get_calendar_monthly_view::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_calendar_get_calendar_monthly_view::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_calendar_get_calendar_monthly_view::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_calendar_get_calendar_upcoming_view* Ucore_calendar_get_calendar_upcoming_view::core_calendar_get_calendar_upcoming_view(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _categoryid)
{
	Ucore_calendar_get_calendar_upcoming_view* Node = NewObject<Ucore_calendar_get_calendar_upcoming_view>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_calendar_get_calendar_upcoming_view&courseid=" + FString::FromInt(_courseid) + "&categoryid=" + FString::FromInt(_categoryid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_calendar_get_calendar_upcoming_view::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_calendar_get_calendar_upcoming_view::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_calendar_get_calendar_upcoming_view::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_calendar_get_timestamps* Ucore_calendar_get_timestamps::core_calendar_get_timestamps(
			const FString ServerURL,
			const FString Token,
			const int32 _datayear,
			const int32 _datamonth,
			const int32 _dataday,
			const FString _datakey,
			const int32 _datahour,
			const int32 _dataminute)
{
	Ucore_calendar_get_timestamps* Node = NewObject<Ucore_calendar_get_timestamps>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_calendar_get_timestamps&data[0][key]=" + _datakey + "&data[0][year]=" + FString::FromInt(_datayear) + "&data[0][month]=" + FString::FromInt(_datamonth) + "&data[0][day]=" + FString::FromInt(_dataday) + "&data[0][hour]=" + FString::FromInt(_datahour) + "&data[0][minute]=" + FString::FromInt(_dataminute);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_calendar_get_timestamps::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_calendar_get_timestamps::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_calendar_get_timestamps::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_calendar_submit_create_update_form* Ucore_calendar_submit_create_update_form::core_calendar_submit_create_update_form(
			const FString ServerURL,
			const FString Token,
			const FString _formdata)
{
	Ucore_calendar_submit_create_update_form* Node = NewObject<Ucore_calendar_submit_create_update_form>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_calendar_submit_create_update_form&formdata=" + _formdata;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_calendar_submit_create_update_form::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_calendar_submit_create_update_form::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_calendar_submit_create_update_form::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_calendar_update_event_start_day* Ucore_calendar_update_event_start_day::core_calendar_update_event_start_day(
			const FString ServerURL,
			const FString Token,
			const int32 _eventid,
			const int32 _daytimestamp)
{
	Ucore_calendar_update_event_start_day* Node = NewObject<Ucore_calendar_update_event_start_day>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_calendar_update_event_start_day&eventid=" + FString::FromInt(_eventid) + "&daytimestamp=" + FString::FromInt(_daytimestamp);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_calendar_update_event_start_day::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_calendar_update_event_start_day::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_calendar_update_event_start_day::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_change_editmode* Ucore_change_editmode::core_change_editmode(
			const FString ServerURL,
			const FString Token,
			const int32 _setmode,
			const int32 _context)
{
	Ucore_change_editmode* Node = NewObject<Ucore_change_editmode>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_change_editmode&setmode=" + FString::FromInt(_setmode) + "&context=" + FString::FromInt(_context);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_change_editmode::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_change_editmode::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_change_editmode::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_cohort_add_cohort_members* Ucore_cohort_add_cohort_members::core_cohort_add_cohort_members(
			const FString ServerURL,
			const FString Token,
			const FString _memberscohorttypetype,
			const FString _memberscohorttypevalue,
			const FString _membersusertypetype,
			const FString _membersusertypevalue)
{
	Ucore_cohort_add_cohort_members* Node = NewObject<Ucore_cohort_add_cohort_members>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_cohort_add_cohort_members&members[0][cohorttype][type]=" + _memberscohorttypetype + "&members[0][cohorttype][value]=" + _memberscohorttypevalue + "&members[0][usertype][type]=" + _membersusertypetype + "&members[0][usertype][value]=" + _membersusertypevalue;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_cohort_add_cohort_members::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_cohort_add_cohort_members::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_cohort_add_cohort_members::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_cohort_create_cohorts* Ucore_cohort_create_cohorts::core_cohort_create_cohorts(
			const FString ServerURL,
			const FString Token,
			const FString _cohortscategorytypetype,
			const FString _cohortscategorytypevalue,
			const FString _cohortsname,
			const FString _cohortsidnumber,
			const FString _cohortsdescription,
			const int32 _cohortsdescriptionformat,
			const int32 _cohortsvisible,
			const FString _cohortstheme)
{
	Ucore_cohort_create_cohorts* Node = NewObject<Ucore_cohort_create_cohorts>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_cohort_create_cohorts&cohorts[0][categorytype][type]=" + _cohortscategorytypetype + "&cohorts[0][categorytype][value]=" + _cohortscategorytypevalue + "&cohorts[0][name]=" + _cohortsname + "&cohorts[0][idnumber]=" + _cohortsidnumber + "&cohorts[0][description]=" + _cohortsdescription + "&cohorts[0][descriptionformat]=" + FString::FromInt(_cohortsdescriptionformat) + "&cohorts[0][visible]=" + FString::FromInt(_cohortsvisible) + "&cohorts[0][theme]=" + _cohortstheme;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_cohort_create_cohorts::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_cohort_create_cohorts::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_cohort_create_cohorts::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_cohort_delete_cohort_members* Ucore_cohort_delete_cohort_members::core_cohort_delete_cohort_members(
			const FString ServerURL,
			const FString Token,
			const int32 _memberscohortid,
			const int32 _membersuserid)
{
	Ucore_cohort_delete_cohort_members* Node = NewObject<Ucore_cohort_delete_cohort_members>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_cohort_delete_cohort_members&members[0][cohortid]=" + FString::FromInt(_memberscohortid) + "&members[0][userid]=" + FString::FromInt(_membersuserid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_cohort_delete_cohort_members::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_cohort_delete_cohort_members::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_cohort_delete_cohort_members::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_cohort_delete_cohorts* Ucore_cohort_delete_cohorts::core_cohort_delete_cohorts(
			const FString ServerURL,
			const FString Token,
			const int32 _cohortids)
{
	Ucore_cohort_delete_cohorts* Node = NewObject<Ucore_cohort_delete_cohorts>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_cohort_delete_cohorts&cohortids[0]=" + FString::FromInt(_cohortids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_cohort_delete_cohorts::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_cohort_delete_cohorts::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_cohort_delete_cohorts::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_cohort_get_cohort_members* Ucore_cohort_get_cohort_members::core_cohort_get_cohort_members(
			const FString ServerURL,
			const FString Token,
			const int32 _cohortids)
{
	Ucore_cohort_get_cohort_members* Node = NewObject<Ucore_cohort_get_cohort_members>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_cohort_get_cohort_members&cohortids[0]=" + FString::FromInt(_cohortids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_cohort_get_cohort_members::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_cohort_get_cohort_members::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_cohort_get_cohort_members::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_cohort_get_cohorts* Ucore_cohort_get_cohorts::core_cohort_get_cohorts(
			const FString ServerURL,
			const FString Token,
			const int32 _cohortids)
{
	Ucore_cohort_get_cohorts* Node = NewObject<Ucore_cohort_get_cohorts>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_cohort_get_cohorts&cohortids[0]=" + FString::FromInt(_cohortids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_cohort_get_cohorts::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_cohort_get_cohorts::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_cohort_get_cohorts::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_cohort_search_cohorts* Ucore_cohort_search_cohorts::core_cohort_search_cohorts(
			const FString ServerURL,
			const FString Token,
			const FString _query,
			const int32 _contextcontextid,
			const FString _contextcontextlevel,
			const int32 _contextinstanceid,
			const FString _includes,
			const int32 _limitfrom,
			const int32 _limitnum)
{
	Ucore_cohort_search_cohorts* Node = NewObject<Ucore_cohort_search_cohorts>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_cohort_search_cohorts&query=" + _query + "&context[contextid]=" + FString::FromInt(_contextcontextid) + "&context[contextlevel]=" + _contextcontextlevel + "&context[instanceid]=" + FString::FromInt(_contextinstanceid) + "&includes=" + _includes + "&limitfrom=" + FString::FromInt(_limitfrom) + "&limitnum=" + FString::FromInt(_limitnum);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_cohort_search_cohorts::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_cohort_search_cohorts::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_cohort_search_cohorts::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_cohort_update_cohorts* Ucore_cohort_update_cohorts::core_cohort_update_cohorts(
			const FString ServerURL,
			const FString Token,
			const int32 _cohortsid,
			const FString _cohortscategorytypetype,
			const FString _cohortscategorytypevalue,
			const FString _cohortsname,
			const FString _cohortsidnumber,
			const FString _cohortsdescription,
			const int32 _cohortsdescriptionformat,
			const int32 _cohortsvisible,
			const FString _cohortstheme)
{
	Ucore_cohort_update_cohorts* Node = NewObject<Ucore_cohort_update_cohorts>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_cohort_update_cohorts&cohorts[0][id]=" + FString::FromInt(_cohortsid) + "&cohorts[0][categorytype][type]=" + _cohortscategorytypetype + "&cohorts[0][categorytype][value]=" + _cohortscategorytypevalue + "&cohorts[0][name]=" + _cohortsname + "&cohorts[0][idnumber]=" + _cohortsidnumber + "&cohorts[0][description]=" + _cohortsdescription + "&cohorts[0][descriptionformat]=" + FString::FromInt(_cohortsdescriptionformat) + "&cohorts[0][visible]=" + FString::FromInt(_cohortsvisible) + "&cohorts[0][theme]=" + _cohortstheme;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_cohort_update_cohorts::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_cohort_update_cohorts::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_cohort_update_cohorts::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_comment_add_comments* Ucore_comment_add_comments::core_comment_add_comments(
			const FString ServerURL,
			const FString Token,
			const FString _commentscontextlevel,
			const int32 _commentsinstanceid,
			const FString _commentscomponent,
			const FString _commentscontent,
			const int32 _commentsitemid,
			const FString _commentsarea)
{
	Ucore_comment_add_comments* Node = NewObject<Ucore_comment_add_comments>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_comment_add_comments&comments[0][contextlevel]=" + _commentscontextlevel + "&comments[0][instanceid]=" + FString::FromInt(_commentsinstanceid) + "&comments[0][component]=" + _commentscomponent + "&comments[0][content]=" + _commentscontent + "&comments[0][itemid]=" + FString::FromInt(_commentsitemid) + "&comments[0][area]=" + _commentsarea;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_comment_add_comments::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_comment_add_comments::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_comment_add_comments::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_comment_delete_comments* Ucore_comment_delete_comments::core_comment_delete_comments(
			const FString ServerURL,
			const FString Token,
			const int32 _comments)
{
	Ucore_comment_delete_comments* Node = NewObject<Ucore_comment_delete_comments>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_comment_delete_comments&comments[0]=" + FString::FromInt(_comments);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_comment_delete_comments::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_comment_delete_comments::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_comment_delete_comments::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_comment_get_comments* Ucore_comment_get_comments::core_comment_get_comments(
			const FString ServerURL,
			const FString Token,
			const FString _contextlevel,
			const int32 _instanceid,
			const FString _component,
			const int32 _itemid,
			const FString _area,
			const int32 _page,
			const FString _sortdirection)
{
	Ucore_comment_get_comments* Node = NewObject<Ucore_comment_get_comments>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_comment_get_comments&contextlevel=" + _contextlevel + "&instanceid=" + FString::FromInt(_instanceid) + "&component=" + _component + "&itemid=" + FString::FromInt(_itemid) + "&area=" + _area + "&page=" + FString::FromInt(_page) + "&sortdirection=" + _sortdirection;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_comment_get_comments::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_comment_get_comments::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_comment_get_comments::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_add_competency_to_course* Ucore_competency_add_competency_to_course::core_competency_add_competency_to_course(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _competencyid)
{
	Ucore_competency_add_competency_to_course* Node = NewObject<Ucore_competency_add_competency_to_course>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_add_competency_to_course&courseid=" + FString::FromInt(_courseid) + "&competencyid=" + FString::FromInt(_competencyid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_add_competency_to_course::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_add_competency_to_course::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_add_competency_to_course::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_add_competency_to_plan* Ucore_competency_add_competency_to_plan::core_competency_add_competency_to_plan(
			const FString ServerURL,
			const FString Token,
			const int32 _planid,
			const int32 _competencyid)
{
	Ucore_competency_add_competency_to_plan* Node = NewObject<Ucore_competency_add_competency_to_plan>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_add_competency_to_plan&planid=" + FString::FromInt(_planid) + "&competencyid=" + FString::FromInt(_competencyid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_add_competency_to_plan::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_add_competency_to_plan::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_add_competency_to_plan::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_add_competency_to_template* Ucore_competency_add_competency_to_template::core_competency_add_competency_to_template(
			const FString ServerURL,
			const FString Token,
			const int32 _templateid,
			const int32 _competencyid)
{
	Ucore_competency_add_competency_to_template* Node = NewObject<Ucore_competency_add_competency_to_template>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_add_competency_to_template&templateid=" + FString::FromInt(_templateid) + "&competencyid=" + FString::FromInt(_competencyid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_add_competency_to_template::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_add_competency_to_template::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_add_competency_to_template::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_add_related_competency* Ucore_competency_add_related_competency::core_competency_add_related_competency(
			const FString ServerURL,
			const FString Token,
			const int32 _competencyid,
			const int32 _relatedcompetencyid)
{
	Ucore_competency_add_related_competency* Node = NewObject<Ucore_competency_add_related_competency>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_add_related_competency&competencyid=" + FString::FromInt(_competencyid) + "&relatedcompetencyid=" + FString::FromInt(_relatedcompetencyid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_add_related_competency::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_add_related_competency::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_add_related_competency::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_approve_plan* Ucore_competency_approve_plan::core_competency_approve_plan(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Ucore_competency_approve_plan* Node = NewObject<Ucore_competency_approve_plan>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_approve_plan&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_approve_plan::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_approve_plan::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_approve_plan::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_competency_framework_viewed* Ucore_competency_competency_framework_viewed::core_competency_competency_framework_viewed(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Ucore_competency_competency_framework_viewed* Node = NewObject<Ucore_competency_competency_framework_viewed>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_competency_framework_viewed&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_competency_framework_viewed::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_competency_framework_viewed::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_competency_framework_viewed::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_competency_viewed* Ucore_competency_competency_viewed::core_competency_competency_viewed(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Ucore_competency_competency_viewed* Node = NewObject<Ucore_competency_competency_viewed>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_competency_viewed&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_competency_viewed::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_competency_viewed::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_competency_viewed::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_complete_plan* Ucore_competency_complete_plan::core_competency_complete_plan(
			const FString ServerURL,
			const FString Token,
			const int32 _planid)
{
	Ucore_competency_complete_plan* Node = NewObject<Ucore_competency_complete_plan>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_complete_plan&planid=" + FString::FromInt(_planid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_complete_plan::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_complete_plan::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_complete_plan::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_count_competencies* Ucore_competency_count_competencies::core_competency_count_competencies(
			const FString ServerURL,
			const FString Token,
			const FString _filterscolumn,
			const FString _filtersvalue)
{
	Ucore_competency_count_competencies* Node = NewObject<Ucore_competency_count_competencies>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_count_competencies&filters[0][column]=" + _filterscolumn + "&filters[0][value]=" + _filtersvalue;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_count_competencies::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_count_competencies::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_count_competencies::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_count_competencies_in_course* Ucore_competency_count_competencies_in_course::core_competency_count_competencies_in_course(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Ucore_competency_count_competencies_in_course* Node = NewObject<Ucore_competency_count_competencies_in_course>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_count_competencies_in_course&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_count_competencies_in_course::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_count_competencies_in_course::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_count_competencies_in_course::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_count_competencies_in_template* Ucore_competency_count_competencies_in_template::core_competency_count_competencies_in_template(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Ucore_competency_count_competencies_in_template* Node = NewObject<Ucore_competency_count_competencies_in_template>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_count_competencies_in_template&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_count_competencies_in_template::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_count_competencies_in_template::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_count_competencies_in_template::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_count_competency_frameworks* Ucore_competency_count_competency_frameworks::core_competency_count_competency_frameworks(
			const FString ServerURL,
			const FString Token,
			const int32 _contextcontextid,
			const FString _contextcontextlevel,
			const int32 _contextinstanceid,
			const FString _includes)
{
	Ucore_competency_count_competency_frameworks* Node = NewObject<Ucore_competency_count_competency_frameworks>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_count_competency_frameworks&context[contextid]=" + FString::FromInt(_contextcontextid) + "&context[contextlevel]=" + _contextcontextlevel + "&context[instanceid]=" + FString::FromInt(_contextinstanceid) + "&includes=" + _includes;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_count_competency_frameworks::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_count_competency_frameworks::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_count_competency_frameworks::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_count_course_module_competencies* Ucore_competency_count_course_module_competencies::core_competency_count_course_module_competencies(
			const FString ServerURL,
			const FString Token,
			const int32 _cmid)
{
	Ucore_competency_count_course_module_competencies* Node = NewObject<Ucore_competency_count_course_module_competencies>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_count_course_module_competencies&cmid=" + FString::FromInt(_cmid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_count_course_module_competencies::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_count_course_module_competencies::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_count_course_module_competencies::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_count_courses_using_competency* Ucore_competency_count_courses_using_competency::core_competency_count_courses_using_competency(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Ucore_competency_count_courses_using_competency* Node = NewObject<Ucore_competency_count_courses_using_competency>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_count_courses_using_competency&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_count_courses_using_competency::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_count_courses_using_competency::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_count_courses_using_competency::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_count_templates* Ucore_competency_count_templates::core_competency_count_templates(
			const FString ServerURL,
			const FString Token,
			const int32 _contextcontextid,
			const FString _contextcontextlevel,
			const int32 _contextinstanceid,
			const FString _includes)
{
	Ucore_competency_count_templates* Node = NewObject<Ucore_competency_count_templates>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_count_templates&context[contextid]=" + FString::FromInt(_contextcontextid) + "&context[contextlevel]=" + _contextcontextlevel + "&context[instanceid]=" + FString::FromInt(_contextinstanceid) + "&includes=" + _includes;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_count_templates::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_count_templates::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_count_templates::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_count_templates_using_competency* Ucore_competency_count_templates_using_competency::core_competency_count_templates_using_competency(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Ucore_competency_count_templates_using_competency* Node = NewObject<Ucore_competency_count_templates_using_competency>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_count_templates_using_competency&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_count_templates_using_competency::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_count_templates_using_competency::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_count_templates_using_competency::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_create_competency* Ucore_competency_create_competency::core_competency_create_competency(
			const FString ServerURL,
			const FString Token,
			const FString _competencyshortname,
			const FString _competencyidnumber,
			const FString _competencydescription,
			const int32 _competencydescriptionformat,
			const int32 _competencysortorder,
			const int32 _competencyparentid,
			const FString _competencypath,
			const int32 _competencyruleoutcome,
			const FString _competencyruletype,
			const FString _competencyruleconfig,
			const int32 _competencyscaleid,
			const FString _competencyscaleconfiguration,
			const int32 _competencycompetencyframeworkid,
			const int32 _competencytimecreated,
			const int32 _competencytimemodified,
			const int32 _competencyusermodified)
{
	Ucore_competency_create_competency* Node = NewObject<Ucore_competency_create_competency>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_create_competency&competency[shortname]=" + _competencyshortname + "&competency[idnumber]=" + _competencyidnumber + "&competency[description]=" + _competencydescription + "&competency[descriptionformat]=" + FString::FromInt(_competencydescriptionformat) + "&competency[sortorder]=" + FString::FromInt(_competencysortorder) + "&competency[parentid]=" + FString::FromInt(_competencyparentid) + "&competency[path]=" + _competencypath + "&competency[ruleoutcome]=" + FString::FromInt(_competencyruleoutcome) + "&competency[ruletype]=" + _competencyruletype + "&competency[ruleconfig]=" + _competencyruleconfig + "&competency[scaleid]=" + FString::FromInt(_competencyscaleid) + "&competency[scaleconfiguration]=" + _competencyscaleconfiguration + "&competency[competencyframeworkid]=" + FString::FromInt(_competencycompetencyframeworkid) + "&competency[timecreated]=" + FString::FromInt(_competencytimecreated) + "&competency[timemodified]=" + FString::FromInt(_competencytimemodified) + "&competency[usermodified]=" + FString::FromInt(_competencyusermodified);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_create_competency::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_create_competency::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_create_competency::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_create_competency_framework* Ucore_competency_create_competency_framework::core_competency_create_competency_framework(
			const FString ServerURL,
			const FString Token,
			const FString _competencyframeworkshortname,
			const FString _competencyframeworkidnumber,
			const int32 _competencyframeworkscaleid,
			const FString _competencyframeworkscaleconfiguration,
			const FString _competencyframeworkdescription,
			const int32 _competencyframeworkdescriptionformat,
			const int32 _competencyframeworkvisible,
			const int32 _competencyframeworkcontextid,
			const FString _competencyframeworkcontextlevel,
			const int32 _competencyframeworkinstanceid,
			const FString _competencyframeworktaxonomies,
			const int32 _competencyframeworktimecreated,
			const int32 _competencyframeworktimemodified,
			const int32 _competencyframeworkusermodified)
{
	Ucore_competency_create_competency_framework* Node = NewObject<Ucore_competency_create_competency_framework>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_create_competency_framework&competencyframework[shortname]=" + _competencyframeworkshortname + "&competencyframework[idnumber]=" + _competencyframeworkidnumber + "&competencyframework[description]=" + _competencyframeworkdescription + "&competencyframework[descriptionformat]=" + FString::FromInt(_competencyframeworkdescriptionformat) + "&competencyframework[visible]=" + FString::FromInt(_competencyframeworkvisible) + "&competencyframework[scaleid]=" + FString::FromInt(_competencyframeworkscaleid) + "&competencyframework[scaleconfiguration]=" + _competencyframeworkscaleconfiguration + "&competencyframework[contextid]=" + FString::FromInt(_competencyframeworkcontextid) + "&competencyframework[contextlevel]=" + _competencyframeworkcontextlevel + "&competencyframework[instanceid]=" + FString::FromInt(_competencyframeworkinstanceid) + "&competencyframework[taxonomies]=" + _competencyframeworktaxonomies + "&competencyframework[timecreated]=" + FString::FromInt(_competencyframeworktimecreated) + "&competencyframework[timemodified]=" + FString::FromInt(_competencyframeworktimemodified) + "&competencyframework[usermodified]=" + FString::FromInt(_competencyframeworkusermodified);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_create_competency_framework::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_create_competency_framework::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_create_competency_framework::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_create_plan* Ucore_competency_create_plan::core_competency_create_plan(
			const FString ServerURL,
			const FString Token,
			const FString _planname,
			const int32 _planuserid,
			const FString _plandescription,
			const int32 _plandescriptionformat,
			const int32 _plantemplateid,
			const int32 _planorigtemplateid,
			const int32 _planstatus,
			const int32 _planduedate,
			const int32 _planreviewerid,
			const int32 _plantimecreated,
			const int32 _plantimemodified,
			const int32 _planusermodified)
{
	Ucore_competency_create_plan* Node = NewObject<Ucore_competency_create_plan>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_create_plan&plan[name]=" + _planname + "&plan[description]=" + _plandescription + "&plan[descriptionformat]=" + FString::FromInt(_plandescriptionformat) + "&plan[userid]=" + FString::FromInt(_planuserid) + "&plan[templateid]=" + FString::FromInt(_plantemplateid) + "&plan[origtemplateid]=" + FString::FromInt(_planorigtemplateid) + "&plan[status]=" + FString::FromInt(_planstatus) + "&plan[duedate]=" + FString::FromInt(_planduedate) + "&plan[reviewerid]=" + FString::FromInt(_planreviewerid) + "&plan[timecreated]=" + FString::FromInt(_plantimecreated) + "&plan[timemodified]=" + FString::FromInt(_plantimemodified) + "&plan[usermodified]=" + FString::FromInt(_planusermodified);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_create_plan::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_create_plan::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_create_plan::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_create_template* Ucore_competency_create_template::core_competency_create_template(
			const FString ServerURL,
			const FString Token,
			const FString _templateshortname,
			const FString _templatedescription,
			const int32 _templatedescriptionformat,
			const int32 _templateduedate,
			const int32 _templatevisible,
			const int32 _templatecontextid,
			const FString _templatecontextlevel,
			const int32 _templateinstanceid,
			const int32 _templatetimecreated,
			const int32 _templatetimemodified,
			const int32 _templateusermodified)
{
	Ucore_competency_create_template* Node = NewObject<Ucore_competency_create_template>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_create_template&template[shortname]=" + _templateshortname + "&template[description]=" + _templatedescription + "&template[descriptionformat]=" + FString::FromInt(_templatedescriptionformat) + "&template[duedate]=" + FString::FromInt(_templateduedate) + "&template[visible]=" + FString::FromInt(_templatevisible) + "&template[contextid]=" + FString::FromInt(_templatecontextid) + "&template[contextlevel]=" + _templatecontextlevel + "&template[instanceid]=" + FString::FromInt(_templateinstanceid) + "&template[timecreated]=" + FString::FromInt(_templatetimecreated) + "&template[timemodified]=" + FString::FromInt(_templatetimemodified) + "&template[usermodified]=" + FString::FromInt(_templateusermodified);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_create_template::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_create_template::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_create_template::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_create_user_evidence_competency* Ucore_competency_create_user_evidence_competency::core_competency_create_user_evidence_competency(
			const FString ServerURL,
			const FString Token,
			const int32 _userevidenceid,
			const int32 _competencyid)
{
	Ucore_competency_create_user_evidence_competency* Node = NewObject<Ucore_competency_create_user_evidence_competency>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_create_user_evidence_competency&userevidenceid=" + FString::FromInt(_userevidenceid) + "&competencyid=" + FString::FromInt(_competencyid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_create_user_evidence_competency::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_create_user_evidence_competency::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_create_user_evidence_competency::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_delete_competency* Ucore_competency_delete_competency::core_competency_delete_competency(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Ucore_competency_delete_competency* Node = NewObject<Ucore_competency_delete_competency>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_delete_competency&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_delete_competency::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_delete_competency::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_delete_competency::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_delete_competency_framework* Ucore_competency_delete_competency_framework::core_competency_delete_competency_framework(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Ucore_competency_delete_competency_framework* Node = NewObject<Ucore_competency_delete_competency_framework>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_delete_competency_framework&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_delete_competency_framework::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_delete_competency_framework::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_delete_competency_framework::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_delete_evidence* Ucore_competency_delete_evidence::core_competency_delete_evidence(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Ucore_competency_delete_evidence* Node = NewObject<Ucore_competency_delete_evidence>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_delete_evidence&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_delete_evidence::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_delete_evidence::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_delete_evidence::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_delete_plan* Ucore_competency_delete_plan::core_competency_delete_plan(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Ucore_competency_delete_plan* Node = NewObject<Ucore_competency_delete_plan>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_delete_plan&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_delete_plan::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_delete_plan::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_delete_plan::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_delete_template* Ucore_competency_delete_template::core_competency_delete_template(
			const FString ServerURL,
			const FString Token,
			const int32 _id,
			const int32 _deleteplans)
{
	Ucore_competency_delete_template* Node = NewObject<Ucore_competency_delete_template>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_delete_template&id=" + FString::FromInt(_id) + "&deleteplans=" + FString::FromInt(_deleteplans);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_delete_template::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_delete_template::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_delete_template::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_delete_user_evidence* Ucore_competency_delete_user_evidence::core_competency_delete_user_evidence(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Ucore_competency_delete_user_evidence* Node = NewObject<Ucore_competency_delete_user_evidence>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_delete_user_evidence&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_delete_user_evidence::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_delete_user_evidence::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_delete_user_evidence::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_delete_user_evidence_competency* Ucore_competency_delete_user_evidence_competency::core_competency_delete_user_evidence_competency(
			const FString ServerURL,
			const FString Token,
			const int32 _userevidenceid,
			const int32 _competencyid)
{
	Ucore_competency_delete_user_evidence_competency* Node = NewObject<Ucore_competency_delete_user_evidence_competency>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_delete_user_evidence_competency&userevidenceid=" + FString::FromInt(_userevidenceid) + "&competencyid=" + FString::FromInt(_competencyid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_delete_user_evidence_competency::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_delete_user_evidence_competency::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_delete_user_evidence_competency::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_duplicate_competency_framework* Ucore_competency_duplicate_competency_framework::core_competency_duplicate_competency_framework(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Ucore_competency_duplicate_competency_framework* Node = NewObject<Ucore_competency_duplicate_competency_framework>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_duplicate_competency_framework&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_duplicate_competency_framework::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_duplicate_competency_framework::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_duplicate_competency_framework::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_duplicate_template* Ucore_competency_duplicate_template::core_competency_duplicate_template(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Ucore_competency_duplicate_template* Node = NewObject<Ucore_competency_duplicate_template>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_duplicate_template&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_duplicate_template::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_duplicate_template::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_duplicate_template::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_get_scale_values* Ucore_competency_get_scale_values::core_competency_get_scale_values(
			const FString ServerURL,
			const FString Token,
			const int32 _scaleid)
{
	Ucore_competency_get_scale_values* Node = NewObject<Ucore_competency_get_scale_values>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_get_scale_values&scaleid=" + FString::FromInt(_scaleid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_get_scale_values::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_get_scale_values::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_get_scale_values::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_grade_competency* Ucore_competency_grade_competency::core_competency_grade_competency(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _competencyid,
			const int32 _grade,
			const FString _note)
{
	Ucore_competency_grade_competency* Node = NewObject<Ucore_competency_grade_competency>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_grade_competency&userid=" + FString::FromInt(_userid) + "&competencyid=" + FString::FromInt(_competencyid) + "&grade=" + FString::FromInt(_grade) + "&note=" + _note;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_grade_competency::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_grade_competency::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_grade_competency::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_grade_competency_in_course* Ucore_competency_grade_competency_in_course::core_competency_grade_competency_in_course(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _userid,
			const int32 _competencyid,
			const int32 _grade,
			const FString _note)
{
	Ucore_competency_grade_competency_in_course* Node = NewObject<Ucore_competency_grade_competency_in_course>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_grade_competency_in_course&courseid=" + FString::FromInt(_courseid) + "&userid=" + FString::FromInt(_userid) + "&competencyid=" + FString::FromInt(_competencyid) + "&grade=" + FString::FromInt(_grade) + "&note=" + _note;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_grade_competency_in_course::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_grade_competency_in_course::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_grade_competency_in_course::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_grade_competency_in_plan* Ucore_competency_grade_competency_in_plan::core_competency_grade_competency_in_plan(
			const FString ServerURL,
			const FString Token,
			const int32 _planid,
			const int32 _competencyid,
			const int32 _grade,
			const FString _note)
{
	Ucore_competency_grade_competency_in_plan* Node = NewObject<Ucore_competency_grade_competency_in_plan>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_grade_competency_in_plan&planid=" + FString::FromInt(_planid) + "&competencyid=" + FString::FromInt(_competencyid) + "&grade=" + FString::FromInt(_grade) + "&note=" + _note;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_grade_competency_in_plan::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_grade_competency_in_plan::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_grade_competency_in_plan::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_list_competencies* Ucore_competency_list_competencies::core_competency_list_competencies(
			const FString ServerURL,
			const FString Token,
			const FString _filterscolumn,
			const FString _filtersvalue,
			const FString _sort,
			const FString _order,
			const int32 _skip,
			const int32 _limit)
{
	Ucore_competency_list_competencies* Node = NewObject<Ucore_competency_list_competencies>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_list_competencies&filters[0][column]=" + _filterscolumn + "&filters[0][value]=" + _filtersvalue + "&sort=" + _sort + "&order=" + _order + "&skip=" + FString::FromInt(_skip) + "&limit=" + FString::FromInt(_limit);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_list_competencies::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_list_competencies::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_list_competencies::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_list_competencies_in_template* Ucore_competency_list_competencies_in_template::core_competency_list_competencies_in_template(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Ucore_competency_list_competencies_in_template* Node = NewObject<Ucore_competency_list_competencies_in_template>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_list_competencies_in_template&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_list_competencies_in_template::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_list_competencies_in_template::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_list_competencies_in_template::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_list_competency_frameworks* Ucore_competency_list_competency_frameworks::core_competency_list_competency_frameworks(
			const FString ServerURL,
			const FString Token,
			const FString _sort,
			const FString _order,
			const int32 _skip,
			const int32 _limit,
			const int32 _contextcontextid,
			const FString _contextcontextlevel,
			const int32 _contextinstanceid,
			const FString _includes,
			const int32 _onlyvisible,
			const FString _query)
{
	Ucore_competency_list_competency_frameworks* Node = NewObject<Ucore_competency_list_competency_frameworks>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_list_competency_frameworks&sort=" + _sort + "&order=" + _order + "&skip=" + FString::FromInt(_skip) + "&limit=" + FString::FromInt(_limit) + "&context[contextid]=" + FString::FromInt(_contextcontextid) + "&context[contextlevel]=" + _contextcontextlevel + "&context[instanceid]=" + FString::FromInt(_contextinstanceid) + "&includes=" + _includes + "&onlyvisible=" + FString::FromInt(_onlyvisible) + "&query=" + _query;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_list_competency_frameworks::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_list_competency_frameworks::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_list_competency_frameworks::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_list_course_competencies* Ucore_competency_list_course_competencies::core_competency_list_course_competencies(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Ucore_competency_list_course_competencies* Node = NewObject<Ucore_competency_list_course_competencies>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_list_course_competencies&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_list_course_competencies::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_list_course_competencies::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_list_course_competencies::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_list_course_module_competencies* Ucore_competency_list_course_module_competencies::core_competency_list_course_module_competencies(
			const FString ServerURL,
			const FString Token,
			const int32 _cmid)
{
	Ucore_competency_list_course_module_competencies* Node = NewObject<Ucore_competency_list_course_module_competencies>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_list_course_module_competencies&cmid=" + FString::FromInt(_cmid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_list_course_module_competencies::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_list_course_module_competencies::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_list_course_module_competencies::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_list_plan_competencies* Ucore_competency_list_plan_competencies::core_competency_list_plan_competencies(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Ucore_competency_list_plan_competencies* Node = NewObject<Ucore_competency_list_plan_competencies>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_list_plan_competencies&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_list_plan_competencies::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_list_plan_competencies::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_list_plan_competencies::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_list_templates* Ucore_competency_list_templates::core_competency_list_templates(
			const FString ServerURL,
			const FString Token,
			const FString _sort,
			const FString _order,
			const int32 _skip,
			const int32 _limit,
			const int32 _contextcontextid,
			const FString _contextcontextlevel,
			const int32 _contextinstanceid,
			const FString _includes,
			const int32 _onlyvisible)
{
	Ucore_competency_list_templates* Node = NewObject<Ucore_competency_list_templates>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_list_templates&sort=" + _sort + "&order=" + _order + "&skip=" + FString::FromInt(_skip) + "&limit=" + FString::FromInt(_limit) + "&context[contextid]=" + FString::FromInt(_contextcontextid) + "&context[contextlevel]=" + _contextcontextlevel + "&context[instanceid]=" + FString::FromInt(_contextinstanceid) + "&includes=" + _includes + "&onlyvisible=" + FString::FromInt(_onlyvisible);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_list_templates::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_list_templates::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_list_templates::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_list_templates_using_competency* Ucore_competency_list_templates_using_competency::core_competency_list_templates_using_competency(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Ucore_competency_list_templates_using_competency* Node = NewObject<Ucore_competency_list_templates_using_competency>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_list_templates_using_competency&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_list_templates_using_competency::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_list_templates_using_competency::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_list_templates_using_competency::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_list_user_plans* Ucore_competency_list_user_plans::core_competency_list_user_plans(
			const FString ServerURL,
			const FString Token,
			const int32 _userid)
{
	Ucore_competency_list_user_plans* Node = NewObject<Ucore_competency_list_user_plans>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_list_user_plans&userid=" + FString::FromInt(_userid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_list_user_plans::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_list_user_plans::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_list_user_plans::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_move_down_competency* Ucore_competency_move_down_competency::core_competency_move_down_competency(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Ucore_competency_move_down_competency* Node = NewObject<Ucore_competency_move_down_competency>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_move_down_competency&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_move_down_competency::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_move_down_competency::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_move_down_competency::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_move_up_competency* Ucore_competency_move_up_competency::core_competency_move_up_competency(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Ucore_competency_move_up_competency* Node = NewObject<Ucore_competency_move_up_competency>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_move_up_competency&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_move_up_competency::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_move_up_competency::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_move_up_competency::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_plan_cancel_review_request* Ucore_competency_plan_cancel_review_request::core_competency_plan_cancel_review_request(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Ucore_competency_plan_cancel_review_request* Node = NewObject<Ucore_competency_plan_cancel_review_request>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_plan_cancel_review_request&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_plan_cancel_review_request::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_plan_cancel_review_request::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_plan_cancel_review_request::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_plan_request_review* Ucore_competency_plan_request_review::core_competency_plan_request_review(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Ucore_competency_plan_request_review* Node = NewObject<Ucore_competency_plan_request_review>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_plan_request_review&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_plan_request_review::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_plan_request_review::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_plan_request_review::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_plan_start_review* Ucore_competency_plan_start_review::core_competency_plan_start_review(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Ucore_competency_plan_start_review* Node = NewObject<Ucore_competency_plan_start_review>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_plan_start_review&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_plan_start_review::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_plan_start_review::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_plan_start_review::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_plan_stop_review* Ucore_competency_plan_stop_review::core_competency_plan_stop_review(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Ucore_competency_plan_stop_review* Node = NewObject<Ucore_competency_plan_stop_review>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_plan_stop_review&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_plan_stop_review::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_plan_stop_review::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_plan_stop_review::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_read_competency* Ucore_competency_read_competency::core_competency_read_competency(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Ucore_competency_read_competency* Node = NewObject<Ucore_competency_read_competency>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_read_competency&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_read_competency::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_read_competency::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_read_competency::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_read_competency_framework* Ucore_competency_read_competency_framework::core_competency_read_competency_framework(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Ucore_competency_read_competency_framework* Node = NewObject<Ucore_competency_read_competency_framework>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_read_competency_framework&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_read_competency_framework::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_read_competency_framework::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_read_competency_framework::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_read_plan* Ucore_competency_read_plan::core_competency_read_plan(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Ucore_competency_read_plan* Node = NewObject<Ucore_competency_read_plan>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_read_plan&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_read_plan::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_read_plan::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_read_plan::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_read_template* Ucore_competency_read_template::core_competency_read_template(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Ucore_competency_read_template* Node = NewObject<Ucore_competency_read_template>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_read_template&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_read_template::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_read_template::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_read_template::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_read_user_evidence* Ucore_competency_read_user_evidence::core_competency_read_user_evidence(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Ucore_competency_read_user_evidence* Node = NewObject<Ucore_competency_read_user_evidence>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_read_user_evidence&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_read_user_evidence::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_read_user_evidence::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_read_user_evidence::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_remove_competency_from_course* Ucore_competency_remove_competency_from_course::core_competency_remove_competency_from_course(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _competencyid)
{
	Ucore_competency_remove_competency_from_course* Node = NewObject<Ucore_competency_remove_competency_from_course>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_remove_competency_from_course&courseid=" + FString::FromInt(_courseid) + "&competencyid=" + FString::FromInt(_competencyid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_remove_competency_from_course::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_remove_competency_from_course::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_remove_competency_from_course::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_remove_competency_from_plan* Ucore_competency_remove_competency_from_plan::core_competency_remove_competency_from_plan(
			const FString ServerURL,
			const FString Token,
			const int32 _planid,
			const int32 _competencyid)
{
	Ucore_competency_remove_competency_from_plan* Node = NewObject<Ucore_competency_remove_competency_from_plan>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_remove_competency_from_plan&planid=" + FString::FromInt(_planid) + "&competencyid=" + FString::FromInt(_competencyid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_remove_competency_from_plan::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_remove_competency_from_plan::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_remove_competency_from_plan::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_remove_competency_from_template* Ucore_competency_remove_competency_from_template::core_competency_remove_competency_from_template(
			const FString ServerURL,
			const FString Token,
			const int32 _templateid,
			const int32 _competencyid)
{
	Ucore_competency_remove_competency_from_template* Node = NewObject<Ucore_competency_remove_competency_from_template>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_remove_competency_from_template&templateid=" + FString::FromInt(_templateid) + "&competencyid=" + FString::FromInt(_competencyid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_remove_competency_from_template::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_remove_competency_from_template::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_remove_competency_from_template::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_remove_related_competency* Ucore_competency_remove_related_competency::core_competency_remove_related_competency(
			const FString ServerURL,
			const FString Token,
			const int32 _competencyid,
			const int32 _relatedcompetencyid)
{
	Ucore_competency_remove_related_competency* Node = NewObject<Ucore_competency_remove_related_competency>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_remove_related_competency&competencyid=" + FString::FromInt(_competencyid) + "&relatedcompetencyid=" + FString::FromInt(_relatedcompetencyid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_remove_related_competency::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_remove_related_competency::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_remove_related_competency::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_reopen_plan* Ucore_competency_reopen_plan::core_competency_reopen_plan(
			const FString ServerURL,
			const FString Token,
			const int32 _planid)
{
	Ucore_competency_reopen_plan* Node = NewObject<Ucore_competency_reopen_plan>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_reopen_plan&planid=" + FString::FromInt(_planid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_reopen_plan::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_reopen_plan::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_reopen_plan::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_reorder_course_competency* Ucore_competency_reorder_course_competency::core_competency_reorder_course_competency(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _competencyidfrom,
			const int32 _competencyidto)
{
	Ucore_competency_reorder_course_competency* Node = NewObject<Ucore_competency_reorder_course_competency>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_reorder_course_competency&courseid=" + FString::FromInt(_courseid) + "&competencyidfrom=" + FString::FromInt(_competencyidfrom) + "&competencyidto=" + FString::FromInt(_competencyidto);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_reorder_course_competency::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_reorder_course_competency::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_reorder_course_competency::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_reorder_plan_competency* Ucore_competency_reorder_plan_competency::core_competency_reorder_plan_competency(
			const FString ServerURL,
			const FString Token,
			const int32 _planid,
			const int32 _competencyidfrom,
			const int32 _competencyidto)
{
	Ucore_competency_reorder_plan_competency* Node = NewObject<Ucore_competency_reorder_plan_competency>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_reorder_plan_competency&planid=" + FString::FromInt(_planid) + "&competencyidfrom=" + FString::FromInt(_competencyidfrom) + "&competencyidto=" + FString::FromInt(_competencyidto);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_reorder_plan_competency::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_reorder_plan_competency::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_reorder_plan_competency::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_reorder_template_competency* Ucore_competency_reorder_template_competency::core_competency_reorder_template_competency(
			const FString ServerURL,
			const FString Token,
			const int32 _templateid,
			const int32 _competencyidfrom,
			const int32 _competencyidto)
{
	Ucore_competency_reorder_template_competency* Node = NewObject<Ucore_competency_reorder_template_competency>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_reorder_template_competency&templateid=" + FString::FromInt(_templateid) + "&competencyidfrom=" + FString::FromInt(_competencyidfrom) + "&competencyidto=" + FString::FromInt(_competencyidto);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_reorder_template_competency::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_reorder_template_competency::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_reorder_template_competency::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_request_review_of_user_evidence_linked_competencies* Ucore_competency_request_review_of_user_evidence_linked_competencies::core_competency_request_review_of_user_evidence_linked_competencies(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Ucore_competency_request_review_of_user_evidence_linked_competencies* Node = NewObject<Ucore_competency_request_review_of_user_evidence_linked_competencies>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_request_review_of_user_evidence_linked_competencies&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_request_review_of_user_evidence_linked_competencies::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_request_review_of_user_evidence_linked_competencies::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_request_review_of_user_evidence_linked_competencies::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_search_competencies* Ucore_competency_search_competencies::core_competency_search_competencies(
			const FString ServerURL,
			const FString Token,
			const FString _searchtext,
			const int32 _competencyframeworkid)
{
	Ucore_competency_search_competencies* Node = NewObject<Ucore_competency_search_competencies>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_search_competencies&searchtext=" + _searchtext + "&competencyframeworkid=" + FString::FromInt(_competencyframeworkid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_search_competencies::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_search_competencies::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_search_competencies::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_set_course_competency_ruleoutcome* Ucore_competency_set_course_competency_ruleoutcome::core_competency_set_course_competency_ruleoutcome(
			const FString ServerURL,
			const FString Token,
			const int32 _coursecompetencyid,
			const int32 _ruleoutcome)
{
	Ucore_competency_set_course_competency_ruleoutcome* Node = NewObject<Ucore_competency_set_course_competency_ruleoutcome>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_set_course_competency_ruleoutcome&coursecompetencyid=" + FString::FromInt(_coursecompetencyid) + "&ruleoutcome=" + FString::FromInt(_ruleoutcome);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_set_course_competency_ruleoutcome::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_set_course_competency_ruleoutcome::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_set_course_competency_ruleoutcome::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_set_parent_competency* Ucore_competency_set_parent_competency::core_competency_set_parent_competency(
			const FString ServerURL,
			const FString Token,
			const int32 _competencyid,
			const int32 _parentid)
{
	Ucore_competency_set_parent_competency* Node = NewObject<Ucore_competency_set_parent_competency>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_set_parent_competency&competencyid=" + FString::FromInt(_competencyid) + "&parentid=" + FString::FromInt(_parentid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_set_parent_competency::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_set_parent_competency::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_set_parent_competency::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_template_has_related_data* Ucore_competency_template_has_related_data::core_competency_template_has_related_data(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Ucore_competency_template_has_related_data* Node = NewObject<Ucore_competency_template_has_related_data>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_template_has_related_data&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_template_has_related_data::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_template_has_related_data::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_template_has_related_data::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_template_viewed* Ucore_competency_template_viewed::core_competency_template_viewed(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Ucore_competency_template_viewed* Node = NewObject<Ucore_competency_template_viewed>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_template_viewed&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_template_viewed::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_template_viewed::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_template_viewed::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_unapprove_plan* Ucore_competency_unapprove_plan::core_competency_unapprove_plan(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Ucore_competency_unapprove_plan* Node = NewObject<Ucore_competency_unapprove_plan>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_unapprove_plan&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_unapprove_plan::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_unapprove_plan::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_unapprove_plan::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_unlink_plan_from_template* Ucore_competency_unlink_plan_from_template::core_competency_unlink_plan_from_template(
			const FString ServerURL,
			const FString Token,
			const int32 _planid)
{
	Ucore_competency_unlink_plan_from_template* Node = NewObject<Ucore_competency_unlink_plan_from_template>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_unlink_plan_from_template&planid=" + FString::FromInt(_planid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_unlink_plan_from_template::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_unlink_plan_from_template::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_unlink_plan_from_template::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_update_competency* Ucore_competency_update_competency::core_competency_update_competency(
			const FString ServerURL,
			const FString Token,
			const FString _competencyshortname,
			const FString _competencyidnumber,
			const FString _competencydescription,
			const int32 _competencydescriptionformat,
			const int32 _competencysortorder,
			const int32 _competencyparentid,
			const FString _competencypath,
			const int32 _competencyruleoutcome,
			const FString _competencyruletype,
			const FString _competencyruleconfig,
			const int32 _competencyscaleid,
			const FString _competencyscaleconfiguration,
			const int32 _competencycompetencyframeworkid,
			const int32 _competencyid,
			const int32 _competencytimecreated,
			const int32 _competencytimemodified,
			const int32 _competencyusermodified)
{
	Ucore_competency_update_competency* Node = NewObject<Ucore_competency_update_competency>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_update_competency&competency[shortname]=" + _competencyshortname + "&competency[idnumber]=" + _competencyidnumber + "&competency[description]=" + _competencydescription + "&competency[descriptionformat]=" + FString::FromInt(_competencydescriptionformat) + "&competency[sortorder]=" + FString::FromInt(_competencysortorder) + "&competency[parentid]=" + FString::FromInt(_competencyparentid) + "&competency[path]=" + _competencypath + "&competency[ruleoutcome]=" + FString::FromInt(_competencyruleoutcome) + "&competency[ruletype]=" + _competencyruletype + "&competency[ruleconfig]=" + _competencyruleconfig + "&competency[scaleid]=" + FString::FromInt(_competencyscaleid) + "&competency[scaleconfiguration]=" + _competencyscaleconfiguration + "&competency[competencyframeworkid]=" + FString::FromInt(_competencycompetencyframeworkid) + "&competency[id]=" + FString::FromInt(_competencyid) + "&competency[timecreated]=" + FString::FromInt(_competencytimecreated) + "&competency[timemodified]=" + FString::FromInt(_competencytimemodified) + "&competency[usermodified]=" + FString::FromInt(_competencyusermodified);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_update_competency::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_update_competency::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_update_competency::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_update_competency_framework* Ucore_competency_update_competency_framework::core_competency_update_competency_framework(
			const FString ServerURL,
			const FString Token,
			const FString _competencyframeworkshortname,
			const FString _competencyframeworkidnumber,
			const FString _competencyframeworkdescription,
			const int32 _competencyframeworkdescriptionformat,
			const int32 _competencyframeworkvisible,
			const int32 _competencyframeworkscaleid,
			const FString _competencyframeworkscaleconfiguration,
			const int32 _competencyframeworkcontextid,
			const FString _competencyframeworkcontextlevel,
			const int32 _competencyframeworkinstanceid,
			const FString _competencyframeworktaxonomies,
			const int32 _competencyframeworkid,
			const int32 _competencyframeworktimecreated,
			const int32 _competencyframeworktimemodified,
			const int32 _competencyframeworkusermodified)
{
	Ucore_competency_update_competency_framework* Node = NewObject<Ucore_competency_update_competency_framework>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_update_competency_framework&competencyframework[shortname]=" + _competencyframeworkshortname + "&competencyframework[idnumber]=" + _competencyframeworkidnumber + "&competencyframework[description]=" + _competencyframeworkdescription + "&competencyframework[descriptionformat]=" + FString::FromInt(_competencyframeworkdescriptionformat) + "&competencyframework[visible]=" + FString::FromInt(_competencyframeworkvisible) + "&competencyframework[scaleid]=" + FString::FromInt(_competencyframeworkscaleid) + "&competencyframework[scaleconfiguration]=" + _competencyframeworkscaleconfiguration + "&competencyframework[contextid]=" + FString::FromInt(_competencyframeworkcontextid) + "&competencyframework[contextlevel]=" + _competencyframeworkcontextlevel + "&competencyframework[instanceid]=" + FString::FromInt(_competencyframeworkinstanceid) + "&competencyframework[taxonomies]=" + _competencyframeworktaxonomies + "&competencyframework[id]=" + FString::FromInt(_competencyframeworkid) + "&competencyframework[timecreated]=" + FString::FromInt(_competencyframeworktimecreated) + "&competencyframework[timemodified]=" + FString::FromInt(_competencyframeworktimemodified) + "&competencyframework[usermodified]=" + FString::FromInt(_competencyframeworkusermodified);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_update_competency_framework::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_update_competency_framework::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_update_competency_framework::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_update_course_competency_settings* Ucore_competency_update_course_competency_settings::core_competency_update_course_competency_settings(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _settingspushratingstouserplans)
{
	Ucore_competency_update_course_competency_settings* Node = NewObject<Ucore_competency_update_course_competency_settings>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_update_course_competency_settings&courseid=" + FString::FromInt(_courseid) + "&settings[pushratingstouserplans]=" + FString::FromInt(_settingspushratingstouserplans);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_update_course_competency_settings::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_update_course_competency_settings::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_update_course_competency_settings::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_update_plan* Ucore_competency_update_plan::core_competency_update_plan(
			const FString ServerURL,
			const FString Token,
			const FString _planname,
			const FString _plandescription,
			const int32 _plandescriptionformat,
			const int32 _planuserid,
			const int32 _plantemplateid,
			const int32 _planorigtemplateid,
			const int32 _planstatus,
			const int32 _planduedate,
			const int32 _planreviewerid,
			const int32 _planid,
			const int32 _plantimecreated,
			const int32 _plantimemodified,
			const int32 _planusermodified)
{
	Ucore_competency_update_plan* Node = NewObject<Ucore_competency_update_plan>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_update_plan&plan[name]=" + _planname + "&plan[description]=" + _plandescription + "&plan[descriptionformat]=" + FString::FromInt(_plandescriptionformat) + "&plan[userid]=" + FString::FromInt(_planuserid) + "&plan[templateid]=" + FString::FromInt(_plantemplateid) + "&plan[origtemplateid]=" + FString::FromInt(_planorigtemplateid) + "&plan[status]=" + FString::FromInt(_planstatus) + "&plan[duedate]=" + FString::FromInt(_planduedate) + "&plan[reviewerid]=" + FString::FromInt(_planreviewerid) + "&plan[id]=" + FString::FromInt(_planid) + "&plan[timecreated]=" + FString::FromInt(_plantimecreated) + "&plan[timemodified]=" + FString::FromInt(_plantimemodified) + "&plan[usermodified]=" + FString::FromInt(_planusermodified);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_update_plan::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_update_plan::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_update_plan::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_update_template* Ucore_competency_update_template::core_competency_update_template(
			const FString ServerURL,
			const FString Token,
			const FString _templateshortname,
			const FString _templatedescription,
			const int32 _templatedescriptionformat,
			const int32 _templateduedate,
			const int32 _templatevisible,
			const int32 _templatecontextid,
			const FString _templatecontextlevel,
			const int32 _templateinstanceid,
			const int32 _templateid,
			const int32 _templatetimecreated,
			const int32 _templatetimemodified,
			const int32 _templateusermodified)
{
	Ucore_competency_update_template* Node = NewObject<Ucore_competency_update_template>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_update_template&template[shortname]=" + _templateshortname + "&template[description]=" + _templatedescription + "&template[descriptionformat]=" + FString::FromInt(_templatedescriptionformat) + "&template[duedate]=" + FString::FromInt(_templateduedate) + "&template[visible]=" + FString::FromInt(_templatevisible) + "&template[contextid]=" + FString::FromInt(_templatecontextid) + "&template[contextlevel]=" + _templatecontextlevel + "&template[instanceid]=" + FString::FromInt(_templateinstanceid) + "&template[id]=" + FString::FromInt(_templateid) + "&template[timecreated]=" + FString::FromInt(_templatetimecreated) + "&template[timemodified]=" + FString::FromInt(_templatetimemodified) + "&template[usermodified]=" + FString::FromInt(_templateusermodified);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_update_template::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_update_template::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_update_template::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_user_competency_cancel_review_request* Ucore_competency_user_competency_cancel_review_request::core_competency_user_competency_cancel_review_request(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _competencyid)
{
	Ucore_competency_user_competency_cancel_review_request* Node = NewObject<Ucore_competency_user_competency_cancel_review_request>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_user_competency_cancel_review_request&userid=" + FString::FromInt(_userid) + "&competencyid=" + FString::FromInt(_competencyid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_user_competency_cancel_review_request::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_user_competency_cancel_review_request::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_user_competency_cancel_review_request::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_user_competency_plan_viewed* Ucore_competency_user_competency_plan_viewed::core_competency_user_competency_plan_viewed(
			const FString ServerURL,
			const FString Token,
			const int32 _competencyid,
			const int32 _userid,
			const int32 _planid)
{
	Ucore_competency_user_competency_plan_viewed* Node = NewObject<Ucore_competency_user_competency_plan_viewed>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_user_competency_plan_viewed&competencyid=" + FString::FromInt(_competencyid) + "&userid=" + FString::FromInt(_userid) + "&planid=" + FString::FromInt(_planid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_user_competency_plan_viewed::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_user_competency_plan_viewed::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_user_competency_plan_viewed::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_user_competency_request_review* Ucore_competency_user_competency_request_review::core_competency_user_competency_request_review(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _competencyid)
{
	Ucore_competency_user_competency_request_review* Node = NewObject<Ucore_competency_user_competency_request_review>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_user_competency_request_review&userid=" + FString::FromInt(_userid) + "&competencyid=" + FString::FromInt(_competencyid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_user_competency_request_review::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_user_competency_request_review::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_user_competency_request_review::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_user_competency_start_review* Ucore_competency_user_competency_start_review::core_competency_user_competency_start_review(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _competencyid)
{
	Ucore_competency_user_competency_start_review* Node = NewObject<Ucore_competency_user_competency_start_review>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_user_competency_start_review&userid=" + FString::FromInt(_userid) + "&competencyid=" + FString::FromInt(_competencyid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_user_competency_start_review::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_user_competency_start_review::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_user_competency_start_review::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_user_competency_stop_review* Ucore_competency_user_competency_stop_review::core_competency_user_competency_stop_review(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _competencyid)
{
	Ucore_competency_user_competency_stop_review* Node = NewObject<Ucore_competency_user_competency_stop_review>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_user_competency_stop_review&userid=" + FString::FromInt(_userid) + "&competencyid=" + FString::FromInt(_competencyid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_user_competency_stop_review::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_user_competency_stop_review::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_user_competency_stop_review::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_user_competency_viewed* Ucore_competency_user_competency_viewed::core_competency_user_competency_viewed(
			const FString ServerURL,
			const FString Token,
			const int32 _usercompetencyid)
{
	Ucore_competency_user_competency_viewed* Node = NewObject<Ucore_competency_user_competency_viewed>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_user_competency_viewed&usercompetencyid=" + FString::FromInt(_usercompetencyid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_user_competency_viewed::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_user_competency_viewed::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_user_competency_viewed::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_user_competency_viewed_in_course* Ucore_competency_user_competency_viewed_in_course::core_competency_user_competency_viewed_in_course(
			const FString ServerURL,
			const FString Token,
			const int32 _competencyid,
			const int32 _userid,
			const int32 _courseid)
{
	Ucore_competency_user_competency_viewed_in_course* Node = NewObject<Ucore_competency_user_competency_viewed_in_course>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_user_competency_viewed_in_course&competencyid=" + FString::FromInt(_competencyid) + "&userid=" + FString::FromInt(_userid) + "&courseid=" + FString::FromInt(_courseid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_user_competency_viewed_in_course::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_user_competency_viewed_in_course::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_user_competency_viewed_in_course::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_competency_user_competency_viewed_in_plan* Ucore_competency_user_competency_viewed_in_plan::core_competency_user_competency_viewed_in_plan(
			const FString ServerURL,
			const FString Token,
			const int32 _competencyid,
			const int32 _userid,
			const int32 _planid)
{
	Ucore_competency_user_competency_viewed_in_plan* Node = NewObject<Ucore_competency_user_competency_viewed_in_plan>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_competency_user_competency_viewed_in_plan&competencyid=" + FString::FromInt(_competencyid) + "&userid=" + FString::FromInt(_userid) + "&planid=" + FString::FromInt(_planid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_competency_user_competency_viewed_in_plan::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_competency_user_competency_viewed_in_plan::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_competency_user_competency_viewed_in_plan::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_completion_get_activities_completion_status* Ucore_completion_get_activities_completion_status::core_completion_get_activities_completion_status(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _userid)
{
	Ucore_completion_get_activities_completion_status* Node = NewObject<Ucore_completion_get_activities_completion_status>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_completion_get_activities_completion_status&courseid=" + FString::FromInt(_courseid) + "&userid=" + FString::FromInt(_userid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_completion_get_activities_completion_status::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_completion_get_activities_completion_status::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_completion_get_activities_completion_status::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_completion_get_course_completion_status* Ucore_completion_get_course_completion_status::core_completion_get_course_completion_status(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _userid)
{
	Ucore_completion_get_course_completion_status* Node = NewObject<Ucore_completion_get_course_completion_status>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_completion_get_course_completion_status&courseid=" + FString::FromInt(_courseid) + "&userid=" + FString::FromInt(_userid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_completion_get_course_completion_status::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_completion_get_course_completion_status::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_completion_get_course_completion_status::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_completion_mark_course_self_completed* Ucore_completion_mark_course_self_completed::core_completion_mark_course_self_completed(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid)
{
	Ucore_completion_mark_course_self_completed* Node = NewObject<Ucore_completion_mark_course_self_completed>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_completion_mark_course_self_completed&courseid=" + FString::FromInt(_courseid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_completion_mark_course_self_completed::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_completion_mark_course_self_completed::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_completion_mark_course_self_completed::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_completion_override_activity_completion_status* Ucore_completion_override_activity_completion_status::core_completion_override_activity_completion_status(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _cmid,
			const int32 _newstate)
{
	Ucore_completion_override_activity_completion_status* Node = NewObject<Ucore_completion_override_activity_completion_status>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_completion_override_activity_completion_status&userid=" + FString::FromInt(_userid) + "&cmid=" + FString::FromInt(_cmid) + "&newstate=" + FString::FromInt(_newstate);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_completion_override_activity_completion_status::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_completion_override_activity_completion_status::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_completion_override_activity_completion_status::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_completion_update_activity_completion_status_manually* Ucore_completion_update_activity_completion_status_manually::core_completion_update_activity_completion_status_manually(
			const FString ServerURL,
			const FString Token,
			const int32 _cmid,
			const int32 _completed)
{
	Ucore_completion_update_activity_completion_status_manually* Node = NewObject<Ucore_completion_update_activity_completion_status_manually>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_completion_update_activity_completion_status_manually&cmid=" + FString::FromInt(_cmid) + "&completed=" + FString::FromInt(_completed);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_completion_update_activity_completion_status_manually::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_completion_update_activity_completion_status_manually::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_completion_update_activity_completion_status_manually::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_contentbank_delete_content* Ucore_contentbank_delete_content::core_contentbank_delete_content(
			const FString ServerURL,
			const FString Token,
			const int32 _contentids)
{
	Ucore_contentbank_delete_content* Node = NewObject<Ucore_contentbank_delete_content>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_contentbank_delete_content&contentids[0]=" + FString::FromInt(_contentids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_contentbank_delete_content::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_contentbank_delete_content::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_contentbank_delete_content::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_contentbank_rename_content* Ucore_contentbank_rename_content::core_contentbank_rename_content(
			const FString ServerURL,
			const FString Token,
			const int32 _contentid,
			const FString _name)
{
	Ucore_contentbank_rename_content* Node = NewObject<Ucore_contentbank_rename_content>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_contentbank_rename_content&contentid=" + FString::FromInt(_contentid) + "&name=" + _name;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_contentbank_rename_content::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_contentbank_rename_content::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_contentbank_rename_content::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_contentbank_set_content_visibility* Ucore_contentbank_set_content_visibility::core_contentbank_set_content_visibility(
			const FString ServerURL,
			const FString Token,
			const int32 _contentid,
			const int32 _visibility)
{
	Ucore_contentbank_set_content_visibility* Node = NewObject<Ucore_contentbank_set_content_visibility>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_contentbank_set_content_visibility&contentid=" + FString::FromInt(_contentid) + "&visibility=" + FString::FromInt(_visibility);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_contentbank_set_content_visibility::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_contentbank_set_content_visibility::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_contentbank_set_content_visibility::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_course_add_content_item_to_user_favourites* Ucore_course_add_content_item_to_user_favourites::core_course_add_content_item_to_user_favourites(
			const FString ServerURL,
			const FString Token,
			const FString _componentname,
			const int32 _contentitemid)
{
	Ucore_course_add_content_item_to_user_favourites* Node = NewObject<Ucore_course_add_content_item_to_user_favourites>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_course_add_content_item_to_user_favourites&componentname=" + _componentname + "&contentitemid=" + FString::FromInt(_contentitemid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_course_add_content_item_to_user_favourites::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_course_add_content_item_to_user_favourites::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_course_add_content_item_to_user_favourites::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_course_check_updates* Ucore_course_check_updates::core_course_check_updates(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const FString _tocheckcontextlevel,
			const int32 _tocheckid,
			const int32 _tochecksince,
			const FString _filter)
{
	Ucore_course_check_updates* Node = NewObject<Ucore_course_check_updates>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_course_check_updates&courseid=" + FString::FromInt(_courseid) + "&tocheck[0][contextlevel]=" + _tocheckcontextlevel + "&tocheck[0][id]=" + FString::FromInt(_tocheckid) + "&tocheck[0][since]=" + FString::FromInt(_tochecksince) + "&filter[0]=" + _filter;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_course_check_updates::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_course_check_updates::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_course_check_updates::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_course_create_categories* Ucore_course_create_categories::core_course_create_categories(
			const FString ServerURL,
			const FString Token,
			const FString _categoriesname,
			const int32 _categoriesparent,
			const FString _categoriesidnumber,
			const FString _categoriesdescription,
			const int32 _categoriesdescriptionformat,
			const FString _categoriestheme)
{
	Ucore_course_create_categories* Node = NewObject<Ucore_course_create_categories>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_course_create_categories&categories[0][name]=" + _categoriesname + "&categories[0][parent]=" + FString::FromInt(_categoriesparent) + "&categories[0][idnumber]=" + _categoriesidnumber + "&categories[0][description]=" + _categoriesdescription + "&categories[0][descriptionformat]=" + FString::FromInt(_categoriesdescriptionformat) + "&categories[0][theme]=" + _categoriestheme;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_course_create_categories::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_course_create_categories::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_course_create_categories::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_course_create_courses* Ucore_course_create_courses::core_course_create_courses(
			const FString ServerURL,
			const FString Token,
			const FString _coursesfullname,
			const FString _coursesshortname,
			const int32 _coursescategoryid,
			const FString _coursesidnumber,
			const FString _coursessummary,
			const int32 _coursessummaryformat,
			const FString _coursesformat,
			const int32 _coursesshowgrades,
			const int32 _coursesnewsitems,
			const int32 _coursesstartdate,
			const int32 _coursesenddate,
			const int32 _coursesnumsections,
			const int32 _coursesmaxbytes,
			const int32 _coursesshowreports,
			const int32 _coursesvisible,
			const int32 _courseshiddensections,
			const int32 _coursesgroupmode,
			const int32 _coursesgroupmodeforce,
			const int32 _coursesdefaultgroupingid,
			const int32 _coursesenablecompletion,
			const int32 _coursescompletionnotify,
			const FString _courseslang,
			const FString _coursesforcetheme,
			const FString _coursescourseformatoptionsname,
			const FString _coursescourseformatoptionsvalue,
			const FString _coursescustomfieldsshortname,
			const FString _coursescustomfieldsvalue)
{
	Ucore_course_create_courses* Node = NewObject<Ucore_course_create_courses>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_course_create_courses&courses[0][fullname]=" + _coursesfullname + "&courses[0][shortname]=" + _coursesshortname + "&courses[0][categoryid]=" + FString::FromInt(_coursescategoryid) + "&courses[0][idnumber]=" + _coursesidnumber + "&courses[0][summary]=" + _coursessummary + "&courses[0][summaryformat]=" + FString::FromInt(_coursessummaryformat) + "&courses[0][format]=" + _coursesformat + "&courses[0][showgrades]=" + FString::FromInt(_coursesshowgrades) + "&courses[0][newsitems]=" + FString::FromInt(_coursesnewsitems) + "&courses[0][startdate]=" + FString::FromInt(_coursesstartdate) + "&courses[0][enddate]=" + FString::FromInt(_coursesenddate) + "&courses[0][numsections]=" + FString::FromInt(_coursesnumsections) + "&courses[0][maxbytes]=" + FString::FromInt(_coursesmaxbytes) + "&courses[0][showreports]=" + FString::FromInt(_coursesshowreports) + "&courses[0][visible]=" + FString::FromInt(_coursesvisible) + "&courses[0][hiddensections]=" + FString::FromInt(_courseshiddensections) + "&courses[0][groupmode]=" + FString::FromInt(_coursesgroupmode) + "&courses[0][groupmodeforce]=" + FString::FromInt(_coursesgroupmodeforce) + "&courses[0][defaultgroupingid]=" + FString::FromInt(_coursesdefaultgroupingid) + "&courses[0][enablecompletion]=" + FString::FromInt(_coursesenablecompletion) + "&courses[0][completionnotify]=" + FString::FromInt(_coursescompletionnotify) + "&courses[0][lang]=" + _courseslang + "&courses[0][forcetheme]=" + _coursesforcetheme + "&courses[0][courseformatoptions][0][name]=" + _coursescourseformatoptionsname + "&courses[0][courseformatoptions][0][value]=" + _coursescourseformatoptionsvalue + "&courses[0][customfields][0][shortname]=" + _coursescustomfieldsshortname + "&courses[0][customfields][0][value]=" + _coursescustomfieldsvalue;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_course_create_courses::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_course_create_courses::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_course_create_courses::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_course_delete_categories* Ucore_course_delete_categories::core_course_delete_categories(
			const FString ServerURL,
			const FString Token,
			const int32 _categoriesid,
			const int32 _categoriesnewparent,
			const int32 _categoriesrecursive)
{
	Ucore_course_delete_categories* Node = NewObject<Ucore_course_delete_categories>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_course_delete_categories&categories[0][id]=" + FString::FromInt(_categoriesid) + "&categories[0][newparent]=" + FString::FromInt(_categoriesnewparent) + "&categories[0][recursive]=" + FString::FromInt(_categoriesrecursive);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_course_delete_categories::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_course_delete_categories::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_course_delete_categories::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_course_delete_courses* Ucore_course_delete_courses::core_course_delete_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids)
{
	Ucore_course_delete_courses* Node = NewObject<Ucore_course_delete_courses>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_course_delete_courses&courseids[0]=" + FString::FromInt(_courseids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_course_delete_courses::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_course_delete_courses::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_course_delete_courses::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_course_delete_modules* Ucore_course_delete_modules::core_course_delete_modules(
			const FString ServerURL,
			const FString Token,
			const int32 _cmids)
{
	Ucore_course_delete_modules* Node = NewObject<Ucore_course_delete_modules>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_course_delete_modules&cmids[0]=" + FString::FromInt(_cmids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_course_delete_modules::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_course_delete_modules::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_course_delete_modules::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_course_duplicate_course* Ucore_course_duplicate_course::core_course_duplicate_course(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const FString _fullname,
			const FString _shortname,
			const int32 _categoryid,
			const FString _optionsname,
			const FString _optionsvalue,
			const int32 _visible)
{
	Ucore_course_duplicate_course* Node = NewObject<Ucore_course_duplicate_course>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_course_duplicate_course&courseid=" + FString::FromInt(_courseid) + "&fullname=" + _fullname + "&shortname=" + _shortname + "&categoryid=" + FString::FromInt(_categoryid) + "&visible=" + FString::FromInt(_visible) + "&options[0][name]=" + _optionsname + "&options[0][value]=" + _optionsvalue;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_course_duplicate_course::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_course_duplicate_course::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_course_duplicate_course::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_course_edit_module* Ucore_course_edit_module::core_course_edit_module(
			const FString ServerURL,
			const FString Token,
			const FString _action,
			const int32 _id,
			const int32 _sectionreturn)
{
	Ucore_course_edit_module* Node = NewObject<Ucore_course_edit_module>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_course_edit_module&action=" + _action + "&id=" + FString::FromInt(_id) + "&sectionreturn=" + FString::FromInt(_sectionreturn);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_course_edit_module::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_course_edit_module::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_course_edit_module::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_course_edit_section* Ucore_course_edit_section::core_course_edit_section(
			const FString ServerURL,
			const FString Token,
			const FString _action,
			const int32 _id,
			const int32 _sectionreturn)
{
	Ucore_course_edit_section* Node = NewObject<Ucore_course_edit_section>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_course_edit_section&action=" + _action + "&id=" + FString::FromInt(_id) + "&sectionreturn=" + FString::FromInt(_sectionreturn);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_course_edit_section::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_course_edit_section::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_course_edit_section::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_course_get_activity_chooser_footer* Ucore_course_get_activity_chooser_footer::core_course_get_activity_chooser_footer(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _sectionid)
{
	Ucore_course_get_activity_chooser_footer* Node = NewObject<Ucore_course_get_activity_chooser_footer>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_course_get_activity_chooser_footer&courseid=" + FString::FromInt(_courseid) + "&sectionid=" + FString::FromInt(_sectionid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_course_get_activity_chooser_footer::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_course_get_activity_chooser_footer::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_course_get_activity_chooser_footer::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_course_get_categories* Ucore_course_get_categories::core_course_get_categories(
			const FString ServerURL,
			const FString Token,
			const FString _criteriakey,
			const FString _criteriavalue,
			const int32 _addsubcategories)
{
	Ucore_course_get_categories* Node = NewObject<Ucore_course_get_categories>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_course_get_categories&criteria[0][key]=" + _criteriakey + "&criteria[0][value]=" + _criteriavalue + "&addsubcategories=" + FString::FromInt(_addsubcategories);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_course_get_categories::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_course_get_categories::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_course_get_categories::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_course_get_contents* Ucore_course_get_contents::core_course_get_contents(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const FString _optionsname,
			const FString _optionsvalue)
{
	Ucore_course_get_contents* Node = NewObject<Ucore_course_get_contents>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_course_get_contents&courseid=" + FString::FromInt(_courseid) + "&options[0][name]=" + _optionsname + "&options[0][value]=" + _optionsvalue;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_course_get_contents::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_course_get_contents::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_course_get_contents::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_course_get_course_content_items* Ucore_course_get_course_content_items::core_course_get_course_content_items(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid)
{
	Ucore_course_get_course_content_items* Node = NewObject<Ucore_course_get_course_content_items>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_course_get_course_content_items&courseid=" + FString::FromInt(_courseid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_course_get_course_content_items::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_course_get_course_content_items::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_course_get_course_content_items::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_course_get_course_module* Ucore_course_get_course_module::core_course_get_course_module(
			const FString ServerURL,
			const FString Token,
			const int32 _cmid)
{
	Ucore_course_get_course_module* Node = NewObject<Ucore_course_get_course_module>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_course_get_course_module&cmid=" + FString::FromInt(_cmid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_course_get_course_module::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_course_get_course_module::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_course_get_course_module::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_course_get_course_module_by_instance* Ucore_course_get_course_module_by_instance::core_course_get_course_module_by_instance(
			const FString ServerURL,
			const FString Token,
			const FString _module,
			const int32 _instance)
{
	Ucore_course_get_course_module_by_instance* Node = NewObject<Ucore_course_get_course_module_by_instance>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_course_get_course_module_by_instance&module=" + _module + "&instance=" + FString::FromInt(_instance);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_course_get_course_module_by_instance::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_course_get_course_module_by_instance::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_course_get_course_module_by_instance::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_course_get_courses* Ucore_course_get_courses::core_course_get_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _optionsids)
{
	Ucore_course_get_courses* Node = NewObject<Ucore_course_get_courses>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_course_get_courses&options[ids][0]=" + FString::FromInt(_optionsids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_course_get_courses::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_course_get_courses::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_course_get_courses::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_course_get_courses_by_field* Ucore_course_get_courses_by_field::core_course_get_courses_by_field(
			const FString ServerURL,
			const FString Token,
			const FString _field,
			const FString _value)
{
	Ucore_course_get_courses_by_field* Node = NewObject<Ucore_course_get_courses_by_field>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_course_get_courses_by_field&field=" + _field + "&value=" + _value;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_course_get_courses_by_field::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_course_get_courses_by_field::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_course_get_courses_by_field::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_course_get_enrolled_courses_by_timeline_classification* Ucore_course_get_enrolled_courses_by_timeline_classification::core_course_get_enrolled_courses_by_timeline_classification(
			const FString ServerURL,
			const FString Token,
			const FString _classification,
			const int32 _limit,
			const int32 _offset,
			const FString _sort,
			const FString _customfieldname,
			const FString _customfieldvalue,
			const FString _searchvalue)
{
	Ucore_course_get_enrolled_courses_by_timeline_classification* Node = NewObject<Ucore_course_get_enrolled_courses_by_timeline_classification>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_course_get_enrolled_courses_by_timeline_classification&classification=" + _classification + "&limit=" + FString::FromInt(_limit) + "&offset=" + FString::FromInt(_offset) + "&sort=" + _sort + "&customfieldname=" + _customfieldname + "&customfieldvalue=" + _customfieldvalue + "&searchvalue=" + _searchvalue;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_course_get_enrolled_courses_by_timeline_classification::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_course_get_enrolled_courses_by_timeline_classification::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_course_get_enrolled_courses_by_timeline_classification::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_course_get_enrolled_courses_with_action_events_by_timeline_classification* Ucore_course_get_enrolled_courses_with_action_events_by_timeline_classification::core_course_get_enrolled_courses_with_action_events_by_timeline_classification(
			const FString ServerURL,
			const FString Token,
			const FString _classification,
			const int32 _limit,
			const int32 _offset,
			const FString _sort,
			const FString _customfieldname,
			const FString _customfieldvalue,
			const FString _searchvalue,
			const int32 _eventsfrom,
			const int32 _eventsto)
{
	Ucore_course_get_enrolled_courses_with_action_events_by_timeline_classification* Node = NewObject<Ucore_course_get_enrolled_courses_with_action_events_by_timeline_classification>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_course_get_enrolled_courses_with_action_events_by_timeline_classification&classification=" + _classification + "&limit=" + FString::FromInt(_limit) + "&offset=" + FString::FromInt(_offset) + "&sort=" + _sort + "&customfieldname=" + _customfieldname + "&customfieldvalue=" + _customfieldvalue + "&searchvalue=" + _searchvalue + "&eventsfrom=" + FString::FromInt(_eventsfrom) + "&eventsto=" + FString::FromInt(_eventsto);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_course_get_enrolled_courses_with_action_events_by_timeline_classification::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_course_get_enrolled_courses_with_action_events_by_timeline_classification::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_course_get_enrolled_courses_with_action_events_by_timeline_classification::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_course_get_enrolled_users_by_cmid* Ucore_course_get_enrolled_users_by_cmid::core_course_get_enrolled_users_by_cmid(
			const FString ServerURL,
			const FString Token,
			const int32 _cmid,
			const int32 _groupid,
			const int32 _onlyactive)
{
	Ucore_course_get_enrolled_users_by_cmid* Node = NewObject<Ucore_course_get_enrolled_users_by_cmid>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_course_get_enrolled_users_by_cmid&cmid=" + FString::FromInt(_cmid) + "&groupid=" + FString::FromInt(_groupid) + "&onlyactive=" + FString::FromInt(_onlyactive);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_course_get_enrolled_users_by_cmid::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_course_get_enrolled_users_by_cmid::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_course_get_enrolled_users_by_cmid::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_course_get_module* Ucore_course_get_module::core_course_get_module(
			const FString ServerURL,
			const FString Token,
			const int32 _id,
			const int32 _sectionreturn)
{
	Ucore_course_get_module* Node = NewObject<Ucore_course_get_module>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_course_get_module&id=" + FString::FromInt(_id) + "&sectionreturn=" + FString::FromInt(_sectionreturn);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_course_get_module::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_course_get_module::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_course_get_module::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_course_get_recent_courses* Ucore_course_get_recent_courses::core_course_get_recent_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _limit,
			const int32 _offset,
			const FString _sort)
{
	Ucore_course_get_recent_courses* Node = NewObject<Ucore_course_get_recent_courses>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_course_get_recent_courses&userid=" + FString::FromInt(_userid) + "&limit=" + FString::FromInt(_limit) + "&offset=" + FString::FromInt(_offset) + "&sort=" + _sort;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_course_get_recent_courses::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_course_get_recent_courses::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_course_get_recent_courses::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_course_get_updates_since* Ucore_course_get_updates_since::core_course_get_updates_since(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _since,
			const FString _filter)
{
	Ucore_course_get_updates_since* Node = NewObject<Ucore_course_get_updates_since>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_course_get_updates_since&courseid=" + FString::FromInt(_courseid) + "&since=" + FString::FromInt(_since) + "&filter[0]=" + _filter;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_course_get_updates_since::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_course_get_updates_since::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_course_get_updates_since::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_course_get_user_administration_options* Ucore_course_get_user_administration_options::core_course_get_user_administration_options(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids)
{
	Ucore_course_get_user_administration_options* Node = NewObject<Ucore_course_get_user_administration_options>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_course_get_user_administration_options&courseids[0]=" + FString::FromInt(_courseids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_course_get_user_administration_options::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_course_get_user_administration_options::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_course_get_user_administration_options::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_course_get_user_navigation_options* Ucore_course_get_user_navigation_options::core_course_get_user_navigation_options(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids)
{
	Ucore_course_get_user_navigation_options* Node = NewObject<Ucore_course_get_user_navigation_options>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_course_get_user_navigation_options&courseids[0]=" + FString::FromInt(_courseids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_course_get_user_navigation_options::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_course_get_user_navigation_options::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_course_get_user_navigation_options::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_course_import_course* Ucore_course_import_course::core_course_import_course(
			const FString ServerURL,
			const FString Token,
			const int32 _importfrom,
			const int32 _importto,
			const FString _optionsname,
			const FString _optionsvalue,
			const int32 _deletecontent)
{
	Ucore_course_import_course* Node = NewObject<Ucore_course_import_course>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_course_import_course&importfrom=" + FString::FromInt(_importfrom) + "&importto=" + FString::FromInt(_importto) + "&deletecontent=" + FString::FromInt(_deletecontent) + "&options[0][name]=" + _optionsname + "&options[0][value]=" + _optionsvalue;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_course_import_course::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_course_import_course::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_course_import_course::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_course_remove_content_item_from_user_favourites* Ucore_course_remove_content_item_from_user_favourites::core_course_remove_content_item_from_user_favourites(
			const FString ServerURL,
			const FString Token,
			const FString _componentname,
			const int32 _contentitemid)
{
	Ucore_course_remove_content_item_from_user_favourites* Node = NewObject<Ucore_course_remove_content_item_from_user_favourites>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_course_remove_content_item_from_user_favourites&componentname=" + _componentname + "&contentitemid=" + FString::FromInt(_contentitemid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_course_remove_content_item_from_user_favourites::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_course_remove_content_item_from_user_favourites::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_course_remove_content_item_from_user_favourites::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_course_search_courses* Ucore_course_search_courses::core_course_search_courses(
			const FString ServerURL,
			const FString Token,
			const FString _criterianame,
			const FString _criteriavalue,
			const int32 _page,
			const int32 _perpage,
			const FString _requiredcapabilities,
			const int32 _limittoenrolled,
			const int32 _onlywithcompletion)
{
	Ucore_course_search_courses* Node = NewObject<Ucore_course_search_courses>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_course_search_courses&criterianame=" + _criterianame + "&criteriavalue=" + _criteriavalue + "&page=" + FString::FromInt(_page) + "&perpage=" + FString::FromInt(_perpage) + "&requiredcapabilities[0]=" + _requiredcapabilities + "&limittoenrolled=" + FString::FromInt(_limittoenrolled) + "&onlywithcompletion=" + FString::FromInt(_onlywithcompletion);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_course_search_courses::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_course_search_courses::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_course_search_courses::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_course_set_favourite_courses* Ucore_course_set_favourite_courses::core_course_set_favourite_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _coursesid,
			const int32 _coursesfavourite)
{
	Ucore_course_set_favourite_courses* Node = NewObject<Ucore_course_set_favourite_courses>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_course_set_favourite_courses&courses[0][id]=" + FString::FromInt(_coursesid) + "&courses[0][favourite]=" + FString::FromInt(_coursesfavourite);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_course_set_favourite_courses::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_course_set_favourite_courses::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_course_set_favourite_courses::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_course_toggle_activity_recommendation* Ucore_course_toggle_activity_recommendation::core_course_toggle_activity_recommendation(
			const FString ServerURL,
			const FString Token,
			const FString _area,
			const int32 _id)
{
	Ucore_course_toggle_activity_recommendation* Node = NewObject<Ucore_course_toggle_activity_recommendation>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_course_toggle_activity_recommendation&area=" + _area + "&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_course_toggle_activity_recommendation::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_course_toggle_activity_recommendation::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_course_toggle_activity_recommendation::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_course_update_categories* Ucore_course_update_categories::core_course_update_categories(
			const FString ServerURL,
			const FString Token,
			const int32 _categoriesid,
			const FString _categoriesname,
			const FString _categoriesidnumber,
			const int32 _categoriesparent,
			const FString _categoriesdescription,
			const int32 _categoriesdescriptionformat,
			const FString _categoriestheme)
{
	Ucore_course_update_categories* Node = NewObject<Ucore_course_update_categories>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_course_update_categories&categories[0][id]=" + FString::FromInt(_categoriesid) + "&categories[0][name]=" + _categoriesname + "&categories[0][idnumber]=" + _categoriesidnumber + "&categories[0][parent]=" + FString::FromInt(_categoriesparent) + "&categories[0][description]=" + _categoriesdescription + "&categories[0][descriptionformat]=" + FString::FromInt(_categoriesdescriptionformat) + "&categories[0][theme]=" + _categoriestheme;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_course_update_categories::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_course_update_categories::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_course_update_categories::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_course_update_courses* Ucore_course_update_courses::core_course_update_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _coursesid,
			const FString _coursesfullname,
			const FString _coursesshortname,
			const int32 _coursescategoryid,
			const FString _coursesidnumber,
			const FString _coursessummary,
			const int32 _coursessummaryformat,
			const FString _coursesformat,
			const int32 _coursesshowgrades,
			const int32 _coursesnewsitems,
			const int32 _coursesstartdate,
			const int32 _coursesenddate,
			const int32 _coursesnumsections,
			const int32 _coursesmaxbytes,
			const int32 _coursesshowreports,
			const int32 _coursesvisible,
			const int32 _courseshiddensections,
			const int32 _coursesgroupmode,
			const int32 _coursesgroupmodeforce,
			const int32 _coursesdefaultgroupingid,
			const int32 _coursesenablecompletion,
			const int32 _coursescompletionnotify,
			const FString _courseslang,
			const FString _coursesforcetheme,
			const FString _coursescourseformatoptionsname,
			const FString _coursescourseformatoptionsvalue,
			const FString _coursescustomfieldsshortname,
			const FString _coursescustomfieldsvalue)
{
	Ucore_course_update_courses* Node = NewObject<Ucore_course_update_courses>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_course_update_courses&courses[0][id]=" + FString::FromInt(_coursesid) + "&courses[0][fullname]=" + _coursesfullname + "&courses[0][shortname]=" + _coursesshortname + "&courses[0][categoryid]=" + FString::FromInt(_coursescategoryid) + "&courses[0][idnumber]=" + _coursesidnumber + "&courses[0][summary]=" + _coursessummary + "&courses[0][summaryformat]=" + FString::FromInt(_coursessummaryformat) + "&courses[0][format]=" + _coursesformat + "&courses[0][showgrades]=" + FString::FromInt(_coursesshowgrades) + "&courses[0][newsitems]=" + FString::FromInt(_coursesnewsitems) + "&courses[0][startdate]=" + FString::FromInt(_coursesstartdate) + "&courses[0][enddate]=" + FString::FromInt(_coursesenddate) + "&courses[0][numsections]=" + FString::FromInt(_coursesnumsections) + "&courses[0][maxbytes]=" + FString::FromInt(_coursesmaxbytes) + "&courses[0][showreports]=" + FString::FromInt(_coursesshowreports) + "&courses[0][visible]=" + FString::FromInt(_coursesvisible) + "&courses[0][hiddensections]=" + FString::FromInt(_courseshiddensections) + "&courses[0][groupmode]=" + FString::FromInt(_coursesgroupmode) + "&courses[0][groupmodeforce]=" + FString::FromInt(_coursesgroupmodeforce) + "&courses[0][defaultgroupingid]=" + FString::FromInt(_coursesdefaultgroupingid) + "&courses[0][enablecompletion]=" + FString::FromInt(_coursesenablecompletion) + "&courses[0][completionnotify]=" + FString::FromInt(_coursescompletionnotify) + "&courses[0][lang]=" + _courseslang + "&courses[0][forcetheme]=" + _coursesforcetheme + "&courses[0][courseformatoptions][0][name]=" + _coursescourseformatoptionsname + "&courses[0][courseformatoptions][0][value]=" + _coursescourseformatoptionsvalue + "&courses[0][customfields][0][shortname]=" + _coursescustomfieldsshortname + "&courses[0][customfields][0][value]=" + _coursescustomfieldsvalue;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_course_update_courses::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_course_update_courses::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_course_update_courses::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_course_view_course* Ucore_course_view_course::core_course_view_course(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _sectionnumber)
{
	Ucore_course_view_course* Node = NewObject<Ucore_course_view_course>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_course_view_course&courseid=" + FString::FromInt(_courseid) + "&sectionnumber=" + FString::FromInt(_sectionnumber);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_course_view_course::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_course_view_course::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_course_view_course::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_courseformat_get_state* Ucore_courseformat_get_state::core_courseformat_get_state(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid)
{
	Ucore_courseformat_get_state* Node = NewObject<Ucore_courseformat_get_state>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_courseformat_get_state&courseid=" + FString::FromInt(_courseid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_courseformat_get_state::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_courseformat_get_state::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_courseformat_get_state::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_courseformat_update_course* Ucore_courseformat_update_course::core_courseformat_update_course(
			const FString ServerURL,
			const FString Token,
			const FString _action,
			const int32 _courseid,
			const int32 _ids,
			const int32 _targetsectionid,
			const int32 _targetcmid)
{
	Ucore_courseformat_update_course* Node = NewObject<Ucore_courseformat_update_course>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_courseformat_update_course&action=" + _action + "&courseid=" + FString::FromInt(_courseid) + "&ids[0]=" + FString::FromInt(_ids) + "&targetsectionid=" + FString::FromInt(_targetsectionid) + "&targetcmid=" + FString::FromInt(_targetcmid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_courseformat_update_course::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_courseformat_update_course::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_courseformat_update_course::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_create_userfeedback_action_record* Ucore_create_userfeedback_action_record::core_create_userfeedback_action_record(
			const FString ServerURL,
			const FString Token,
			const FString _action,
			const int32 _contextid)
{
	Ucore_create_userfeedback_action_record* Node = NewObject<Ucore_create_userfeedback_action_record>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_create_userfeedback_action_record&action=" + _action + "&contextid=" + FString::FromInt(_contextid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_create_userfeedback_action_record::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_create_userfeedback_action_record::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_create_userfeedback_action_record::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_customfield_create_category* Ucore_customfield_create_category::core_customfield_create_category(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const FString _area,
			const int32 _itemid)
{
	Ucore_customfield_create_category* Node = NewObject<Ucore_customfield_create_category>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_customfield_create_category&component=" + _component + "&area=" + _area + "&itemid=" + FString::FromInt(_itemid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_customfield_create_category::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_customfield_create_category::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_customfield_create_category::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_customfield_delete_category* Ucore_customfield_delete_category::core_customfield_delete_category(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Ucore_customfield_delete_category* Node = NewObject<Ucore_customfield_delete_category>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_customfield_delete_category&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_customfield_delete_category::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_customfield_delete_category::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_customfield_delete_category::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_customfield_delete_field* Ucore_customfield_delete_field::core_customfield_delete_field(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Ucore_customfield_delete_field* Node = NewObject<Ucore_customfield_delete_field>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_customfield_delete_field&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_customfield_delete_field::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_customfield_delete_field::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_customfield_delete_field::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_customfield_move_category* Ucore_customfield_move_category::core_customfield_move_category(
			const FString ServerURL,
			const FString Token,
			const int32 _id,
			const int32 _beforeid)
{
	Ucore_customfield_move_category* Node = NewObject<Ucore_customfield_move_category>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_customfield_move_category&id=" + FString::FromInt(_id) + "&beforeid=" + FString::FromInt(_beforeid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_customfield_move_category::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_customfield_move_category::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_customfield_move_category::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_customfield_move_field* Ucore_customfield_move_field::core_customfield_move_field(
			const FString ServerURL,
			const FString Token,
			const int32 _id,
			const int32 _categoryid,
			const int32 _beforeid)
{
	Ucore_customfield_move_field* Node = NewObject<Ucore_customfield_move_field>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_customfield_move_field&id=" + FString::FromInt(_id) + "&categoryid=" + FString::FromInt(_categoryid) + "&beforeid=" + FString::FromInt(_beforeid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_customfield_move_field::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_customfield_move_field::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_customfield_move_field::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_customfield_reload_template* Ucore_customfield_reload_template::core_customfield_reload_template(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const FString _area,
			const int32 _itemid)
{
	Ucore_customfield_reload_template* Node = NewObject<Ucore_customfield_reload_template>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_customfield_reload_template&component=" + _component + "&area=" + _area + "&itemid=" + FString::FromInt(_itemid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_customfield_reload_template::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_customfield_reload_template::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_customfield_reload_template::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_dynamic_tabs_get_content* Ucore_dynamic_tabs_get_content::core_dynamic_tabs_get_content(
			const FString ServerURL,
			const FString Token,
			const FString _tab,
			const FString _jsondata)
{
	Ucore_dynamic_tabs_get_content* Node = NewObject<Ucore_dynamic_tabs_get_content>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_dynamic_tabs_get_content&tab=" + _tab + "&jsondata=" + _jsondata;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_dynamic_tabs_get_content::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_dynamic_tabs_get_content::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_dynamic_tabs_get_content::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_enrol_get_course_enrolment_methods* Ucore_enrol_get_course_enrolment_methods::core_enrol_get_course_enrolment_methods(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid)
{
	Ucore_enrol_get_course_enrolment_methods* Node = NewObject<Ucore_enrol_get_course_enrolment_methods>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_enrol_get_course_enrolment_methods&courseid=" + FString::FromInt(_courseid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_enrol_get_course_enrolment_methods::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_enrol_get_course_enrolment_methods::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_enrol_get_course_enrolment_methods::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_enrol_get_enrolled_users* Ucore_enrol_get_enrolled_users::core_enrol_get_enrolled_users(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const FString _optionsname,
			const FString _optionsvalue)
{
	Ucore_enrol_get_enrolled_users* Node = NewObject<Ucore_enrol_get_enrolled_users>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_enrol_get_enrolled_users&courseid=" + FString::FromInt(_courseid) + "&options[0][name]=" + _optionsname + "&options[0][value]=" + _optionsvalue;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_enrol_get_enrolled_users::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_enrol_get_enrolled_users::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_enrol_get_enrolled_users::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_enrol_get_enrolled_users_with_capability* Ucore_enrol_get_enrolled_users_with_capability::core_enrol_get_enrolled_users_with_capability(
			const FString ServerURL,
			const FString Token,
			const int32 _coursecapabilitiescourseid,
			const FString _coursecapabilitiescapabilities,
			const FString _optionsname,
			const FString _optionsvalue)
{
	Ucore_enrol_get_enrolled_users_with_capability* Node = NewObject<Ucore_enrol_get_enrolled_users_with_capability>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_enrol_get_enrolled_users_with_capability&coursecapabilities[0][courseid]=" + FString::FromInt(_coursecapabilitiescourseid) + "&coursecapabilities[0][capabilities][0]=" + _coursecapabilitiescapabilities + "&options[0][name]=" + _optionsname + "&options[0][value]=" + _optionsvalue;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_enrol_get_enrolled_users_with_capability::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_enrol_get_enrolled_users_with_capability::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_enrol_get_enrolled_users_with_capability::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_enrol_get_potential_users* Ucore_enrol_get_potential_users::core_enrol_get_potential_users(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _enrolid,
			const FString _search,
			const int32 _searchanywhere,
			const int32 _page,
			const int32 _perpage)
{
	Ucore_enrol_get_potential_users* Node = NewObject<Ucore_enrol_get_potential_users>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_enrol_get_potential_users&courseid=" + FString::FromInt(_courseid) + "&enrolid=" + FString::FromInt(_enrolid) + "&search=" + _search + "&searchanywhere=" + FString::FromInt(_searchanywhere) + "&page=" + FString::FromInt(_page) + "&perpage=" + FString::FromInt(_perpage);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_enrol_get_potential_users::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_enrol_get_potential_users::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_enrol_get_potential_users::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_enrol_get_users_courses* Ucore_enrol_get_users_courses::core_enrol_get_users_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _returnusercount)
{
	Ucore_enrol_get_users_courses* Node = NewObject<Ucore_enrol_get_users_courses>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_enrol_get_users_courses&userid=" + FString::FromInt(_userid) + "&returnusercount=" + FString::FromInt(_returnusercount);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_enrol_get_users_courses::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_enrol_get_users_courses::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_enrol_get_users_courses::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_enrol_search_users* Ucore_enrol_search_users::core_enrol_search_users(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const FString _search,
			const int32 _searchanywhere,
			const int32 _page,
			const int32 _perpage)
{
	Ucore_enrol_search_users* Node = NewObject<Ucore_enrol_search_users>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_enrol_search_users&courseid=" + FString::FromInt(_courseid) + "&search=" + _search + "&searchanywhere=" + FString::FromInt(_searchanywhere) + "&page=" + FString::FromInt(_page) + "&perpage=" + FString::FromInt(_perpage);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_enrol_search_users::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_enrol_search_users::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_enrol_search_users::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_enrol_submit_user_enrolment_form* Ucore_enrol_submit_user_enrolment_form::core_enrol_submit_user_enrolment_form(
			const FString ServerURL,
			const FString Token,
			const FString _formdata)
{
	Ucore_enrol_submit_user_enrolment_form* Node = NewObject<Ucore_enrol_submit_user_enrolment_form>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_enrol_submit_user_enrolment_form&formdata=" + _formdata;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_enrol_submit_user_enrolment_form::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_enrol_submit_user_enrolment_form::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_enrol_submit_user_enrolment_form::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_enrol_unenrol_user_enrolment* Ucore_enrol_unenrol_user_enrolment::core_enrol_unenrol_user_enrolment(
			const FString ServerURL,
			const FString Token,
			const int32 _ueid)
{
	Ucore_enrol_unenrol_user_enrolment* Node = NewObject<Ucore_enrol_unenrol_user_enrolment>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_enrol_unenrol_user_enrolment&ueid=" + FString::FromInt(_ueid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_enrol_unenrol_user_enrolment::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_enrol_unenrol_user_enrolment::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_enrol_unenrol_user_enrolment::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_fetch_notifications* Ucore_fetch_notifications::core_fetch_notifications(
			const FString ServerURL,
			const FString Token,
			const int32 _contextid)
{
	Ucore_fetch_notifications* Node = NewObject<Ucore_fetch_notifications>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_fetch_notifications&contextid=" + FString::FromInt(_contextid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_fetch_notifications::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_fetch_notifications::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_fetch_notifications::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_files_delete_draft_files* Ucore_files_delete_draft_files::core_files_delete_draft_files(
			const FString ServerURL,
			const FString Token,
			const int32 _draftitemid,
			const FString _filesfilepath,
			const FString _filesfilename)
{
	Ucore_files_delete_draft_files* Node = NewObject<Ucore_files_delete_draft_files>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_files_delete_draft_files&draftitemid=" + FString::FromInt(_draftitemid) + "&files[0][filepath]=" + _filesfilepath + "&files[0][filename]=" + _filesfilename;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_files_delete_draft_files::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_files_delete_draft_files::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_files_delete_draft_files::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_files_get_files* Ucore_files_get_files::core_files_get_files(
			const FString ServerURL,
			const FString Token,
			const int32 _contextid,
			const FString _component,
			const FString _filearea,
			const int32 _itemid,
			const FString _filepath,
			const FString _filename,
			const int32 _modified,
			const FString _contextlevel,
			const int32 _instanceid)
{
	Ucore_files_get_files* Node = NewObject<Ucore_files_get_files>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_files_get_files&contextid=" + FString::FromInt(_contextid) + "&component=" + _component + "&filearea=" + _filearea + "&itemid=" + FString::FromInt(_itemid) + "&filepath=" + _filepath + "&filename=" + _filename + "&modified=" + FString::FromInt(_modified) + "&contextlevel=" + _contextlevel + "&instanceid=" + FString::FromInt(_instanceid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_files_get_files::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_files_get_files::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_files_get_files::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_files_get_unused_draft_itemid* Ucore_files_get_unused_draft_itemid::core_files_get_unused_draft_itemid(
			const FString ServerURL,
			const FString Token)
{
	Ucore_files_get_unused_draft_itemid* Node = NewObject<Ucore_files_get_unused_draft_itemid>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_files_get_unused_draft_itemid";

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_files_get_unused_draft_itemid::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_files_get_unused_draft_itemid::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_files_get_unused_draft_itemid::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_files_upload* Ucore_files_upload::core_files_upload(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const FString _filearea,
			const int32 _itemid,
			const FString _filepath,
			const FString _filename,
			const FString _filecontent,
			const int32 _contextid,
			const FString _contextlevel,
			const int32 _instanceid)
{
	Ucore_files_upload* Node = NewObject<Ucore_files_upload>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_files_upload&contextid=" + FString::FromInt(_contextid) + "&component=" + _component + "&filearea=" + _filearea + "&itemid=" + FString::FromInt(_itemid) + "&filepath=" + _filepath + "&filename=" + _filename + "&filecontent=" + _filecontent + "&contextlevel=" + _contextlevel + "&instanceid=" + FString::FromInt(_instanceid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_files_upload::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_files_upload::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_files_upload::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_filters_get_available_in_context* Ucore_filters_get_available_in_context::core_filters_get_available_in_context(
			const FString ServerURL,
			const FString Token,
			const FString _contextscontextlevel,
			const int32 _contextsinstanceid)
{
	Ucore_filters_get_available_in_context* Node = NewObject<Ucore_filters_get_available_in_context>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_filters_get_available_in_context&contexts[0][contextlevel]=" + _contextscontextlevel + "&contexts[0][instanceid]=" + FString::FromInt(_contextsinstanceid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_filters_get_available_in_context::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_filters_get_available_in_context::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_filters_get_available_in_context::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_form_dynamic_form* Ucore_form_dynamic_form::core_form_dynamic_form(
			const FString ServerURL,
			const FString Token,
			const FString _form,
			const FString _formdata)
{
	Ucore_form_dynamic_form* Node = NewObject<Ucore_form_dynamic_form>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_form_dynamic_form&form=" + _form + "&formdata=" + _formdata;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_form_dynamic_form::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_form_dynamic_form::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_form_dynamic_form::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_form_get_filetypes_browser_data* Ucore_form_get_filetypes_browser_data::core_form_get_filetypes_browser_data(
			const FString ServerURL,
			const FString Token,
			const FString _onlytypes,
			const int32 _allowall,
			const FString _current)
{
	Ucore_form_get_filetypes_browser_data* Node = NewObject<Ucore_form_get_filetypes_browser_data>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_form_get_filetypes_browser_data&onlytypes=" + _onlytypes + "&allowall=" + FString::FromInt(_allowall) + "&current=" + _current;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_form_get_filetypes_browser_data::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_form_get_filetypes_browser_data::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_form_get_filetypes_browser_data::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_get_component_strings* Ucore_get_component_strings::core_get_component_strings(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const FString _lang)
{
	Ucore_get_component_strings* Node = NewObject<Ucore_get_component_strings>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_get_component_strings&component=" + _component + "&lang=" + _lang;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_get_component_strings::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_get_component_strings::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_get_component_strings::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_get_fragment* Ucore_get_fragment::core_get_fragment(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const int32 _contextid,
			const FString _callback,
			const FString _argsname,
			const FString _argsvalue)
{
	Ucore_get_fragment* Node = NewObject<Ucore_get_fragment>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_get_fragment&component=" + _component + "&callback=" + _callback + "&contextid=" + FString::FromInt(_contextid) + "&args[0][name]=" + _argsname + "&args[0][value]=" + _argsvalue;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_get_fragment::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_get_fragment::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_get_fragment::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_get_string* Ucore_get_string::core_get_string(
			const FString ServerURL,
			const FString Token,
			const FString _stringid,
			const FString _stringparamsvalue,
			const FString _component,
			const FString _lang,
			const FString _stringparamsname)
{
	Ucore_get_string* Node = NewObject<Ucore_get_string>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_get_string&stringid=" + _stringid + "&component=" + _component + "&lang=" + _lang + "&stringparams[0][name]=" + _stringparamsname + "&stringparams[0][value]=" + _stringparamsvalue;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_get_string::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_get_string::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_get_string::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_get_strings* Ucore_get_strings::core_get_strings(
			const FString ServerURL,
			const FString Token,
			const FString _stringsstringid,
			const FString _stringsstringparamsvalue,
			const FString _stringscomponent,
			const FString _stringslang,
			const FString _stringsstringparamsname)
{
	Ucore_get_strings* Node = NewObject<Ucore_get_strings>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_get_strings&strings[0][stringid]=" + _stringsstringid + "&strings[0][component]=" + _stringscomponent + "&strings[0][lang]=" + _stringslang + "&strings[0][stringparams][0][name]=" + _stringsstringparamsname + "&strings[0][stringparams][0][value]=" + _stringsstringparamsvalue;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_get_strings::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_get_strings::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_get_strings::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_get_user_dates* Ucore_get_user_dates::core_get_user_dates(
			const FString ServerURL,
			const FString Token,
			const int32 _timestampstimestamp,
			const FString _timestampsformat,
			const int32 _contextid,
			const FString _contextlevel,
			const int32 _instanceid,
			const FString _timestampstype,
			const int32 _timestampsfixday,
			const int32 _timestampsfixhour)
{
	Ucore_get_user_dates* Node = NewObject<Ucore_get_user_dates>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_get_user_dates&contextid=" + FString::FromInt(_contextid) + "&contextlevel=" + _contextlevel + "&instanceid=" + FString::FromInt(_instanceid) + "&timestamps[0][timestamp]=" + FString::FromInt(_timestampstimestamp) + "&timestamps[0][format]=" + _timestampsformat + "&timestamps[0][type]=" + _timestampstype + "&timestamps[0][fixday]=" + FString::FromInt(_timestampsfixday) + "&timestamps[0][fixhour]=" + FString::FromInt(_timestampsfixhour);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_get_user_dates::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_get_user_dates::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_get_user_dates::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_grades_create_gradecategories* Ucore_grades_create_gradecategories::core_grades_create_gradecategories(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const FString _categoriesfullname,
			const int32 _categoriesoptionsaggregation,
			const int32 _categoriesoptionsaggregateonlygraded,
			const int32 _categoriesoptionsaggregateoutcomes,
			const int32 _categoriesoptionsdroplow,
			const FString _categoriesoptionsitemname,
			const FString _categoriesoptionsiteminfo,
			const FString _categoriesoptionsidnumber,
			const int32 _categoriesoptionsgradetype,
			const int32 _categoriesoptionsgrademax,
			const int32 _categoriesoptionsgrademin,
			const int32 _categoriesoptionsgradepass,
			const int32 _categoriesoptionsdisplay,
			const int32 _categoriesoptionsdecimals,
			const int32 _categoriesoptionshiddenuntil,
			const int32 _categoriesoptionslocktime,
			const int32 _categoriesoptionsweightoverride,
			const FString _categoriesoptionsaggregationcoef2,
			const int32 _categoriesoptionsparentcategoryid,
			const FString _categoriesoptionsparentcategoryidnumber)
{
	Ucore_grades_create_gradecategories* Node = NewObject<Ucore_grades_create_gradecategories>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_grades_create_gradecategories&courseid=" + FString::FromInt(_courseid) + "&categories[0][fullname]=" + _categoriesfullname + "&categories[0][options][aggregation]=" + FString::FromInt(_categoriesoptionsaggregation) + "&categories[0][options][aggregateonlygraded]=" + FString::FromInt(_categoriesoptionsaggregateonlygraded) + "&categories[0][options][aggregateoutcomes]=" + FString::FromInt(_categoriesoptionsaggregateoutcomes) + "&categories[0][options][droplow]=" + FString::FromInt(_categoriesoptionsdroplow) + "&categories[0][options][itemname]=" + _categoriesoptionsitemname + "&categories[0][options][iteminfo]=" + _categoriesoptionsiteminfo + "&categories[0][options][idnumber]=" + _categoriesoptionsidnumber + "&categories[0][options][gradetype]=" + FString::FromInt(_categoriesoptionsgradetype) + "&categories[0][options][grademax]=" + FString::FromInt(_categoriesoptionsgrademax) + "&categories[0][options][grademin]=" + FString::FromInt(_categoriesoptionsgrademin) + "&categories[0][options][gradepass]=" + FString::FromInt(_categoriesoptionsgradepass) + "&categories[0][options][display]=" + FString::FromInt(_categoriesoptionsdisplay) + "&categories[0][options][decimals]=" + FString::FromInt(_categoriesoptionsdecimals) + "&categories[0][options][hiddenuntil]=" + FString::FromInt(_categoriesoptionshiddenuntil) + "&categories[0][options][locktime]=" + FString::FromInt(_categoriesoptionslocktime) + "&categories[0][options][weightoverride]=" + FString::FromInt(_categoriesoptionsweightoverride) + "&categories[0][options][aggregationcoef2]=" + _categoriesoptionsaggregationcoef2 + "&categories[0][options][parentcategoryid]=" + FString::FromInt(_categoriesoptionsparentcategoryid) + "&categories[0][options][parentcategoryidnumber]=" + _categoriesoptionsparentcategoryidnumber;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_grades_create_gradecategories::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_grades_create_gradecategories::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_grades_create_gradecategories::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_grades_get_enrolled_users_for_search_widget* Ucore_grades_get_enrolled_users_for_search_widget::core_grades_get_enrolled_users_for_search_widget(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const FString _actionbaseurl,
			const int32 _groupid)
{
	Ucore_grades_get_enrolled_users_for_search_widget* Node = NewObject<Ucore_grades_get_enrolled_users_for_search_widget>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_grades_get_enrolled_users_for_search_widget&courseid=" + FString::FromInt(_courseid) + "&actionbaseurl=" + _actionbaseurl + "&groupid=" + FString::FromInt(_groupid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_grades_get_enrolled_users_for_search_widget::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_grades_get_enrolled_users_for_search_widget::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_grades_get_enrolled_users_for_search_widget::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_grades_get_groups_for_search_widget* Ucore_grades_get_groups_for_search_widget::core_grades_get_groups_for_search_widget(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const FString _actionbaseurl)
{
	Ucore_grades_get_groups_for_search_widget* Node = NewObject<Ucore_grades_get_groups_for_search_widget>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_grades_get_groups_for_search_widget&courseid=" + FString::FromInt(_courseid) + "&actionbaseurl=" + _actionbaseurl;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_grades_get_groups_for_search_widget::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_grades_get_groups_for_search_widget::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_grades_get_groups_for_search_widget::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_grades_grader_gradingpanel_point_fetch* Ucore_grades_grader_gradingpanel_point_fetch::core_grades_grader_gradingpanel_point_fetch(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const int32 _contextid,
			const FString _itemname,
			const int32 _gradeduserid)
{
	Ucore_grades_grader_gradingpanel_point_fetch* Node = NewObject<Ucore_grades_grader_gradingpanel_point_fetch>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_grades_grader_gradingpanel_point_fetch&component=" + _component + "&contextid=" + FString::FromInt(_contextid) + "&itemname=" + _itemname + "&gradeduserid=" + FString::FromInt(_gradeduserid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_grades_grader_gradingpanel_point_fetch::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_grades_grader_gradingpanel_point_fetch::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_grades_grader_gradingpanel_point_fetch::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_grades_grader_gradingpanel_point_store* Ucore_grades_grader_gradingpanel_point_store::core_grades_grader_gradingpanel_point_store(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const int32 _contextid,
			const FString _itemname,
			const int32 _gradeduserid,
			const FString _formdata,
			const int32 _notifyuser)
{
	Ucore_grades_grader_gradingpanel_point_store* Node = NewObject<Ucore_grades_grader_gradingpanel_point_store>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_grades_grader_gradingpanel_point_store&component=" + _component + "&contextid=" + FString::FromInt(_contextid) + "&itemname=" + _itemname + "&gradeduserid=" + FString::FromInt(_gradeduserid) + "&notifyuser=" + FString::FromInt(_notifyuser) + "&formdata=" + _formdata;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_grades_grader_gradingpanel_point_store::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_grades_grader_gradingpanel_point_store::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_grades_grader_gradingpanel_point_store::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_grades_grader_gradingpanel_scale_fetch* Ucore_grades_grader_gradingpanel_scale_fetch::core_grades_grader_gradingpanel_scale_fetch(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const int32 _contextid,
			const FString _itemname,
			const int32 _gradeduserid)
{
	Ucore_grades_grader_gradingpanel_scale_fetch* Node = NewObject<Ucore_grades_grader_gradingpanel_scale_fetch>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_grades_grader_gradingpanel_scale_fetch&component=" + _component + "&contextid=" + FString::FromInt(_contextid) + "&itemname=" + _itemname + "&gradeduserid=" + FString::FromInt(_gradeduserid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_grades_grader_gradingpanel_scale_fetch::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_grades_grader_gradingpanel_scale_fetch::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_grades_grader_gradingpanel_scale_fetch::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_grades_grader_gradingpanel_scale_store* Ucore_grades_grader_gradingpanel_scale_store::core_grades_grader_gradingpanel_scale_store(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const int32 _contextid,
			const FString _itemname,
			const int32 _gradeduserid,
			const FString _formdata,
			const int32 _notifyuser)
{
	Ucore_grades_grader_gradingpanel_scale_store* Node = NewObject<Ucore_grades_grader_gradingpanel_scale_store>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_grades_grader_gradingpanel_scale_store&component=" + _component + "&contextid=" + FString::FromInt(_contextid) + "&itemname=" + _itemname + "&gradeduserid=" + FString::FromInt(_gradeduserid) + "&notifyuser=" + FString::FromInt(_notifyuser) + "&formdata=" + _formdata;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_grades_grader_gradingpanel_scale_store::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_grades_grader_gradingpanel_scale_store::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_grades_grader_gradingpanel_scale_store::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_grades_update_grades* Ucore_grades_update_grades::core_grades_update_grades(
			const FString ServerURL,
			const FString Token,
			const FString _source,
			const int32 _courseid,
			const FString _component,
			const int32 _activityid,
			const int32 _itemnumber,
			const int32 _gradesstudentid,
			const float _gradesgrade,
			const FString _gradesstr_feedback,
			const FString _itemdetailsitemname,
			const int32 _itemdetailsidnumber,
			const int32 _itemdetailsgradetype,
			const float _itemdetailsgrademax,
			const float _itemdetailsgrademin,
			const int32 _itemdetailsscaleid,
			const float _itemdetailsmultfactor,
			const float _itemdetailsplusfactor,
			const int32 _itemdetailsdeleted,
			const int32 _itemdetailshidden)
{
	Ucore_grades_update_grades* Node = NewObject<Ucore_grades_update_grades>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_grades_update_grades&source=" + _source + "&courseid=" + FString::FromInt(_courseid) + "&component=" + _component + "&activityid=" + FString::FromInt(_activityid) + "&itemnumber=" + FString::FromInt(_itemnumber) + "&grades[0][studentid]=" + FString::FromInt(_gradesstudentid) + "&grades[0][grade]=" + FString::SanitizeFloat(_gradesgrade) + "&grades[0][str_feedback]=" + _gradesstr_feedback + "&itemdetails[itemname]=" + _itemdetailsitemname + "&itemdetails[idnumber]=" + FString::FromInt(_itemdetailsidnumber) + "&itemdetails[gradetype]=" + FString::FromInt(_itemdetailsgradetype) + "&itemdetails[grademax]=" + FString::SanitizeFloat(_itemdetailsgrademax) + "&itemdetails[grademin]=" + FString::SanitizeFloat(_itemdetailsgrademin) + "&itemdetails[scaleid]=" + FString::FromInt(_itemdetailsscaleid) + "&itemdetails[multfactor]=" + FString::SanitizeFloat(_itemdetailsmultfactor) + "&itemdetails[plusfactor]=" + FString::SanitizeFloat(_itemdetailsplusfactor) + "&itemdetails[deleted]=" + FString::FromInt(_itemdetailsdeleted) + "&itemdetails[hidden]=" + FString::FromInt(_itemdetailshidden);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_grades_update_grades::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_grades_update_grades::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_grades_update_grades::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_grading_get_definitions* Ucore_grading_get_definitions::core_grading_get_definitions(
			const FString ServerURL,
			const FString Token,
			const int32 _cmids,
			const FString _areaname,
			const int32 _activeonly)
{
	Ucore_grading_get_definitions* Node = NewObject<Ucore_grading_get_definitions>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_grading_get_definitions&cmids[0]=" + FString::FromInt(_cmids) + "&areaname=" + _areaname + "&activeonly=" + FString::FromInt(_activeonly);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_grading_get_definitions::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_grading_get_definitions::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_grading_get_definitions::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_grading_get_gradingform_instances* Ucore_grading_get_gradingform_instances::core_grading_get_gradingform_instances(
			const FString ServerURL,
			const FString Token,
			const int32 _definitionid,
			const int32 _since)
{
	Ucore_grading_get_gradingform_instances* Node = NewObject<Ucore_grading_get_gradingform_instances>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_grading_get_gradingform_instances&definitionid=" + FString::FromInt(_definitionid) + "&since=" + FString::FromInt(_since);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_grading_get_gradingform_instances::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_grading_get_gradingform_instances::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_grading_get_gradingform_instances::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_grading_save_definitions* Ucore_grading_save_definitions::core_grading_save_definitions(
			const FString ServerURL,
			const FString Token,
			const int32 _areascmid,
			const int32 _areascontextid,
			const FString _areascomponent,
			const FString _areasareaname,
			const FString _areasdefinitionsname,
			const int32 _areasdefinitionsstatus,
			const int32 _areasdefinitionstimecreated,
			const int32 _areasdefinitionsusercreated,
			const int32 _areasdefinitionstimemodified,
			const int32 _areasdefinitionsusermodified,
			const FString _areasactivemethod,
			const int32 _areasdefinitionsid,
			const FString _areasdefinitionsmethod,
			const FString _areasdefinitionsdescription,
			const int32 _areasdefinitionsdescriptionformat,
			const int32 _areasdefinitionscopiedfromid,
			const int32 _areasdefinitionstimecopied,
			const int32 _areasdefinitionsguideguide_criteriaid,
			const int32 _areasdefinitionsguideguide_criteriasortorder,
			const FString _areasdefinitionsguideguide_criteriadescription,
			const int32 _areasdefinitionsguideguide_criteriadescriptionformat,
			const FString _areasdefinitionsguideguide_criteriashortname,
			const FString _areasdefinitionsguideguide_criteriadescriptionmarkers,
			const int32 _areasdefinitionsguideguide_criteriadescriptionmarkersformat,
			const float _areasdefinitionsguideguide_criteriamaxscore,
			const int32 _areasdefinitionsguideguide_commentsid,
			const int32 _areasdefinitionsguideguide_commentssortorder,
			const FString _areasdefinitionsguideguide_commentsdescription,
			const int32 _areasdefinitionsguideguide_commentsdescriptionformat,
			const int32 _areasdefinitionsrubricrubric_criteriaid,
			const int32 _areasdefinitionsrubricrubric_criteriasortorder,
			const FString _areasdefinitionsrubricrubric_criteriadescription,
			const int32 _areasdefinitionsrubricrubric_criteriadescriptionformat,
			const int32 _areasdefinitionsrubricrubric_criterialevelsid,
			const float _areasdefinitionsrubricrubric_criterialevelsscore,
			const FString _areasdefinitionsrubricrubric_criterialevelsdefinition,
			const int32 _areasdefinitionsrubricrubric_criterialevelsdefinitionformat)
{
	Ucore_grading_save_definitions* Node = NewObject<Ucore_grading_save_definitions>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_grading_save_definitions&areas[0][cmid]=" + FString::FromInt(_areascmid) + "&areas[0][contextid]=" + FString::FromInt(_areascontextid) + "&areas[0][component]=" + _areascomponent + "&areas[0][areaname]=" + _areasareaname + "&areas[0][activemethod]=" + _areasactivemethod + "&areas[0][definitions][0][id]=" + FString::FromInt(_areasdefinitionsid) + "&areas[0][definitions][0][method]=" + _areasdefinitionsmethod + "&areas[0][definitions][0][name]=" + _areasdefinitionsname + "&areas[0][definitions][0][description]=" + _areasdefinitionsdescription + "&areas[0][definitions][0][descriptionformat]=" + FString::FromInt(_areasdefinitionsdescriptionformat) + "&areas[0][definitions][0][status]=" + FString::FromInt(_areasdefinitionsstatus) + "&areas[0][definitions][0][copiedfromid]=" + FString::FromInt(_areasdefinitionscopiedfromid) + "&areas[0][definitions][0][timecreated]=" + FString::FromInt(_areasdefinitionstimecreated) + "&areas[0][definitions][0][usercreated]=" + FString::FromInt(_areasdefinitionsusercreated) + "&areas[0][definitions][0][timemodified]=" + FString::FromInt(_areasdefinitionstimemodified) + "&areas[0][definitions][0][usermodified]=" + FString::FromInt(_areasdefinitionsusermodified) + "&areas[0][definitions][0][timecopied]=" + FString::FromInt(_areasdefinitionstimecopied) + "&areas[0][definitions][0][guide][guide_criteria][0][id]=" + FString::FromInt(_areasdefinitionsguideguide_criteriaid) + "&areas[0][definitions][0][guide][guide_criteria][0][sortorder]=" + FString::FromInt(_areasdefinitionsguideguide_criteriasortorder) + "&areas[0][definitions][0][guide][guide_criteria][0][description]=" + _areasdefinitionsguideguide_criteriadescription + "&areas[0][definitions][0][guide][guide_criteria][0][descriptionformat]=" + FString::FromInt(_areasdefinitionsguideguide_criteriadescriptionformat) + "&areas[0][definitions][0][guide][guide_criteria][0][shortname]=" + _areasdefinitionsguideguide_criteriashortname + "&areas[0][definitions][0][guide][guide_criteria][0][descriptionmarkers]=" + _areasdefinitionsguideguide_criteriadescriptionmarkers + "&areas[0][definitions][0][guide][guide_criteria][0][descriptionmarkersformat]=" + FString::FromInt(_areasdefinitionsguideguide_criteriadescriptionmarkersformat) + "&areas[0][definitions][0][guide][guide_criteria][0][maxscore]=" + FString::SanitizeFloat(_areasdefinitionsguideguide_criteriamaxscore) + "&areas[0][definitions][0][guide][guide_comments][0][id]=" + FString::FromInt(_areasdefinitionsguideguide_commentsid) + "&areas[0][definitions][0][guide][guide_comments][0][sortorder]=" + FString::FromInt(_areasdefinitionsguideguide_commentssortorder) + "&areas[0][definitions][0][guide][guide_comments][0][description]=" + _areasdefinitionsguideguide_commentsdescription + "&areas[0][definitions][0][guide][guide_comments][0][descriptionformat]=" + FString::FromInt(_areasdefinitionsguideguide_commentsdescriptionformat) + "&areas[0][definitions][0][rubric][rubric_criteria][0][id]=" + FString::FromInt(_areasdefinitionsrubricrubric_criteriaid) + "&areas[0][definitions][0][rubric][rubric_criteria][0][sortorder]=" + FString::FromInt(_areasdefinitionsrubricrubric_criteriasortorder) + "&areas[0][definitions][0][rubric][rubric_criteria][0][description]=" + _areasdefinitionsrubricrubric_criteriadescription + "&areas[0][definitions][0][rubric][rubric_criteria][0][descriptionformat]=" + FString::FromInt(_areasdefinitionsrubricrubric_criteriadescriptionformat) + "&areas[0][definitions][0][rubric][rubric_criteria][0][levels][0][id]=" + FString::FromInt(_areasdefinitionsrubricrubric_criterialevelsid) + "&areas[0][definitions][0][rubric][rubric_criteria][0][levels][0][score]=" + FString::SanitizeFloat(_areasdefinitionsrubricrubric_criterialevelsscore) + "&areas[0][definitions][0][rubric][rubric_criteria][0][levels][0][definition]=" + _areasdefinitionsrubricrubric_criterialevelsdefinition + "&areas[0][definitions][0][rubric][rubric_criteria][0][levels][0][definitionformat]=" + FString::FromInt(_areasdefinitionsrubricrubric_criterialevelsdefinitionformat);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_grading_save_definitions::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_grading_save_definitions::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_grading_save_definitions::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_group_add_group_members* Ucore_group_add_group_members::core_group_add_group_members(
			const FString ServerURL,
			const FString Token,
			const int32 _membersgroupid,
			const int32 _membersuserid)
{
	Ucore_group_add_group_members* Node = NewObject<Ucore_group_add_group_members>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_group_add_group_members&members[0][groupid]=" + FString::FromInt(_membersgroupid) + "&members[0][userid]=" + FString::FromInt(_membersuserid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_group_add_group_members::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_group_add_group_members::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_group_add_group_members::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_group_assign_grouping* Ucore_group_assign_grouping::core_group_assign_grouping(
			const FString ServerURL,
			const FString Token,
			const int32 _assignmentsgroupingid,
			const int32 _assignmentsgroupid)
{
	Ucore_group_assign_grouping* Node = NewObject<Ucore_group_assign_grouping>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_group_assign_grouping&assignments[0][groupingid]=" + FString::FromInt(_assignmentsgroupingid) + "&assignments[0][groupid]=" + FString::FromInt(_assignmentsgroupid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_group_assign_grouping::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_group_assign_grouping::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_group_assign_grouping::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_group_create_groupings* Ucore_group_create_groupings::core_group_create_groupings(
			const FString ServerURL,
			const FString Token,
			const int32 _groupingscourseid,
			const FString _groupingsname,
			const FString _groupingsdescription,
			const int32 _groupingsdescriptionformat,
			const FString _groupingsidnumber)
{
	Ucore_group_create_groupings* Node = NewObject<Ucore_group_create_groupings>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_group_create_groupings&groupings[0][courseid]=" + FString::FromInt(_groupingscourseid) + "&groupings[0][name]=" + _groupingsname + "&groupings[0][description]=" + _groupingsdescription + "&groupings[0][descriptionformat]=" + FString::FromInt(_groupingsdescriptionformat) + "&groupings[0][idnumber]=" + _groupingsidnumber;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_group_create_groupings::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_group_create_groupings::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_group_create_groupings::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_group_create_groups* Ucore_group_create_groups::core_group_create_groups(
			const FString ServerURL,
			const FString Token,
			const int32 _groupscourseid,
			const FString _groupsname,
			const FString _groupsdescription,
			const int32 _groupsdescriptionformat,
			const FString _groupsenrolmentkey,
			const FString _groupsidnumber)
{
	Ucore_group_create_groups* Node = NewObject<Ucore_group_create_groups>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_group_create_groups&groups[0][courseid]=" + FString::FromInt(_groupscourseid) + "&groups[0][name]=" + _groupsname + "&groups[0][description]=" + _groupsdescription + "&groups[0][descriptionformat]=" + FString::FromInt(_groupsdescriptionformat) + "&groups[0][enrolmentkey]=" + _groupsenrolmentkey + "&groups[0][idnumber]=" + _groupsidnumber;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_group_create_groups::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_group_create_groups::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_group_create_groups::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_group_delete_group_members* Ucore_group_delete_group_members::core_group_delete_group_members(
			const FString ServerURL,
			const FString Token,
			const int32 _membersgroupid,
			const int32 _membersuserid)
{
	Ucore_group_delete_group_members* Node = NewObject<Ucore_group_delete_group_members>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_group_delete_group_members&members[0][groupid]=" + FString::FromInt(_membersgroupid) + "&members[0][userid]=" + FString::FromInt(_membersuserid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_group_delete_group_members::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_group_delete_group_members::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_group_delete_group_members::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_group_delete_groupings* Ucore_group_delete_groupings::core_group_delete_groupings(
			const FString ServerURL,
			const FString Token,
			const int32 _groupingids)
{
	Ucore_group_delete_groupings* Node = NewObject<Ucore_group_delete_groupings>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_group_delete_groupings&groupingids[0]=" + FString::FromInt(_groupingids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_group_delete_groupings::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_group_delete_groupings::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_group_delete_groupings::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_group_delete_groups* Ucore_group_delete_groups::core_group_delete_groups(
			const FString ServerURL,
			const FString Token,
			const int32 _groupids)
{
	Ucore_group_delete_groups* Node = NewObject<Ucore_group_delete_groups>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_group_delete_groups&groupids[0]=" + FString::FromInt(_groupids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_group_delete_groups::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_group_delete_groups::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_group_delete_groups::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_group_get_activity_allowed_groups* Ucore_group_get_activity_allowed_groups::core_group_get_activity_allowed_groups(
			const FString ServerURL,
			const FString Token,
			const int32 _cmid,
			const int32 _userid)
{
	Ucore_group_get_activity_allowed_groups* Node = NewObject<Ucore_group_get_activity_allowed_groups>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_group_get_activity_allowed_groups&cmid=" + FString::FromInt(_cmid) + "&userid=" + FString::FromInt(_userid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_group_get_activity_allowed_groups::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_group_get_activity_allowed_groups::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_group_get_activity_allowed_groups::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_group_get_activity_groupmode* Ucore_group_get_activity_groupmode::core_group_get_activity_groupmode(
			const FString ServerURL,
			const FString Token,
			const int32 _cmid)
{
	Ucore_group_get_activity_groupmode* Node = NewObject<Ucore_group_get_activity_groupmode>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_group_get_activity_groupmode&cmid=" + FString::FromInt(_cmid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_group_get_activity_groupmode::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_group_get_activity_groupmode::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_group_get_activity_groupmode::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_group_get_course_groupings* Ucore_group_get_course_groupings::core_group_get_course_groupings(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid)
{
	Ucore_group_get_course_groupings* Node = NewObject<Ucore_group_get_course_groupings>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_group_get_course_groupings&courseid=" + FString::FromInt(_courseid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_group_get_course_groupings::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_group_get_course_groupings::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_group_get_course_groupings::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_group_get_course_groups* Ucore_group_get_course_groups::core_group_get_course_groups(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid)
{
	Ucore_group_get_course_groups* Node = NewObject<Ucore_group_get_course_groups>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_group_get_course_groups&courseid=" + FString::FromInt(_courseid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_group_get_course_groups::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_group_get_course_groups::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_group_get_course_groups::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_group_get_course_user_groups* Ucore_group_get_course_user_groups::core_group_get_course_user_groups(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _userid,
			const int32 _groupingid)
{
	Ucore_group_get_course_user_groups* Node = NewObject<Ucore_group_get_course_user_groups>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_group_get_course_user_groups&courseid=" + FString::FromInt(_courseid) + "&userid=" + FString::FromInt(_userid) + "&groupingid=" + FString::FromInt(_groupingid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_group_get_course_user_groups::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_group_get_course_user_groups::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_group_get_course_user_groups::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_group_get_group_members* Ucore_group_get_group_members::core_group_get_group_members(
			const FString ServerURL,
			const FString Token,
			const int32 _groupids)
{
	Ucore_group_get_group_members* Node = NewObject<Ucore_group_get_group_members>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_group_get_group_members&groupids[0]=" + FString::FromInt(_groupids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_group_get_group_members::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_group_get_group_members::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_group_get_group_members::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_group_get_groupings* Ucore_group_get_groupings::core_group_get_groupings(
			const FString ServerURL,
			const FString Token,
			const int32 _groupingids,
			const int32 _returngroups)
{
	Ucore_group_get_groupings* Node = NewObject<Ucore_group_get_groupings>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_group_get_groupings&groupingids[0]=" + FString::FromInt(_groupingids) + "&returngroups=" + FString::FromInt(_returngroups);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_group_get_groupings::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_group_get_groupings::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_group_get_groupings::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_group_get_groups* Ucore_group_get_groups::core_group_get_groups(
			const FString ServerURL,
			const FString Token,
			const int32 _groupids)
{
	Ucore_group_get_groups* Node = NewObject<Ucore_group_get_groups>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_group_get_groups&groupids[0]=" + FString::FromInt(_groupids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_group_get_groups::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_group_get_groups::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_group_get_groups::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_group_unassign_grouping* Ucore_group_unassign_grouping::core_group_unassign_grouping(
			const FString ServerURL,
			const FString Token,
			const int32 _unassignmentsgroupingid,
			const int32 _unassignmentsgroupid)
{
	Ucore_group_unassign_grouping* Node = NewObject<Ucore_group_unassign_grouping>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_group_unassign_grouping&unassignments[0][groupingid]=" + FString::FromInt(_unassignmentsgroupingid) + "&unassignments[0][groupid]=" + FString::FromInt(_unassignmentsgroupid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_group_unassign_grouping::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_group_unassign_grouping::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_group_unassign_grouping::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_group_update_groupings* Ucore_group_update_groupings::core_group_update_groupings(
			const FString ServerURL,
			const FString Token,
			const FString _groupingsname,
			const int32 _groupingsid,
			const FString _groupingsdescription,
			const int32 _groupingsdescriptionformat,
			const FString _groupingsidnumber)
{
	Ucore_group_update_groupings* Node = NewObject<Ucore_group_update_groupings>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_group_update_groupings&groupings[0][id]=" + FString::FromInt(_groupingsid) + "&groupings[0][name]=" + _groupingsname + "&groupings[0][description]=" + _groupingsdescription + "&groupings[0][descriptionformat]=" + FString::FromInt(_groupingsdescriptionformat) + "&groupings[0][idnumber]=" + _groupingsidnumber;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_group_update_groupings::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_group_update_groupings::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_group_update_groupings::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_group_update_groups* Ucore_group_update_groups::core_group_update_groups(
			const FString ServerURL,
			const FString Token,
			const FString _groupsname,
			const int32 _groupsid,
			const FString _groupsdescription,
			const int32 _groupsdescriptionformat,
			const FString _groupsenrolmentkey,
			const FString _groupsidnumber)
{
	Ucore_group_update_groups* Node = NewObject<Ucore_group_update_groups>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_group_update_groups&groups[0][id]=" + FString::FromInt(_groupsid) + "&groups[0][name]=" + _groupsname + "&groups[0][description]=" + _groupsdescription + "&groups[0][descriptionformat]=" + FString::FromInt(_groupsdescriptionformat) + "&groups[0][enrolmentkey]=" + _groupsenrolmentkey + "&groups[0][idnumber]=" + _groupsidnumber;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_group_update_groups::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_group_update_groups::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_group_update_groups::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_h5p_get_trusted_h5p_file* Ucore_h5p_get_trusted_h5p_file::core_h5p_get_trusted_h5p_file(
			const FString ServerURL,
			const FString Token,
			const FString _url,
			const int32 _frame,
			const int32 _export,
			const int32 _embed,
			const int32 _copyright)
{
	Ucore_h5p_get_trusted_h5p_file* Node = NewObject<Ucore_h5p_get_trusted_h5p_file>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_h5p_get_trusted_h5p_file&url=" + _url + "&frame=" + FString::FromInt(_frame) + "&export=" + FString::FromInt(_export) + "&embed=" + FString::FromInt(_embed) + "&copyright=" + FString::FromInt(_copyright);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_h5p_get_trusted_h5p_file::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_h5p_get_trusted_h5p_file::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_h5p_get_trusted_h5p_file::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_block_user* Ucore_message_block_user::core_message_block_user(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _blockeduserid)
{
	Ucore_message_block_user* Node = NewObject<Ucore_message_block_user>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_block_user&userid=" + FString::FromInt(_userid) + "&blockeduserid=" + FString::FromInt(_blockeduserid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_block_user::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_block_user::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_block_user::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_confirm_contact_request* Ucore_message_confirm_contact_request::core_message_confirm_contact_request(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _requesteduserid)
{
	Ucore_message_confirm_contact_request* Node = NewObject<Ucore_message_confirm_contact_request>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_confirm_contact_request&userid=" + FString::FromInt(_userid) + "&requesteduserid=" + FString::FromInt(_requesteduserid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_confirm_contact_request::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_confirm_contact_request::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_confirm_contact_request::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_create_contact_request* Ucore_message_create_contact_request::core_message_create_contact_request(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _requesteduserid)
{
	Ucore_message_create_contact_request* Node = NewObject<Ucore_message_create_contact_request>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_create_contact_request&userid=" + FString::FromInt(_userid) + "&requesteduserid=" + FString::FromInt(_requesteduserid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_create_contact_request::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_create_contact_request::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_create_contact_request::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_data_for_messagearea_search_messages* Ucore_message_data_for_messagearea_search_messages::core_message_data_for_messagearea_search_messages(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const FString _search,
			const int32 _limitfrom,
			const int32 _limitnum)
{
	Ucore_message_data_for_messagearea_search_messages* Node = NewObject<Ucore_message_data_for_messagearea_search_messages>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_data_for_messagearea_search_messages&userid=" + FString::FromInt(_userid) + "&search=" + _search + "&limitfrom=" + FString::FromInt(_limitfrom) + "&limitnum=" + FString::FromInt(_limitnum);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_data_for_messagearea_search_messages::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_data_for_messagearea_search_messages::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_data_for_messagearea_search_messages::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_decline_contact_request* Ucore_message_decline_contact_request::core_message_decline_contact_request(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _requesteduserid)
{
	Ucore_message_decline_contact_request* Node = NewObject<Ucore_message_decline_contact_request>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_decline_contact_request&userid=" + FString::FromInt(_userid) + "&requesteduserid=" + FString::FromInt(_requesteduserid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_decline_contact_request::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_decline_contact_request::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_decline_contact_request::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_delete_contacts* Ucore_message_delete_contacts::core_message_delete_contacts(
			const FString ServerURL,
			const FString Token,
			const int32 _userids,
			const int32 _userid)
{
	Ucore_message_delete_contacts* Node = NewObject<Ucore_message_delete_contacts>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_delete_contacts&userids[0]=" + FString::FromInt(_userids) + "&userid=" + FString::FromInt(_userid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_delete_contacts::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_delete_contacts::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_delete_contacts::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_delete_conversations_by_id* Ucore_message_delete_conversations_by_id::core_message_delete_conversations_by_id(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _conversationids)
{
	Ucore_message_delete_conversations_by_id* Node = NewObject<Ucore_message_delete_conversations_by_id>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_delete_conversations_by_id&userid=" + FString::FromInt(_userid) + "&conversationids[0]=" + FString::FromInt(_conversationids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_delete_conversations_by_id::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_delete_conversations_by_id::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_delete_conversations_by_id::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_delete_message* Ucore_message_delete_message::core_message_delete_message(
			const FString ServerURL,
			const FString Token,
			const int32 _messageid,
			const int32 _userid,
			const int32 _read)
{
	Ucore_message_delete_message* Node = NewObject<Ucore_message_delete_message>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_delete_message&messageid=" + FString::FromInt(_messageid) + "&userid=" + FString::FromInt(_userid) + "&read=" + FString::FromInt(_read);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_delete_message::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_delete_message::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_delete_message::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_delete_message_for_all_users* Ucore_message_delete_message_for_all_users::core_message_delete_message_for_all_users(
			const FString ServerURL,
			const FString Token,
			const int32 _messageid,
			const int32 _userid)
{
	Ucore_message_delete_message_for_all_users* Node = NewObject<Ucore_message_delete_message_for_all_users>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_delete_message_for_all_users&messageid=" + FString::FromInt(_messageid) + "&userid=" + FString::FromInt(_userid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_delete_message_for_all_users::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_delete_message_for_all_users::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_delete_message_for_all_users::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_get_blocked_users* Ucore_message_get_blocked_users::core_message_get_blocked_users(
			const FString ServerURL,
			const FString Token,
			const int32 _userid)
{
	Ucore_message_get_blocked_users* Node = NewObject<Ucore_message_get_blocked_users>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_get_blocked_users&userid=" + FString::FromInt(_userid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_get_blocked_users::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_get_blocked_users::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_get_blocked_users::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_get_contact_requests* Ucore_message_get_contact_requests::core_message_get_contact_requests(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _limitfrom,
			const int32 _limitnum)
{
	Ucore_message_get_contact_requests* Node = NewObject<Ucore_message_get_contact_requests>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_get_contact_requests&userid=" + FString::FromInt(_userid) + "&limitfrom=" + FString::FromInt(_limitfrom) + "&limitnum=" + FString::FromInt(_limitnum);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_get_contact_requests::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_get_contact_requests::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_get_contact_requests::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_get_conversation* Ucore_message_get_conversation::core_message_get_conversation(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _conversationid,
			const int32 _includecontactrequests,
			const int32 _includeprivacyinfo,
			const int32 _memberlimit,
			const int32 _memberoffset,
			const int32 _messagelimit,
			const int32 _messageoffset,
			const int32 _newestmessagesfirst)
{
	Ucore_message_get_conversation* Node = NewObject<Ucore_message_get_conversation>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_get_conversation&userid=" + FString::FromInt(_userid) + "&conversationid=" + FString::FromInt(_conversationid) + "&includecontactrequests=" + FString::FromInt(_includecontactrequests) + "&includeprivacyinfo=" + FString::FromInt(_includeprivacyinfo) + "&memberlimit=" + FString::FromInt(_memberlimit) + "&memberoffset=" + FString::FromInt(_memberoffset) + "&messagelimit=" + FString::FromInt(_messagelimit) + "&messageoffset=" + FString::FromInt(_messageoffset) + "&newestmessagesfirst=" + FString::FromInt(_newestmessagesfirst);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_get_conversation::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_get_conversation::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_get_conversation::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_get_conversation_between_users* Ucore_message_get_conversation_between_users::core_message_get_conversation_between_users(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _otheruserid,
			const int32 _includecontactrequests,
			const int32 _includeprivacyinfo,
			const int32 _memberlimit,
			const int32 _memberoffset,
			const int32 _messagelimit,
			const int32 _messageoffset,
			const int32 _newestmessagesfirst)
{
	Ucore_message_get_conversation_between_users* Node = NewObject<Ucore_message_get_conversation_between_users>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_get_conversation_between_users&userid=" + FString::FromInt(_userid) + "&otheruserid=" + FString::FromInt(_otheruserid) + "&includecontactrequests=" + FString::FromInt(_includecontactrequests) + "&includeprivacyinfo=" + FString::FromInt(_includeprivacyinfo) + "&memberlimit=" + FString::FromInt(_memberlimit) + "&memberoffset=" + FString::FromInt(_memberoffset) + "&messagelimit=" + FString::FromInt(_messagelimit) + "&messageoffset=" + FString::FromInt(_messageoffset) + "&newestmessagesfirst=" + FString::FromInt(_newestmessagesfirst);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_get_conversation_between_users::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_get_conversation_between_users::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_get_conversation_between_users::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_get_conversation_counts* Ucore_message_get_conversation_counts::core_message_get_conversation_counts(
			const FString ServerURL,
			const FString Token,
			const int32 _userid)
{
	Ucore_message_get_conversation_counts* Node = NewObject<Ucore_message_get_conversation_counts>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_get_conversation_counts&userid=" + FString::FromInt(_userid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_get_conversation_counts::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_get_conversation_counts::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_get_conversation_counts::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_get_conversation_members* Ucore_message_get_conversation_members::core_message_get_conversation_members(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _conversationid,
			const int32 _includecontactrequests,
			const int32 _includeprivacyinfo,
			const int32 _limitfrom,
			const int32 _limitnum)
{
	Ucore_message_get_conversation_members* Node = NewObject<Ucore_message_get_conversation_members>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_get_conversation_members&userid=" + FString::FromInt(_userid) + "&conversationid=" + FString::FromInt(_conversationid) + "&includecontactrequests=" + FString::FromInt(_includecontactrequests) + "&includeprivacyinfo=" + FString::FromInt(_includeprivacyinfo) + "&limitfrom=" + FString::FromInt(_limitfrom) + "&limitnum=" + FString::FromInt(_limitnum);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_get_conversation_members::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_get_conversation_members::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_get_conversation_members::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_get_conversation_messages* Ucore_message_get_conversation_messages::core_message_get_conversation_messages(
			const FString ServerURL,
			const FString Token,
			const int32 _currentuserid,
			const int32 _convid,
			const int32 _limitfrom,
			const int32 _limitnum,
			const int32 _newest,
			const int32 _timefrom)
{
	Ucore_message_get_conversation_messages* Node = NewObject<Ucore_message_get_conversation_messages>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_get_conversation_messages&currentuserid=" + FString::FromInt(_currentuserid) + "&convid=" + FString::FromInt(_convid) + "&limitfrom=" + FString::FromInt(_limitfrom) + "&limitnum=" + FString::FromInt(_limitnum) + "&newest=" + FString::FromInt(_newest) + "&timefrom=" + FString::FromInt(_timefrom);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_get_conversation_messages::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_get_conversation_messages::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_get_conversation_messages::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_get_conversations* Ucore_message_get_conversations::core_message_get_conversations(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _limitfrom,
			const int32 _limitnum,
			const int32 _type,
			const int32 _favourites,
			const int32 _mergeself)
{
	Ucore_message_get_conversations* Node = NewObject<Ucore_message_get_conversations>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_get_conversations&userid=" + FString::FromInt(_userid) + "&limitfrom=" + FString::FromInt(_limitfrom) + "&limitnum=" + FString::FromInt(_limitnum) + "&type=" + FString::FromInt(_type) + "&favourites=" + FString::FromInt(_favourites) + "&mergeself=" + FString::FromInt(_mergeself);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_get_conversations::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_get_conversations::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_get_conversations::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_get_member_info* Ucore_message_get_member_info::core_message_get_member_info(
			const FString ServerURL,
			const FString Token,
			const int32 _referenceuserid,
			const int32 _userids,
			const int32 _includecontactrequests,
			const int32 _includeprivacyinfo)
{
	Ucore_message_get_member_info* Node = NewObject<Ucore_message_get_member_info>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_get_member_info&referenceuserid=" + FString::FromInt(_referenceuserid) + "&userids[0]=" + FString::FromInt(_userids) + "&includecontactrequests=" + FString::FromInt(_includecontactrequests) + "&includeprivacyinfo=" + FString::FromInt(_includeprivacyinfo);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_get_member_info::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_get_member_info::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_get_member_info::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_get_message_processor* Ucore_message_get_message_processor::core_message_get_message_processor(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const FString _name)
{
	Ucore_message_get_message_processor* Node = NewObject<Ucore_message_get_message_processor>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_get_message_processor&userid=" + FString::FromInt(_userid) + "&name=" + _name;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_get_message_processor::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_get_message_processor::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_get_message_processor::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_get_messages* Ucore_message_get_messages::core_message_get_messages(
			const FString ServerURL,
			const FString Token,
			const int32 _useridto,
			const int32 _useridfrom,
			const FString _type,
			const int32 _read,
			const int32 _newestfirst,
			const int32 _limitfrom,
			const int32 _limitnum)
{
	Ucore_message_get_messages* Node = NewObject<Ucore_message_get_messages>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_get_messages&useridto=" + FString::FromInt(_useridto) + "&useridfrom=" + FString::FromInt(_useridfrom) + "&type=" + _type + "&read=" + FString::FromInt(_read) + "&newestfirst=" + FString::FromInt(_newestfirst) + "&limitfrom=" + FString::FromInt(_limitfrom) + "&limitnum=" + FString::FromInt(_limitnum);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_get_messages::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_get_messages::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_get_messages::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_get_received_contact_requests_count* Ucore_message_get_received_contact_requests_count::core_message_get_received_contact_requests_count(
			const FString ServerURL,
			const FString Token,
			const int32 _userid)
{
	Ucore_message_get_received_contact_requests_count* Node = NewObject<Ucore_message_get_received_contact_requests_count>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_get_received_contact_requests_count&userid=" + FString::FromInt(_userid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_get_received_contact_requests_count::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_get_received_contact_requests_count::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_get_received_contact_requests_count::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_get_self_conversation* Ucore_message_get_self_conversation::core_message_get_self_conversation(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _messagelimit,
			const int32 _messageoffset,
			const int32 _newestmessagesfirst)
{
	Ucore_message_get_self_conversation* Node = NewObject<Ucore_message_get_self_conversation>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_get_self_conversation&userid=" + FString::FromInt(_userid) + "&messagelimit=" + FString::FromInt(_messagelimit) + "&messageoffset=" + FString::FromInt(_messageoffset) + "&newestmessagesfirst=" + FString::FromInt(_newestmessagesfirst);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_get_self_conversation::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_get_self_conversation::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_get_self_conversation::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_get_unread_conversation_counts* Ucore_message_get_unread_conversation_counts::core_message_get_unread_conversation_counts(
			const FString ServerURL,
			const FString Token,
			const int32 _userid)
{
	Ucore_message_get_unread_conversation_counts* Node = NewObject<Ucore_message_get_unread_conversation_counts>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_get_unread_conversation_counts&userid=" + FString::FromInt(_userid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_get_unread_conversation_counts::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_get_unread_conversation_counts::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_get_unread_conversation_counts::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_get_unread_conversations_count* Ucore_message_get_unread_conversations_count::core_message_get_unread_conversations_count(
			const FString ServerURL,
			const FString Token,
			const int32 _useridto)
{
	Ucore_message_get_unread_conversations_count* Node = NewObject<Ucore_message_get_unread_conversations_count>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_get_unread_conversations_count&useridto=" + FString::FromInt(_useridto);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_get_unread_conversations_count::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_get_unread_conversations_count::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_get_unread_conversations_count::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_get_unread_notification_count* Ucore_message_get_unread_notification_count::core_message_get_unread_notification_count(
			const FString ServerURL,
			const FString Token,
			const int32 _useridto)
{
	Ucore_message_get_unread_notification_count* Node = NewObject<Ucore_message_get_unread_notification_count>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_get_unread_notification_count&useridto=" + FString::FromInt(_useridto);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_get_unread_notification_count::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_get_unread_notification_count::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_get_unread_notification_count::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_get_user_contacts* Ucore_message_get_user_contacts::core_message_get_user_contacts(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _limitfrom,
			const int32 _limitnum)
{
	Ucore_message_get_user_contacts* Node = NewObject<Ucore_message_get_user_contacts>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_get_user_contacts&userid=" + FString::FromInt(_userid) + "&limitfrom=" + FString::FromInt(_limitfrom) + "&limitnum=" + FString::FromInt(_limitnum);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_get_user_contacts::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_get_user_contacts::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_get_user_contacts::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_get_user_message_preferences* Ucore_message_get_user_message_preferences::core_message_get_user_message_preferences(
			const FString ServerURL,
			const FString Token,
			const int32 _userid)
{
	Ucore_message_get_user_message_preferences* Node = NewObject<Ucore_message_get_user_message_preferences>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_get_user_message_preferences&userid=" + FString::FromInt(_userid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_get_user_message_preferences::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_get_user_message_preferences::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_get_user_message_preferences::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_get_user_notification_preferences* Ucore_message_get_user_notification_preferences::core_message_get_user_notification_preferences(
			const FString ServerURL,
			const FString Token,
			const int32 _userid)
{
	Ucore_message_get_user_notification_preferences* Node = NewObject<Ucore_message_get_user_notification_preferences>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_get_user_notification_preferences&userid=" + FString::FromInt(_userid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_get_user_notification_preferences::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_get_user_notification_preferences::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_get_user_notification_preferences::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_mark_all_conversation_messages_as_read* Ucore_message_mark_all_conversation_messages_as_read::core_message_mark_all_conversation_messages_as_read(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _conversationid)
{
	Ucore_message_mark_all_conversation_messages_as_read* Node = NewObject<Ucore_message_mark_all_conversation_messages_as_read>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_mark_all_conversation_messages_as_read&userid=" + FString::FromInt(_userid) + "&conversationid=" + FString::FromInt(_conversationid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_mark_all_conversation_messages_as_read::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_mark_all_conversation_messages_as_read::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_mark_all_conversation_messages_as_read::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_mark_all_notifications_as_read* Ucore_message_mark_all_notifications_as_read::core_message_mark_all_notifications_as_read(
			const FString ServerURL,
			const FString Token,
			const int32 _useridto,
			const int32 _useridfrom,
			const int32 _timecreatedto)
{
	Ucore_message_mark_all_notifications_as_read* Node = NewObject<Ucore_message_mark_all_notifications_as_read>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_mark_all_notifications_as_read&useridto=" + FString::FromInt(_useridto) + "&useridfrom=" + FString::FromInt(_useridfrom) + "&timecreatedto=" + FString::FromInt(_timecreatedto);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_mark_all_notifications_as_read::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_mark_all_notifications_as_read::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_mark_all_notifications_as_read::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_mark_message_read* Ucore_message_mark_message_read::core_message_mark_message_read(
			const FString ServerURL,
			const FString Token,
			const int32 _messageid,
			const int32 _timeread)
{
	Ucore_message_mark_message_read* Node = NewObject<Ucore_message_mark_message_read>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_mark_message_read&messageid=" + FString::FromInt(_messageid) + "&timeread=" + FString::FromInt(_timeread);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_mark_message_read::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_mark_message_read::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_mark_message_read::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_mark_notification_read* Ucore_message_mark_notification_read::core_message_mark_notification_read(
			const FString ServerURL,
			const FString Token,
			const int32 _notificationid,
			const int32 _timeread)
{
	Ucore_message_mark_notification_read* Node = NewObject<Ucore_message_mark_notification_read>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_mark_notification_read&notificationid=" + FString::FromInt(_notificationid) + "&timeread=" + FString::FromInt(_timeread);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_mark_notification_read::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_mark_notification_read::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_mark_notification_read::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_message_processor_config_form* Ucore_message_message_processor_config_form::core_message_message_processor_config_form(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const FString _name,
			const FString _formvaluesname,
			const FString _formvaluesvalue)
{
	Ucore_message_message_processor_config_form* Node = NewObject<Ucore_message_message_processor_config_form>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_message_processor_config_form&userid=" + FString::FromInt(_userid) + "&name=" + _name + "&formvalues[0][name]=" + _formvaluesname + "&formvalues[0][value]=" + _formvaluesvalue;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_message_processor_config_form::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_message_processor_config_form::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_message_processor_config_form::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_message_search_users* Ucore_message_message_search_users::core_message_message_search_users(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const FString _search,
			const int32 _limitfrom,
			const int32 _limitnum)
{
	Ucore_message_message_search_users* Node = NewObject<Ucore_message_message_search_users>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_message_search_users&userid=" + FString::FromInt(_userid) + "&search=" + _search + "&limitfrom=" + FString::FromInt(_limitfrom) + "&limitnum=" + FString::FromInt(_limitnum);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_message_search_users::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_message_search_users::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_message_search_users::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_mute_conversations* Ucore_message_mute_conversations::core_message_mute_conversations(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _conversationids)
{
	Ucore_message_mute_conversations* Node = NewObject<Ucore_message_mute_conversations>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_mute_conversations&userid=" + FString::FromInt(_userid) + "&conversationids[0]=" + FString::FromInt(_conversationids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_mute_conversations::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_mute_conversations::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_mute_conversations::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_search_contacts* Ucore_message_search_contacts::core_message_search_contacts(
			const FString ServerURL,
			const FString Token,
			const FString _searchtext,
			const int32 _onlymycourses)
{
	Ucore_message_search_contacts* Node = NewObject<Ucore_message_search_contacts>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_search_contacts&searchtext=" + _searchtext + "&onlymycourses=" + FString::FromInt(_onlymycourses);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_search_contacts::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_search_contacts::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_search_contacts::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_send_instant_messages* Ucore_message_send_instant_messages::core_message_send_instant_messages(
			const FString ServerURL,
			const FString Token,
			const int32 _messagestouserid,
			const FString _messagestext,
			const int32 _messagestextformat,
			const FString _messagesclientmsgid)
{
	Ucore_message_send_instant_messages* Node = NewObject<Ucore_message_send_instant_messages>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_send_instant_messages&messages[0][touserid]=" + FString::FromInt(_messagestouserid) + "&messages[0][text]=" + _messagestext + "&messages[0][textformat]=" + FString::FromInt(_messagestextformat) + "&messages[0][clientmsgid]=" + _messagesclientmsgid;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_send_instant_messages::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_send_instant_messages::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_send_instant_messages::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_send_messages_to_conversation* Ucore_message_send_messages_to_conversation::core_message_send_messages_to_conversation(
			const FString ServerURL,
			const FString Token,
			const int32 _conversationid,
			const FString _messagestext,
			const int32 _messagestextformat)
{
	Ucore_message_send_messages_to_conversation* Node = NewObject<Ucore_message_send_messages_to_conversation>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_send_messages_to_conversation&conversationid=" + FString::FromInt(_conversationid) + "&messages[0][text]=" + _messagestext + "&messages[0][textformat]=" + FString::FromInt(_messagestextformat);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_send_messages_to_conversation::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_send_messages_to_conversation::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_send_messages_to_conversation::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_set_favourite_conversations* Ucore_message_set_favourite_conversations::core_message_set_favourite_conversations(
			const FString ServerURL,
			const FString Token,
			const int32 _conversations,
			const int32 _userid)
{
	Ucore_message_set_favourite_conversations* Node = NewObject<Ucore_message_set_favourite_conversations>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_set_favourite_conversations&userid=" + FString::FromInt(_userid) + "&conversations[0]=" + FString::FromInt(_conversations);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_set_favourite_conversations::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_set_favourite_conversations::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_set_favourite_conversations::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_unblock_user* Ucore_message_unblock_user::core_message_unblock_user(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _unblockeduserid)
{
	Ucore_message_unblock_user* Node = NewObject<Ucore_message_unblock_user>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_unblock_user&userid=" + FString::FromInt(_userid) + "&unblockeduserid=" + FString::FromInt(_unblockeduserid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_unblock_user::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_unblock_user::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_unblock_user::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_unmute_conversations* Ucore_message_unmute_conversations::core_message_unmute_conversations(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _conversationids)
{
	Ucore_message_unmute_conversations* Node = NewObject<Ucore_message_unmute_conversations>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_unmute_conversations&userid=" + FString::FromInt(_userid) + "&conversationids[0]=" + FString::FromInt(_conversationids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_unmute_conversations::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_unmute_conversations::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_unmute_conversations::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_message_unset_favourite_conversations* Ucore_message_unset_favourite_conversations::core_message_unset_favourite_conversations(
			const FString ServerURL,
			const FString Token,
			const int32 _conversations,
			const int32 _userid)
{
	Ucore_message_unset_favourite_conversations* Node = NewObject<Ucore_message_unset_favourite_conversations>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_message_unset_favourite_conversations&userid=" + FString::FromInt(_userid) + "&conversations[0]=" + FString::FromInt(_conversations);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_message_unset_favourite_conversations::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_message_unset_favourite_conversations::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_message_unset_favourite_conversations::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_notes_create_notes* Ucore_notes_create_notes::core_notes_create_notes(
			const FString ServerURL,
			const FString Token,
			const int32 _notesuserid,
			const FString _notespublishstate,
			const int32 _notescourseid,
			const FString _notestext,
			const int32 _notesformat,
			const FString _notesclientnoteid)
{
	Ucore_notes_create_notes* Node = NewObject<Ucore_notes_create_notes>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_notes_create_notes&notes[0][userid]=" + FString::FromInt(_notesuserid) + "&notes[0][publishstate]=" + _notespublishstate + "&notes[0][courseid]=" + FString::FromInt(_notescourseid) + "&notes[0][text]=" + _notestext + "&notes[0][format]=" + FString::FromInt(_notesformat) + "&notes[0][clientnoteid]=" + _notesclientnoteid;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_notes_create_notes::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_notes_create_notes::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_notes_create_notes::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_notes_delete_notes* Ucore_notes_delete_notes::core_notes_delete_notes(
			const FString ServerURL,
			const FString Token,
			const int32 _notes)
{
	Ucore_notes_delete_notes* Node = NewObject<Ucore_notes_delete_notes>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_notes_delete_notes&notes[0]=" + FString::FromInt(_notes);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_notes_delete_notes::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_notes_delete_notes::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_notes_delete_notes::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_notes_get_course_notes* Ucore_notes_get_course_notes::core_notes_get_course_notes(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _userid)
{
	Ucore_notes_get_course_notes* Node = NewObject<Ucore_notes_get_course_notes>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_notes_get_course_notes&courseid=" + FString::FromInt(_courseid) + "&userid=" + FString::FromInt(_userid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_notes_get_course_notes::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_notes_get_course_notes::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_notes_get_course_notes::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_notes_get_notes* Ucore_notes_get_notes::core_notes_get_notes(
			const FString ServerURL,
			const FString Token,
			const int32 _notes)
{
	Ucore_notes_get_notes* Node = NewObject<Ucore_notes_get_notes>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_notes_get_notes&notes[0]=" + FString::FromInt(_notes);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_notes_get_notes::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_notes_get_notes::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_notes_get_notes::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_notes_update_notes* Ucore_notes_update_notes::core_notes_update_notes(
			const FString ServerURL,
			const FString Token,
			const int32 _notesid,
			const FString _notespublishstate,
			const FString _notestext,
			const int32 _notesformat)
{
	Ucore_notes_update_notes* Node = NewObject<Ucore_notes_update_notes>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_notes_update_notes&notes[0][id]=" + FString::FromInt(_notesid) + "&notes[0][publishstate]=" + _notespublishstate + "&notes[0][text]=" + _notestext + "&notes[0][format]=" + FString::FromInt(_notesformat);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_notes_update_notes::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_notes_update_notes::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_notes_update_notes::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_notes_view_notes* Ucore_notes_view_notes::core_notes_view_notes(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _userid)
{
	Ucore_notes_view_notes* Node = NewObject<Ucore_notes_view_notes>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_notes_view_notes&courseid=" + FString::FromInt(_courseid) + "&userid=" + FString::FromInt(_userid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_notes_view_notes::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_notes_view_notes::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_notes_view_notes::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_output_load_fontawesome_icon_system_map* Ucore_output_load_fontawesome_icon_system_map::core_output_load_fontawesome_icon_system_map(
			const FString ServerURL,
			const FString Token,
			const FString _themename)
{
	Ucore_output_load_fontawesome_icon_system_map* Node = NewObject<Ucore_output_load_fontawesome_icon_system_map>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_output_load_fontawesome_icon_system_map&themename=" + _themename;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_output_load_fontawesome_icon_system_map::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_output_load_fontawesome_icon_system_map::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_output_load_fontawesome_icon_system_map::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_output_load_template* Ucore_output_load_template::core_output_load_template(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const FString _template,
			const FString _themename,
			const int32 _includecomments)
{
	Ucore_output_load_template* Node = NewObject<Ucore_output_load_template>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_output_load_template&component=" + _component + "&template=" + _template + "&themename=" + _themename + "&includecomments=" + FString::FromInt(_includecomments);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_output_load_template::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_output_load_template::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_output_load_template::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_output_load_template_with_dependencies* Ucore_output_load_template_with_dependencies::core_output_load_template_with_dependencies(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const FString _template,
			const FString _themename,
			const int32 _includecomments,
			const FString _lang)
{
	Ucore_output_load_template_with_dependencies* Node = NewObject<Ucore_output_load_template_with_dependencies>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_output_load_template_with_dependencies&component=" + _component + "&template=" + _template + "&themename=" + _themename + "&includecomments=" + FString::FromInt(_includecomments) + "&lang=" + _lang;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_output_load_template_with_dependencies::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_output_load_template_with_dependencies::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_output_load_template_with_dependencies::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_payment_get_available_gateways* Ucore_payment_get_available_gateways::core_payment_get_available_gateways(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const FString _paymentarea,
			const int32 _itemid)
{
	Ucore_payment_get_available_gateways* Node = NewObject<Ucore_payment_get_available_gateways>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_payment_get_available_gateways&component=" + _component + "&paymentarea=" + _paymentarea + "&itemid=" + FString::FromInt(_itemid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_payment_get_available_gateways::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_payment_get_available_gateways::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_payment_get_available_gateways::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_question_get_random_question_summaries* Ucore_question_get_random_question_summaries::core_question_get_random_question_summaries(
			const FString ServerURL,
			const FString Token,
			const int32 _categoryid,
			const int32 _includesubcategories,
			const int32 _tagids,
			const int32 _contextid,
			const int32 _limit,
			const int32 _offset)
{
	Ucore_question_get_random_question_summaries* Node = NewObject<Ucore_question_get_random_question_summaries>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_question_get_random_question_summaries&categoryid=" + FString::FromInt(_categoryid) + "&includesubcategories=" + FString::FromInt(_includesubcategories) + "&tagids[0]=" + FString::FromInt(_tagids) + "&contextid=" + FString::FromInt(_contextid) + "&limit=" + FString::FromInt(_limit) + "&offset=" + FString::FromInt(_offset);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_question_get_random_question_summaries::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_question_get_random_question_summaries::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_question_get_random_question_summaries::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_question_update_flag* Ucore_question_update_flag::core_question_update_flag(
			const FString ServerURL,
			const FString Token,
			const int32 _qubaid,
			const int32 _questionid,
			const int32 _qaid,
			const int32 _slot,
			const FString _checksum,
			const int32 _newstate)
{
	Ucore_question_update_flag* Node = NewObject<Ucore_question_update_flag>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_question_update_flag&qubaid=" + FString::FromInt(_qubaid) + "&questionid=" + FString::FromInt(_questionid) + "&qaid=" + FString::FromInt(_qaid) + "&slot=" + FString::FromInt(_slot) + "&checksum=" + _checksum + "&newstate=" + FString::FromInt(_newstate);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_question_update_flag::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_question_update_flag::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_question_update_flag::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_rating_add_rating* Ucore_rating_add_rating::core_rating_add_rating(
			const FString ServerURL,
			const FString Token,
			const FString _contextlevel,
			const int32 _instanceid,
			const FString _component,
			const FString _ratingarea,
			const int32 _itemid,
			const int32 _scaleid,
			const int32 _rating,
			const int32 _rateduserid,
			const int32 _aggregation)
{
	Ucore_rating_add_rating* Node = NewObject<Ucore_rating_add_rating>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_rating_add_rating&contextlevel=" + _contextlevel + "&instanceid=" + FString::FromInt(_instanceid) + "&component=" + _component + "&ratingarea=" + _ratingarea + "&itemid=" + FString::FromInt(_itemid) + "&scaleid=" + FString::FromInt(_scaleid) + "&rating=" + FString::FromInt(_rating) + "&rateduserid=" + FString::FromInt(_rateduserid) + "&aggregation=" + FString::FromInt(_aggregation);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_rating_add_rating::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_rating_add_rating::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_rating_add_rating::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_rating_get_item_ratings* Ucore_rating_get_item_ratings::core_rating_get_item_ratings(
			const FString ServerURL,
			const FString Token,
			const FString _contextlevel,
			const int32 _instanceid,
			const FString _component,
			const FString _ratingarea,
			const int32 _itemid,
			const int32 _scaleid,
			const FString _sort)
{
	Ucore_rating_get_item_ratings* Node = NewObject<Ucore_rating_get_item_ratings>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_rating_get_item_ratings&contextlevel=" + _contextlevel + "&instanceid=" + FString::FromInt(_instanceid) + "&component=" + _component + "&ratingarea=" + _ratingarea + "&itemid=" + FString::FromInt(_itemid) + "&scaleid=" + FString::FromInt(_scaleid) + "&sort=" + _sort;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_rating_get_item_ratings::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_rating_get_item_ratings::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_rating_get_item_ratings::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_reportbuilder_audiences_delete* Ucore_reportbuilder_audiences_delete::core_reportbuilder_audiences_delete(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid,
			const int32 _instanceid)
{
	Ucore_reportbuilder_audiences_delete* Node = NewObject<Ucore_reportbuilder_audiences_delete>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_reportbuilder_audiences_delete&reportid=" + FString::FromInt(_reportid) + "&instanceid=" + FString::FromInt(_instanceid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_reportbuilder_audiences_delete::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_reportbuilder_audiences_delete::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_reportbuilder_audiences_delete::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_reportbuilder_columns_add* Ucore_reportbuilder_columns_add::core_reportbuilder_columns_add(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid,
			const FString _uniqueidentifier)
{
	Ucore_reportbuilder_columns_add* Node = NewObject<Ucore_reportbuilder_columns_add>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_reportbuilder_columns_add&reportid=" + FString::FromInt(_reportid) + "&uniqueidentifier=" + _uniqueidentifier;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_reportbuilder_columns_add::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_reportbuilder_columns_add::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_reportbuilder_columns_add::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_reportbuilder_columns_delete* Ucore_reportbuilder_columns_delete::core_reportbuilder_columns_delete(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid,
			const int32 _columnid)
{
	Ucore_reportbuilder_columns_delete* Node = NewObject<Ucore_reportbuilder_columns_delete>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_reportbuilder_columns_delete&reportid=" + FString::FromInt(_reportid) + "&columnid=" + FString::FromInt(_columnid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_reportbuilder_columns_delete::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_reportbuilder_columns_delete::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_reportbuilder_columns_delete::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_reportbuilder_columns_reorder* Ucore_reportbuilder_columns_reorder::core_reportbuilder_columns_reorder(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid,
			const int32 _columnid,
			const int32 _position)
{
	Ucore_reportbuilder_columns_reorder* Node = NewObject<Ucore_reportbuilder_columns_reorder>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_reportbuilder_columns_reorder&reportid=" + FString::FromInt(_reportid) + "&columnid=" + FString::FromInt(_columnid) + "&position=" + FString::FromInt(_position);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_reportbuilder_columns_reorder::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_reportbuilder_columns_reorder::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_reportbuilder_columns_reorder::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_reportbuilder_columns_sort_get* Ucore_reportbuilder_columns_sort_get::core_reportbuilder_columns_sort_get(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid)
{
	Ucore_reportbuilder_columns_sort_get* Node = NewObject<Ucore_reportbuilder_columns_sort_get>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_reportbuilder_columns_sort_get&reportid=" + FString::FromInt(_reportid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_reportbuilder_columns_sort_get::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_reportbuilder_columns_sort_get::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_reportbuilder_columns_sort_get::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_reportbuilder_columns_sort_reorder* Ucore_reportbuilder_columns_sort_reorder::core_reportbuilder_columns_sort_reorder(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid,
			const int32 _columnid,
			const int32 _position)
{
	Ucore_reportbuilder_columns_sort_reorder* Node = NewObject<Ucore_reportbuilder_columns_sort_reorder>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_reportbuilder_columns_sort_reorder&reportid=" + FString::FromInt(_reportid) + "&columnid=" + FString::FromInt(_columnid) + "&position=" + FString::FromInt(_position);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_reportbuilder_columns_sort_reorder::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_reportbuilder_columns_sort_reorder::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_reportbuilder_columns_sort_reorder::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_reportbuilder_columns_sort_toggle* Ucore_reportbuilder_columns_sort_toggle::core_reportbuilder_columns_sort_toggle(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid,
			const int32 _columnid,
			const int32 _enabled,
			const int32 _direction)
{
	Ucore_reportbuilder_columns_sort_toggle* Node = NewObject<Ucore_reportbuilder_columns_sort_toggle>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_reportbuilder_columns_sort_toggle&reportid=" + FString::FromInt(_reportid) + "&columnid=" + FString::FromInt(_columnid) + "&enabled=" + FString::FromInt(_enabled) + "&direction=" + FString::FromInt(_direction);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_reportbuilder_columns_sort_toggle::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_reportbuilder_columns_sort_toggle::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_reportbuilder_columns_sort_toggle::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_reportbuilder_conditions_add* Ucore_reportbuilder_conditions_add::core_reportbuilder_conditions_add(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid,
			const FString _uniqueidentifier)
{
	Ucore_reportbuilder_conditions_add* Node = NewObject<Ucore_reportbuilder_conditions_add>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_reportbuilder_conditions_add&reportid=" + FString::FromInt(_reportid) + "&uniqueidentifier=" + _uniqueidentifier;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_reportbuilder_conditions_add::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_reportbuilder_conditions_add::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_reportbuilder_conditions_add::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_reportbuilder_conditions_delete* Ucore_reportbuilder_conditions_delete::core_reportbuilder_conditions_delete(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid,
			const int32 _conditionid)
{
	Ucore_reportbuilder_conditions_delete* Node = NewObject<Ucore_reportbuilder_conditions_delete>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_reportbuilder_conditions_delete&reportid=" + FString::FromInt(_reportid) + "&conditionid=" + FString::FromInt(_conditionid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_reportbuilder_conditions_delete::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_reportbuilder_conditions_delete::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_reportbuilder_conditions_delete::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_reportbuilder_conditions_reorder* Ucore_reportbuilder_conditions_reorder::core_reportbuilder_conditions_reorder(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid,
			const int32 _conditionid,
			const int32 _position)
{
	Ucore_reportbuilder_conditions_reorder* Node = NewObject<Ucore_reportbuilder_conditions_reorder>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_reportbuilder_conditions_reorder&reportid=" + FString::FromInt(_reportid) + "&conditionid=" + FString::FromInt(_conditionid) + "&position=" + FString::FromInt(_position);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_reportbuilder_conditions_reorder::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_reportbuilder_conditions_reorder::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_reportbuilder_conditions_reorder::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_reportbuilder_conditions_reset* Ucore_reportbuilder_conditions_reset::core_reportbuilder_conditions_reset(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid)
{
	Ucore_reportbuilder_conditions_reset* Node = NewObject<Ucore_reportbuilder_conditions_reset>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_reportbuilder_conditions_reset&reportid=" + FString::FromInt(_reportid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_reportbuilder_conditions_reset::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_reportbuilder_conditions_reset::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_reportbuilder_conditions_reset::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_reportbuilder_filters_add* Ucore_reportbuilder_filters_add::core_reportbuilder_filters_add(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid,
			const FString _uniqueidentifier)
{
	Ucore_reportbuilder_filters_add* Node = NewObject<Ucore_reportbuilder_filters_add>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_reportbuilder_filters_add&reportid=" + FString::FromInt(_reportid) + "&uniqueidentifier=" + _uniqueidentifier;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_reportbuilder_filters_add::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_reportbuilder_filters_add::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_reportbuilder_filters_add::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_reportbuilder_filters_delete* Ucore_reportbuilder_filters_delete::core_reportbuilder_filters_delete(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid,
			const int32 _filterid)
{
	Ucore_reportbuilder_filters_delete* Node = NewObject<Ucore_reportbuilder_filters_delete>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_reportbuilder_filters_delete&reportid=" + FString::FromInt(_reportid) + "&filterid=" + FString::FromInt(_filterid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_reportbuilder_filters_delete::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_reportbuilder_filters_delete::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_reportbuilder_filters_delete::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_reportbuilder_filters_reorder* Ucore_reportbuilder_filters_reorder::core_reportbuilder_filters_reorder(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid,
			const int32 _filterid,
			const int32 _position)
{
	Ucore_reportbuilder_filters_reorder* Node = NewObject<Ucore_reportbuilder_filters_reorder>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_reportbuilder_filters_reorder&reportid=" + FString::FromInt(_reportid) + "&filterid=" + FString::FromInt(_filterid) + "&position=" + FString::FromInt(_position);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_reportbuilder_filters_reorder::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_reportbuilder_filters_reorder::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_reportbuilder_filters_reorder::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_reportbuilder_filters_reset* Ucore_reportbuilder_filters_reset::core_reportbuilder_filters_reset(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid,
			const FString _parameters)
{
	Ucore_reportbuilder_filters_reset* Node = NewObject<Ucore_reportbuilder_filters_reset>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_reportbuilder_filters_reset&reportid=" + FString::FromInt(_reportid) + "&parameters=" + _parameters;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_reportbuilder_filters_reset::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_reportbuilder_filters_reset::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_reportbuilder_filters_reset::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_reportbuilder_list_reports* Ucore_reportbuilder_list_reports::core_reportbuilder_list_reports(
			const FString ServerURL,
			const FString Token,
			const int32 _page,
			const int32 _perpage)
{
	Ucore_reportbuilder_list_reports* Node = NewObject<Ucore_reportbuilder_list_reports>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_reportbuilder_list_reports&page=" + FString::FromInt(_page) + "&perpage=" + FString::FromInt(_perpage);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_reportbuilder_list_reports::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_reportbuilder_list_reports::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_reportbuilder_list_reports::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_reportbuilder_reports_delete* Ucore_reportbuilder_reports_delete::core_reportbuilder_reports_delete(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid)
{
	Ucore_reportbuilder_reports_delete* Node = NewObject<Ucore_reportbuilder_reports_delete>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_reportbuilder_reports_delete&reportid=" + FString::FromInt(_reportid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_reportbuilder_reports_delete::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_reportbuilder_reports_delete::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_reportbuilder_reports_delete::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_reportbuilder_reports_get* Ucore_reportbuilder_reports_get::core_reportbuilder_reports_get(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid,
			const int32 _editmode)
{
	Ucore_reportbuilder_reports_get* Node = NewObject<Ucore_reportbuilder_reports_get>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_reportbuilder_reports_get&reportid=" + FString::FromInt(_reportid) + "&editmode=" + FString::FromInt(_editmode);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_reportbuilder_reports_get::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_reportbuilder_reports_get::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_reportbuilder_reports_get::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_reportbuilder_retrieve_report* Ucore_reportbuilder_retrieve_report::core_reportbuilder_retrieve_report(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid,
			const int32 _page,
			const int32 _perpage)
{
	Ucore_reportbuilder_retrieve_report* Node = NewObject<Ucore_reportbuilder_retrieve_report>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_reportbuilder_retrieve_report&reportid=" + FString::FromInt(_reportid) + "&page=" + FString::FromInt(_page) + "&perpage=" + FString::FromInt(_perpage);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_reportbuilder_retrieve_report::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_reportbuilder_retrieve_report::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_reportbuilder_retrieve_report::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_reportbuilder_schedules_delete* Ucore_reportbuilder_schedules_delete::core_reportbuilder_schedules_delete(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid,
			const int32 _scheduleid)
{
	Ucore_reportbuilder_schedules_delete* Node = NewObject<Ucore_reportbuilder_schedules_delete>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_reportbuilder_schedules_delete&reportid=" + FString::FromInt(_reportid) + "&scheduleid=" + FString::FromInt(_scheduleid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_reportbuilder_schedules_delete::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_reportbuilder_schedules_delete::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_reportbuilder_schedules_delete::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_reportbuilder_schedules_send* Ucore_reportbuilder_schedules_send::core_reportbuilder_schedules_send(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid,
			const int32 _scheduleid)
{
	Ucore_reportbuilder_schedules_send* Node = NewObject<Ucore_reportbuilder_schedules_send>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_reportbuilder_schedules_send&reportid=" + FString::FromInt(_reportid) + "&scheduleid=" + FString::FromInt(_scheduleid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_reportbuilder_schedules_send::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_reportbuilder_schedules_send::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_reportbuilder_schedules_send::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_reportbuilder_schedules_toggle* Ucore_reportbuilder_schedules_toggle::core_reportbuilder_schedules_toggle(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid,
			const int32 _scheduleid,
			const int32 _enabled)
{
	Ucore_reportbuilder_schedules_toggle* Node = NewObject<Ucore_reportbuilder_schedules_toggle>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_reportbuilder_schedules_toggle&reportid=" + FString::FromInt(_reportid) + "&scheduleid=" + FString::FromInt(_scheduleid) + "&enabled=" + FString::FromInt(_enabled);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_reportbuilder_schedules_toggle::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_reportbuilder_schedules_toggle::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_reportbuilder_schedules_toggle::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_reportbuilder_set_filters* Ucore_reportbuilder_set_filters::core_reportbuilder_set_filters(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid,
			const FString _values,
			const FString _parameters)
{
	Ucore_reportbuilder_set_filters* Node = NewObject<Ucore_reportbuilder_set_filters>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_reportbuilder_set_filters&reportid=" + FString::FromInt(_reportid) + "&parameters=" + _parameters + "&values=" + _values;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_reportbuilder_set_filters::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_reportbuilder_set_filters::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_reportbuilder_set_filters::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_reportbuilder_view_report* Ucore_reportbuilder_view_report::core_reportbuilder_view_report(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid)
{
	Ucore_reportbuilder_view_report* Node = NewObject<Ucore_reportbuilder_view_report>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_reportbuilder_view_report&reportid=" + FString::FromInt(_reportid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_reportbuilder_view_report::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_reportbuilder_view_report::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_reportbuilder_view_report::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_role_assign_roles* Ucore_role_assign_roles::core_role_assign_roles(
			const FString ServerURL,
			const FString Token,
			const int32 _assignmentsroleid,
			const int32 _assignmentsuserid,
			const int32 _assignmentscontextid,
			const FString _assignmentscontextlevel,
			const int32 _assignmentsinstanceid)
{
	Ucore_role_assign_roles* Node = NewObject<Ucore_role_assign_roles>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_role_assign_roles&assignments[0][roleid]=" + FString::FromInt(_assignmentsroleid) + "&assignments[0][userid]=" + FString::FromInt(_assignmentsuserid) + "&assignments[0][contextid]=" + FString::FromInt(_assignmentscontextid) + "&assignments[0][contextlevel]=" + _assignmentscontextlevel + "&assignments[0][instanceid]=" + FString::FromInt(_assignmentsinstanceid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_role_assign_roles::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_role_assign_roles::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_role_assign_roles::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_role_unassign_roles* Ucore_role_unassign_roles::core_role_unassign_roles(
			const FString ServerURL,
			const FString Token,
			const int32 _unassignmentsroleid,
			const int32 _unassignmentsuserid,
			const int32 _unassignmentscontextid,
			const FString _unassignmentscontextlevel,
			const int32 _unassignmentsinstanceid)
{
	Ucore_role_unassign_roles* Node = NewObject<Ucore_role_unassign_roles>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_role_unassign_roles&unassignments[0][roleid]=" + FString::FromInt(_unassignmentsroleid) + "&unassignments[0][userid]=" + FString::FromInt(_unassignmentsuserid) + "&unassignments[0][contextid]=" + FString::FromInt(_unassignmentscontextid) + "&unassignments[0][contextlevel]=" + _unassignmentscontextlevel + "&unassignments[0][instanceid]=" + FString::FromInt(_unassignmentsinstanceid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_role_unassign_roles::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_role_unassign_roles::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_role_unassign_roles::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_search_get_relevant_users* Ucore_search_get_relevant_users::core_search_get_relevant_users(
			const FString ServerURL,
			const FString Token,
			const FString _query,
			const int32 _courseid)
{
	Ucore_search_get_relevant_users* Node = NewObject<Ucore_search_get_relevant_users>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_search_get_relevant_users&query=" + _query + "&courseid=" + FString::FromInt(_courseid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_search_get_relevant_users::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_search_get_relevant_users::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_search_get_relevant_users::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_session_time_remaining* Ucore_session_time_remaining::core_session_time_remaining(
			const FString ServerURL,
			const FString Token)
{
	Ucore_session_time_remaining* Node = NewObject<Ucore_session_time_remaining>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_session_time_remaining";

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_session_time_remaining::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_session_time_remaining::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_session_time_remaining::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_session_touch* Ucore_session_touch::core_session_touch(
			const FString ServerURL,
			const FString Token)
{
	Ucore_session_touch* Node = NewObject<Ucore_session_touch>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_session_touch";

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_session_touch::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_session_touch::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_session_touch::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_table_get_dynamic_table_content* Ucore_table_get_dynamic_table_content::core_table_get_dynamic_table_content(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const FString _handler,
			const FString _uniqueid,
			const int32 _jointype,
			const FString _firstinitial,
			const FString _lastinitial,
			const int32 _pagenumber,
			const int32 _pagesize,
			const FString _hiddencolumns,
			const int32 _resetpreferences,
			const FString _sortdatasortby,
			const FString _sortdatasortorder,
			const FString _filtersname,
			const int32 _filtersjointype,
			const FString _filtersvalues)
{
	Ucore_table_get_dynamic_table_content* Node = NewObject<Ucore_table_get_dynamic_table_content>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_table_get_dynamic_table_content&component=" + _component + "&handler=" + _handler + "&uniqueid=" + _uniqueid + "&sortdata[0][sortby]=" + _sortdatasortby + "&sortdata[0][sortorder]=" + _sortdatasortorder + "&filters[0][name]=" + _filtersname + "&filters[0][jointype]=" + FString::FromInt(_filtersjointype) + "&filters[0][values][0]=" + _filtersvalues + "&jointype=" + FString::FromInt(_jointype) + "&firstinitial=" + _firstinitial + "&lastinitial=" + _lastinitial + "&pagenumber=" + FString::FromInt(_pagenumber) + "&pagesize=" + FString::FromInt(_pagesize) + "&hiddencolumns[0]=" + _hiddencolumns + "&resetpreferences=" + FString::FromInt(_resetpreferences);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_table_get_dynamic_table_content::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_table_get_dynamic_table_content::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_table_get_dynamic_table_content::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_tag_get_tag_areas* Ucore_tag_get_tag_areas::core_tag_get_tag_areas(
			const FString ServerURL,
			const FString Token)
{
	Ucore_tag_get_tag_areas* Node = NewObject<Ucore_tag_get_tag_areas>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_tag_get_tag_areas";

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_tag_get_tag_areas::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_tag_get_tag_areas::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_tag_get_tag_areas::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_tag_get_tag_cloud* Ucore_tag_get_tag_cloud::core_tag_get_tag_cloud(
			const FString ServerURL,
			const FString Token,
			const int32 _tagcollid,
			const int32 _isstandard,
			const int32 _limit,
			const FString _sort,
			const FString _search,
			const int32 _fromctx,
			const int32 _ctx,
			const int32 _rec)
{
	Ucore_tag_get_tag_cloud* Node = NewObject<Ucore_tag_get_tag_cloud>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_tag_get_tag_cloud&tagcollid=" + FString::FromInt(_tagcollid) + "&isstandard=" + FString::FromInt(_isstandard) + "&limit=" + FString::FromInt(_limit) + "&sort=" + _sort + "&search=" + _search + "&fromctx=" + FString::FromInt(_fromctx) + "&ctx=" + FString::FromInt(_ctx) + "&rec=" + FString::FromInt(_rec);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_tag_get_tag_cloud::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_tag_get_tag_cloud::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_tag_get_tag_cloud::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_tag_get_tag_collections* Ucore_tag_get_tag_collections::core_tag_get_tag_collections(
			const FString ServerURL,
			const FString Token)
{
	Ucore_tag_get_tag_collections* Node = NewObject<Ucore_tag_get_tag_collections>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_tag_get_tag_collections";

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_tag_get_tag_collections::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_tag_get_tag_collections::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_tag_get_tag_collections::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_tag_get_tagindex* Ucore_tag_get_tagindex::core_tag_get_tagindex(
			const FString ServerURL,
			const FString Token,
			const int32 _tagindextc,
			const FString _tagindextag,
			const int32 _tagindexta,
			const int32 _tagindexexcl,
			const int32 _tagindexfrom,
			const int32 _tagindexctx,
			const int32 _tagindexrec,
			const int32 _tagindexpage)
{
	Ucore_tag_get_tagindex* Node = NewObject<Ucore_tag_get_tagindex>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_tag_get_tagindex&tagindex[tag]=" + _tagindextag + "&tagindex[tc]=" + FString::FromInt(_tagindextc) + "&tagindex[ta]=" + FString::FromInt(_tagindexta) + "&tagindex[excl]=" + FString::FromInt(_tagindexexcl) + "&tagindex[from]=" + FString::FromInt(_tagindexfrom) + "&tagindex[ctx]=" + FString::FromInt(_tagindexctx) + "&tagindex[rec]=" + FString::FromInt(_tagindexrec) + "&tagindex[page]=" + FString::FromInt(_tagindexpage);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_tag_get_tagindex::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_tag_get_tagindex::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_tag_get_tagindex::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_tag_get_tagindex_per_area* Ucore_tag_get_tagindex_per_area::core_tag_get_tagindex_per_area(
			const FString ServerURL,
			const FString Token,
			const int32 _tagindexid,
			const FString _tagindextag,
			const int32 _tagindextc,
			const int32 _tagindexta,
			const int32 _tagindexexcl,
			const int32 _tagindexfrom,
			const int32 _tagindexctx,
			const int32 _tagindexrec,
			const int32 _tagindexpage)
{
	Ucore_tag_get_tagindex_per_area* Node = NewObject<Ucore_tag_get_tagindex_per_area>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_tag_get_tagindex_per_area&tagindex[id]=" + FString::FromInt(_tagindexid) + "&tagindex[tag]=" + _tagindextag + "&tagindex[tc]=" + FString::FromInt(_tagindextc) + "&tagindex[ta]=" + FString::FromInt(_tagindexta) + "&tagindex[excl]=" + FString::FromInt(_tagindexexcl) + "&tagindex[from]=" + FString::FromInt(_tagindexfrom) + "&tagindex[ctx]=" + FString::FromInt(_tagindexctx) + "&tagindex[rec]=" + FString::FromInt(_tagindexrec) + "&tagindex[page]=" + FString::FromInt(_tagindexpage);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_tag_get_tagindex_per_area::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_tag_get_tagindex_per_area::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_tag_get_tagindex_per_area::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_tag_get_tags* Ucore_tag_get_tags::core_tag_get_tags(
			const FString ServerURL,
			const FString Token,
			const int32 _tagsid)
{
	Ucore_tag_get_tags* Node = NewObject<Ucore_tag_get_tags>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_tag_get_tags&tags[0][id]=" + FString::FromInt(_tagsid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_tag_get_tags::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_tag_get_tags::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_tag_get_tags::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_tag_update_tags* Ucore_tag_update_tags::core_tag_update_tags(
			const FString ServerURL,
			const FString Token,
			const int32 _tagsid,
			const FString _tagsrawname,
			const FString _tagsdescription,
			const int32 _tagsdescriptionformat,
			const int32 _tagsflag,
			const int32 _tagsofficial,
			const int32 _tagsisstandard)
{
	Ucore_tag_update_tags* Node = NewObject<Ucore_tag_update_tags>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_tag_update_tags&tags[0][id]=" + FString::FromInt(_tagsid) + "&tags[0][rawname]=" + _tagsrawname + "&tags[0][description]=" + _tagsdescription + "&tags[0][descriptionformat]=" + FString::FromInt(_tagsdescriptionformat) + "&tags[0][flag]=" + FString::FromInt(_tagsflag) + "&tags[0][official]=" + FString::FromInt(_tagsofficial) + "&tags[0][isstandard]=" + FString::FromInt(_tagsisstandard);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_tag_update_tags::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_tag_update_tags::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_tag_update_tags::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_update_inplace_editable* Ucore_update_inplace_editable::core_update_inplace_editable(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const FString _itemtype,
			const FString _itemid,
			const FString _value)
{
	Ucore_update_inplace_editable* Node = NewObject<Ucore_update_inplace_editable>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_update_inplace_editable&component=" + _component + "&itemtype=" + _itemtype + "&itemid=" + _itemid + "&value=" + _value;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_update_inplace_editable::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_update_inplace_editable::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_update_inplace_editable::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_user_add_user_device* Ucore_user_add_user_device::core_user_add_user_device(
			const FString ServerURL,
			const FString Token,
			const FString _appid,
			const FString _name,
			const FString _model,
			const FString _platform,
			const FString _version,
			const FString _pushid,
			const FString _uuid)
{
	Ucore_user_add_user_device* Node = NewObject<Ucore_user_add_user_device>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_user_add_user_device&appid=" + _appid + "&name=" + _name + "&model=" + _model + "&platform=" + _platform + "&version=" + _version + "&pushid=" + _pushid + "&uuid=" + _uuid;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_user_add_user_device::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_user_add_user_device::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_user_add_user_device::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_user_add_user_private_files* Ucore_user_add_user_private_files::core_user_add_user_private_files(
			const FString ServerURL,
			const FString Token,
			const int32 _draftid)
{
	Ucore_user_add_user_private_files* Node = NewObject<Ucore_user_add_user_private_files>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_user_add_user_private_files&draftid=" + FString::FromInt(_draftid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_user_add_user_private_files::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_user_add_user_private_files::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_user_add_user_private_files::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_user_agree_site_policy* Ucore_user_agree_site_policy::core_user_agree_site_policy(
			const FString ServerURL,
			const FString Token)
{
	Ucore_user_agree_site_policy* Node = NewObject<Ucore_user_agree_site_policy>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_user_agree_site_policy";

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_user_agree_site_policy::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_user_agree_site_policy::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_user_agree_site_policy::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_user_create_users* Ucore_user_create_users::core_user_create_users(
			const FString ServerURL,
			const FString Token,
			const FString _usersusername,
			const FString _usersemail,
			const int32 _userscreatepassword,
			const FString _usersauth,
			const FString _userspassword,
			const FString _usersfirstname,
			const FString _userslastname,
			const int32 _usersmaildisplay,
			const FString _userscity,
			const FString _userscountry,
			const FString _userstimezone,
			const FString _usersdescription,
			const FString _usersfirstnamephonetic,
			const FString _userslastnamephonetic,
			const FString _usersmiddlename,
			const FString _usersalternatename,
			const FString _usersinterests,
			const FString _usersidnumber,
			const FString _usersinstitution,
			const FString _usersdepartment,
			const FString _usersphone1,
			const FString _usersphone2,
			const FString _usersaddress,
			const FString _userslang,
			const FString _userscalendartype,
			const FString _userstheme,
			const int32 _usersmailformat,
			const FString _userscustomfieldstype,
			const FString _userscustomfieldsvalue,
			const FString _userspreferencestype,
			const FString _userspreferencesvalue)
{
	Ucore_user_create_users* Node = NewObject<Ucore_user_create_users>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_user_create_users&users[0][createpassword]=" + FString::FromInt(_userscreatepassword) + "&users[0][username]=" + _usersusername + "&users[0][auth]=" + _usersauth + "&users[0][password]=" + _userspassword + "&users[0][firstname]=" + _usersfirstname + "&users[0][lastname]=" + _userslastname + "&users[0][email]=" + _usersemail + "&users[0][maildisplay]=" + FString::FromInt(_usersmaildisplay) + "&users[0][city]=" + _userscity + "&users[0][country]=" + _userscountry + "&users[0][timezone]=" + _userstimezone + "&users[0][description]=" + _usersdescription + "&users[0][firstnamephonetic]=" + _usersfirstnamephonetic + "&users[0][lastnamephonetic]=" + _userslastnamephonetic + "&users[0][middlename]=" + _usersmiddlename + "&users[0][alternatename]=" + _usersalternatename + "&users[0][interests]=" + _usersinterests + "&users[0][idnumber]=" + _usersidnumber + "&users[0][institution]=" + _usersinstitution + "&users[0][department]=" + _usersdepartment + "&users[0][phone1]=" + _usersphone1 + "&users[0][phone2]=" + _usersphone2 + "&users[0][address]=" + _usersaddress + "&users[0][lang]=" + _userslang + "&users[0][calendartype]=" + _userscalendartype + "&users[0][theme]=" + _userstheme + "&users[0][mailformat]=" + FString::FromInt(_usersmailformat) + "&users[0][customfields][0][type]=" + _userscustomfieldstype + "&users[0][customfields][0][value]=" + _userscustomfieldsvalue + "&users[0][preferences][0][type]=" + _userspreferencestype + "&users[0][preferences][0][value]=" + _userspreferencesvalue;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_user_create_users::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_user_create_users::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_user_create_users::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_user_delete_users* Ucore_user_delete_users::core_user_delete_users(
			const FString ServerURL,
			const FString Token,
			const int32 _userids)
{
	Ucore_user_delete_users* Node = NewObject<Ucore_user_delete_users>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_user_delete_users&userids[0]=" + FString::FromInt(_userids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_user_delete_users::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_user_delete_users::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_user_delete_users::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_user_get_course_user_profiles* Ucore_user_get_course_user_profiles::core_user_get_course_user_profiles(
			const FString ServerURL,
			const FString Token,
			const int32 _userlistuserid,
			const int32 _userlistcourseid)
{
	Ucore_user_get_course_user_profiles* Node = NewObject<Ucore_user_get_course_user_profiles>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_user_get_course_user_profiles&userlist[0][userid]=" + FString::FromInt(_userlistuserid) + "&userlist[0][courseid]=" + FString::FromInt(_userlistcourseid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_user_get_course_user_profiles::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_user_get_course_user_profiles::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_user_get_course_user_profiles::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_user_get_private_files_info* Ucore_user_get_private_files_info::core_user_get_private_files_info(
			const FString ServerURL,
			const FString Token,
			const int32 _userid)
{
	Ucore_user_get_private_files_info* Node = NewObject<Ucore_user_get_private_files_info>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_user_get_private_files_info&userid=" + FString::FromInt(_userid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_user_get_private_files_info::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_user_get_private_files_info::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_user_get_private_files_info::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_user_get_user_preferences* Ucore_user_get_user_preferences::core_user_get_user_preferences(
			const FString ServerURL,
			const FString Token,
			const FString _name,
			const int32 _userid)
{
	Ucore_user_get_user_preferences* Node = NewObject<Ucore_user_get_user_preferences>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_user_get_user_preferences&name=" + _name + "&userid=" + FString::FromInt(_userid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_user_get_user_preferences::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_user_get_user_preferences::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_user_get_user_preferences::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_user_get_users* Ucore_user_get_users::core_user_get_users(
			const FString ServerURL,
			const FString Token,
			const FString _criteriakey,
			const FString _criteriavalue)
{
	Ucore_user_get_users* Node = NewObject<Ucore_user_get_users>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_user_get_users&criteria[0][key]=" + _criteriakey + "&criteria[0][value]=" + _criteriavalue;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_user_get_users::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_user_get_users::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_user_get_users::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_user_get_users_by_field* Ucore_user_get_users_by_field::core_user_get_users_by_field(
			const FString ServerURL,
			const FString Token,
			const FString _field,
			const FString _values)
{
	Ucore_user_get_users_by_field* Node = NewObject<Ucore_user_get_users_by_field>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_user_get_users_by_field&field=" + _field + "&values[0]=" + _values;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_user_get_users_by_field::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_user_get_users_by_field::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_user_get_users_by_field::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_user_remove_user_device* Ucore_user_remove_user_device::core_user_remove_user_device(
			const FString ServerURL,
			const FString Token,
			const FString _uuid,
			const FString _appid)
{
	Ucore_user_remove_user_device* Node = NewObject<Ucore_user_remove_user_device>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_user_remove_user_device&uuid=" + _uuid + "&appid=" + _appid;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_user_remove_user_device::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_user_remove_user_device::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_user_remove_user_device::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_user_search_identity* Ucore_user_search_identity::core_user_search_identity(
			const FString ServerURL,
			const FString Token,
			const FString _field,
			const FString _values)
{
	Ucore_user_search_identity* Node = NewObject<Ucore_user_search_identity>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_user_search_identity&field=" + _field + "&values[0]=" + _values;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_user_search_identity::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_user_search_identity::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_user_search_identity::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_user_set_user_preferences* Ucore_user_set_user_preferences::core_user_set_user_preferences(
			const FString ServerURL,
			const FString Token,
			const FString _preferencesname,
			const FString _preferencesvalue,
			const int32 _preferencesuserid)
{
	Ucore_user_set_user_preferences* Node = NewObject<Ucore_user_set_user_preferences>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_user_set_user_preferences&preferences[0][name]=" + _preferencesname + "&preferences[0][value]=" + _preferencesvalue + "&preferences[0][userid]=" + FString::FromInt(_preferencesuserid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_user_set_user_preferences::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_user_set_user_preferences::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_user_set_user_preferences::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_user_update_picture* Ucore_user_update_picture::core_user_update_picture(
			const FString ServerURL,
			const FString Token,
			const int32 _draftitemid,
			const int32 _delete,
			const int32 _userid)
{
	Ucore_user_update_picture* Node = NewObject<Ucore_user_update_picture>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_user_update_picture&draftitemid=" + FString::FromInt(_draftitemid) + "&delete=" + FString::FromInt(_delete) + "&userid=" + FString::FromInt(_userid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_user_update_picture::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_user_update_picture::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_user_update_picture::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_user_update_user_preferences* Ucore_user_update_user_preferences::core_user_update_user_preferences(
			const FString ServerURL,
			const FString Token,
			const FString _preferencestype,
			const int32 _userid,
			const int32 _emailstop,
			const FString _preferencesvalue)
{
	Ucore_user_update_user_preferences* Node = NewObject<Ucore_user_update_user_preferences>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_user_update_user_preferences&userid=" + FString::FromInt(_userid) + "&emailstop=" + FString::FromInt(_emailstop) + "&preferences[0][type]=" + _preferencestype + "&preferences[0][value]=" + _preferencesvalue;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_user_update_user_preferences::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_user_update_user_preferences::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_user_update_user_preferences::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_user_update_users* Ucore_user_update_users::core_user_update_users(
			const FString ServerURL,
			const FString Token,
			const int32 _usersid,
			const FString _usersusername,
			const FString _usersauth,
			const int32 _userssuspended,
			const FString _userspassword,
			const FString _usersfirstname,
			const FString _userslastname,
			const FString _usersemail,
			const int32 _usersmaildisplay,
			const FString _userscity,
			const FString _userscountry,
			const FString _userstimezone,
			const FString _usersdescription,
			const int32 _usersuserpicture,
			const FString _usersfirstnamephonetic,
			const FString _userslastnamephonetic,
			const FString _usersmiddlename,
			const FString _usersalternatename,
			const FString _usersinterests,
			const FString _usersidnumber,
			const FString _usersinstitution,
			const FString _usersdepartment,
			const FString _usersphone1,
			const FString _usersphone2,
			const FString _usersaddress,
			const FString _userslang,
			const FString _userscalendartype,
			const FString _userstheme,
			const int32 _usersmailformat,
			const FString _userscustomfieldstype,
			const FString _userscustomfieldsvalue,
			const FString _userspreferencestype,
			const FString _userspreferencesvalue)
{
	Ucore_user_update_users* Node = NewObject<Ucore_user_update_users>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_user_update_users&users[0][id]=" + FString::FromInt(_usersid) + "&users[0][username]=" + _usersusername + "&users[0][auth]=" + _usersauth + "&users[0][suspended]=" + FString::FromInt(_userssuspended) + "&users[0][password]=" + _userspassword + "&users[0][firstname]=" + _usersfirstname + "&users[0][lastname]=" + _userslastname + "&users[0][email]=" + _usersemail + "&users[0][maildisplay]=" + FString::FromInt(_usersmaildisplay) + "&users[0][city]=" + _userscity + "&users[0][country]=" + _userscountry + "&users[0][timezone]=" + _userstimezone + "&users[0][description]=" + _usersdescription + "&users[0][userpicture]=" + FString::FromInt(_usersuserpicture) + "&users[0][firstnamephonetic]=" + _usersfirstnamephonetic + "&users[0][lastnamephonetic]=" + _userslastnamephonetic + "&users[0][middlename]=" + _usersmiddlename + "&users[0][alternatename]=" + _usersalternatename + "&users[0][interests]=" + _usersinterests + "&users[0][idnumber]=" + _usersidnumber + "&users[0][institution]=" + _usersinstitution + "&users[0][department]=" + _usersdepartment + "&users[0][phone1]=" + _usersphone1 + "&users[0][phone2]=" + _usersphone2 + "&users[0][address]=" + _usersaddress + "&users[0][lang]=" + _userslang + "&users[0][calendartype]=" + _userscalendartype + "&users[0][theme]=" + _userstheme + "&users[0][mailformat]=" + FString::FromInt(_usersmailformat) + "&users[0][customfields][0][type]=" + _userscustomfieldstype + "&users[0][customfields][0][value]=" + _userscustomfieldsvalue + "&users[0][preferences][0][type]=" + _userspreferencestype + "&users[0][preferences][0][value]=" + _userspreferencesvalue;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_user_update_users::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_user_update_users::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_user_update_users::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_user_view_user_list* Ucore_user_view_user_list::core_user_view_user_list(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid)
{
	Ucore_user_view_user_list* Node = NewObject<Ucore_user_view_user_list>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_user_view_user_list&courseid=" + FString::FromInt(_courseid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_user_view_user_list::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_user_view_user_list::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_user_view_user_list::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_user_view_user_profile* Ucore_user_view_user_profile::core_user_view_user_profile(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _courseid)
{
	Ucore_user_view_user_profile* Node = NewObject<Ucore_user_view_user_profile>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_user_view_user_profile&userid=" + FString::FromInt(_userid) + "&courseid=" + FString::FromInt(_courseid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_user_view_user_profile::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_user_view_user_profile::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_user_view_user_profile::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_webservice_get_site_info* Ucore_webservice_get_site_info::core_webservice_get_site_info(
			const FString ServerURL,
			const FString Token,
			const FString _serviceshortnames)
{
	Ucore_webservice_get_site_info* Node = NewObject<Ucore_webservice_get_site_info>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_webservice_get_site_info&serviceshortnames[0]=" + _serviceshortnames;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_webservice_get_site_info::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_webservice_get_site_info::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_webservice_get_site_info::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ucore_xapi_statement_post* Ucore_xapi_statement_post::core_xapi_statement_post(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const FString _requestjson)
{
	Ucore_xapi_statement_post* Node = NewObject<Ucore_xapi_statement_post>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=core_xapi_statement_post&component=" + _component + "&requestjson=" + _requestjson;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ucore_xapi_statement_post::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ucore_xapi_statement_post::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ucore_xapi_statement_post::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Uenrol_guest_get_instance_info* Uenrol_guest_get_instance_info::enrol_guest_get_instance_info(
			const FString ServerURL,
			const FString Token,
			const int32 _instanceid)
{
	Uenrol_guest_get_instance_info* Node = NewObject<Uenrol_guest_get_instance_info>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=enrol_guest_get_instance_info&instanceid=" + FString::FromInt(_instanceid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Uenrol_guest_get_instance_info::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Uenrol_guest_get_instance_info::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Uenrol_guest_get_instance_info::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Uenrol_manual_enrol_users* Uenrol_manual_enrol_users::enrol_manual_enrol_users(
			const FString ServerURL,
			const FString Token,
			const int32 _enrolmentsroleid,
			const int32 _enrolmentsuserid,
			const int32 _enrolmentscourseid,
			const int32 _enrolmentstimestart,
			const int32 _enrolmentstimeend,
			const int32 _enrolmentssuspend)
{
	Uenrol_manual_enrol_users* Node = NewObject<Uenrol_manual_enrol_users>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=enrol_manual_enrol_users&enrolments[0][roleid]=" + FString::FromInt(_enrolmentsroleid) + "&enrolments[0][userid]=" + FString::FromInt(_enrolmentsuserid) + "&enrolments[0][courseid]=" + FString::FromInt(_enrolmentscourseid) + "&enrolments[0][timestart]=" + FString::FromInt(_enrolmentstimestart) + "&enrolments[0][timeend]=" + FString::FromInt(_enrolmentstimeend) + "&enrolments[0][suspend]=" + FString::FromInt(_enrolmentssuspend);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Uenrol_manual_enrol_users::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Uenrol_manual_enrol_users::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Uenrol_manual_enrol_users::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Uenrol_manual_unenrol_users* Uenrol_manual_unenrol_users::enrol_manual_unenrol_users(
			const FString ServerURL,
			const FString Token,
			const int32 _enrolmentsuserid,
			const int32 _enrolmentscourseid,
			const int32 _enrolmentsroleid)
{
	Uenrol_manual_unenrol_users* Node = NewObject<Uenrol_manual_unenrol_users>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=enrol_manual_unenrol_users&enrolments[0][userid]=" + FString::FromInt(_enrolmentsuserid) + "&enrolments[0][courseid]=" + FString::FromInt(_enrolmentscourseid) + "&enrolments[0][roleid]=" + FString::FromInt(_enrolmentsroleid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Uenrol_manual_unenrol_users::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Uenrol_manual_unenrol_users::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Uenrol_manual_unenrol_users::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Uenrol_meta_add_instances* Uenrol_meta_add_instances::enrol_meta_add_instances(
			const FString ServerURL,
			const FString Token,
			const int32 _instancesmetacourseid,
			const FString _instancescourseid,
			const int32 _instancescreategroup)
{
	Uenrol_meta_add_instances* Node = NewObject<Uenrol_meta_add_instances>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=enrol_meta_add_instances&instances[0][metacourseid]=" + FString::FromInt(_instancesmetacourseid) + "&instances[0][courseid]=" + _instancescourseid + "&instances[0][creategroup]=" + FString::FromInt(_instancescreategroup);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Uenrol_meta_add_instances::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Uenrol_meta_add_instances::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Uenrol_meta_add_instances::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Uenrol_meta_delete_instances* Uenrol_meta_delete_instances::enrol_meta_delete_instances(
			const FString ServerURL,
			const FString Token,
			const int32 _instancesmetacourseid,
			const FString _instancescourseid)
{
	Uenrol_meta_delete_instances* Node = NewObject<Uenrol_meta_delete_instances>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=enrol_meta_delete_instances&instances[0][metacourseid]=" + FString::FromInt(_instancesmetacourseid) + "&instances[0][courseid]=" + _instancescourseid;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Uenrol_meta_delete_instances::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Uenrol_meta_delete_instances::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Uenrol_meta_delete_instances::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Uenrol_self_enrol_user* Uenrol_self_enrol_user::enrol_self_enrol_user(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const FString _password,
			const int32 _instanceid)
{
	Uenrol_self_enrol_user* Node = NewObject<Uenrol_self_enrol_user>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=enrol_self_enrol_user&courseid=" + FString::FromInt(_courseid) + "&password=" + _password + "&instanceid=" + FString::FromInt(_instanceid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Uenrol_self_enrol_user::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Uenrol_self_enrol_user::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Uenrol_self_enrol_user::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Uenrol_self_get_instance_info* Uenrol_self_get_instance_info::enrol_self_get_instance_info(
			const FString ServerURL,
			const FString Token,
			const int32 _instanceid)
{
	Uenrol_self_get_instance_info* Node = NewObject<Uenrol_self_get_instance_info>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=enrol_self_get_instance_info&instanceid=" + FString::FromInt(_instanceid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Uenrol_self_get_instance_info::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Uenrol_self_get_instance_info::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Uenrol_self_get_instance_info::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ugradereport_overview_get_course_grades* Ugradereport_overview_get_course_grades::gradereport_overview_get_course_grades(
			const FString ServerURL,
			const FString Token,
			const int32 _userid)
{
	Ugradereport_overview_get_course_grades* Node = NewObject<Ugradereport_overview_get_course_grades>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=gradereport_overview_get_course_grades&userid=" + FString::FromInt(_userid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ugradereport_overview_get_course_grades::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ugradereport_overview_get_course_grades::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ugradereport_overview_get_course_grades::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ugradereport_overview_view_grade_report* Ugradereport_overview_view_grade_report::gradereport_overview_view_grade_report(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _userid)
{
	Ugradereport_overview_view_grade_report* Node = NewObject<Ugradereport_overview_view_grade_report>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=gradereport_overview_view_grade_report&courseid=" + FString::FromInt(_courseid) + "&userid=" + FString::FromInt(_userid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ugradereport_overview_view_grade_report::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ugradereport_overview_view_grade_report::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ugradereport_overview_view_grade_report::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ugradereport_singleview_get_grade_items_for_search_widget* Ugradereport_singleview_get_grade_items_for_search_widget::gradereport_singleview_get_grade_items_for_search_widget(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid)
{
	Ugradereport_singleview_get_grade_items_for_search_widget* Node = NewObject<Ugradereport_singleview_get_grade_items_for_search_widget>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=gradereport_singleview_get_grade_items_for_search_widget&courseid=" + FString::FromInt(_courseid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ugradereport_singleview_get_grade_items_for_search_widget::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ugradereport_singleview_get_grade_items_for_search_widget::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ugradereport_singleview_get_grade_items_for_search_widget::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ugradereport_user_get_grade_items* Ugradereport_user_get_grade_items::gradereport_user_get_grade_items(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _userid,
			const int32 _groupid)
{
	Ugradereport_user_get_grade_items* Node = NewObject<Ugradereport_user_get_grade_items>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=gradereport_user_get_grade_items&courseid=" + FString::FromInt(_courseid) + "&userid=" + FString::FromInt(_userid) + "&groupid=" + FString::FromInt(_groupid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ugradereport_user_get_grade_items::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ugradereport_user_get_grade_items::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ugradereport_user_get_grade_items::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ugradereport_user_get_grades_table* Ugradereport_user_get_grades_table::gradereport_user_get_grades_table(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _userid,
			const int32 _groupid)
{
	Ugradereport_user_get_grades_table* Node = NewObject<Ugradereport_user_get_grades_table>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=gradereport_user_get_grades_table&courseid=" + FString::FromInt(_courseid) + "&userid=" + FString::FromInt(_userid) + "&groupid=" + FString::FromInt(_groupid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ugradereport_user_get_grades_table::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ugradereport_user_get_grades_table::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ugradereport_user_get_grades_table::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ugradereport_user_view_grade_report* Ugradereport_user_view_grade_report::gradereport_user_view_grade_report(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _userid)
{
	Ugradereport_user_view_grade_report* Node = NewObject<Ugradereport_user_view_grade_report>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=gradereport_user_view_grade_report&courseid=" + FString::FromInt(_courseid) + "&userid=" + FString::FromInt(_userid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ugradereport_user_view_grade_report::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ugradereport_user_view_grade_report::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ugradereport_user_view_grade_report::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ugradingform_guide_grader_gradingpanel_fetch* Ugradingform_guide_grader_gradingpanel_fetch::gradingform_guide_grader_gradingpanel_fetch(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const int32 _contextid,
			const FString _itemname,
			const int32 _gradeduserid)
{
	Ugradingform_guide_grader_gradingpanel_fetch* Node = NewObject<Ugradingform_guide_grader_gradingpanel_fetch>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=gradingform_guide_grader_gradingpanel_fetch&component=" + _component + "&contextid=" + FString::FromInt(_contextid) + "&itemname=" + _itemname + "&gradeduserid=" + FString::FromInt(_gradeduserid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ugradingform_guide_grader_gradingpanel_fetch::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ugradingform_guide_grader_gradingpanel_fetch::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ugradingform_guide_grader_gradingpanel_fetch::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ugradingform_guide_grader_gradingpanel_store* Ugradingform_guide_grader_gradingpanel_store::gradingform_guide_grader_gradingpanel_store(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const int32 _contextid,
			const FString _itemname,
			const int32 _gradeduserid,
			const FString _formdata,
			const int32 _notifyuser)
{
	Ugradingform_guide_grader_gradingpanel_store* Node = NewObject<Ugradingform_guide_grader_gradingpanel_store>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=gradingform_guide_grader_gradingpanel_store&component=" + _component + "&contextid=" + FString::FromInt(_contextid) + "&itemname=" + _itemname + "&gradeduserid=" + FString::FromInt(_gradeduserid) + "&notifyuser=" + FString::FromInt(_notifyuser) + "&formdata=" + _formdata;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ugradingform_guide_grader_gradingpanel_store::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ugradingform_guide_grader_gradingpanel_store::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ugradingform_guide_grader_gradingpanel_store::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ugradingform_rubric_grader_gradingpanel_fetch* Ugradingform_rubric_grader_gradingpanel_fetch::gradingform_rubric_grader_gradingpanel_fetch(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const int32 _contextid,
			const FString _itemname,
			const int32 _gradeduserid)
{
	Ugradingform_rubric_grader_gradingpanel_fetch* Node = NewObject<Ugradingform_rubric_grader_gradingpanel_fetch>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=gradingform_rubric_grader_gradingpanel_fetch&component=" + _component + "&contextid=" + FString::FromInt(_contextid) + "&itemname=" + _itemname + "&gradeduserid=" + FString::FromInt(_gradeduserid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ugradingform_rubric_grader_gradingpanel_fetch::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ugradingform_rubric_grader_gradingpanel_fetch::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ugradingform_rubric_grader_gradingpanel_fetch::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ugradingform_rubric_grader_gradingpanel_store* Ugradingform_rubric_grader_gradingpanel_store::gradingform_rubric_grader_gradingpanel_store(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const int32 _contextid,
			const FString _itemname,
			const int32 _gradeduserid,
			const FString _formdata,
			const int32 _notifyuser)
{
	Ugradingform_rubric_grader_gradingpanel_store* Node = NewObject<Ugradingform_rubric_grader_gradingpanel_store>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=gradingform_rubric_grader_gradingpanel_store&component=" + _component + "&contextid=" + FString::FromInt(_contextid) + "&itemname=" + _itemname + "&gradeduserid=" + FString::FromInt(_gradeduserid) + "&notifyuser=" + FString::FromInt(_notifyuser) + "&formdata=" + _formdata;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ugradingform_rubric_grader_gradingpanel_store::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ugradingform_rubric_grader_gradingpanel_store::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ugradingform_rubric_grader_gradingpanel_store::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umedia_videojs_get_language* Umedia_videojs_get_language::media_videojs_get_language(
			const FString ServerURL,
			const FString Token,
			const FString _lang)
{
	Umedia_videojs_get_language* Node = NewObject<Umedia_videojs_get_language>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=media_videojs_get_language&lang=" + _lang;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umedia_videojs_get_language::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umedia_videojs_get_language::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umedia_videojs_get_language::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umessage_airnotifier_are_notification_preferences_configured* Umessage_airnotifier_are_notification_preferences_configured::message_airnotifier_are_notification_preferences_configured(
			const FString ServerURL,
			const FString Token,
			const int32 _userids)
{
	Umessage_airnotifier_are_notification_preferences_configured* Node = NewObject<Umessage_airnotifier_are_notification_preferences_configured>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=message_airnotifier_are_notification_preferences_configured&userids[0]=" + FString::FromInt(_userids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umessage_airnotifier_are_notification_preferences_configured::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umessage_airnotifier_are_notification_preferences_configured::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umessage_airnotifier_are_notification_preferences_configured::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umessage_airnotifier_enable_device* Umessage_airnotifier_enable_device::message_airnotifier_enable_device(
			const FString ServerURL,
			const FString Token,
			const int32 _deviceid,
			const int32 _enable)
{
	Umessage_airnotifier_enable_device* Node = NewObject<Umessage_airnotifier_enable_device>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=message_airnotifier_enable_device&deviceid=" + FString::FromInt(_deviceid) + "&enable=" + FString::FromInt(_enable);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umessage_airnotifier_enable_device::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umessage_airnotifier_enable_device::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umessage_airnotifier_enable_device::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umessage_airnotifier_get_user_devices* Umessage_airnotifier_get_user_devices::message_airnotifier_get_user_devices(
			const FString ServerURL,
			const FString Token,
			const FString _appid,
			const int32 _userid)
{
	Umessage_airnotifier_get_user_devices* Node = NewObject<Umessage_airnotifier_get_user_devices>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=message_airnotifier_get_user_devices&appid=" + _appid + "&userid=" + FString::FromInt(_userid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umessage_airnotifier_get_user_devices::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umessage_airnotifier_get_user_devices::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umessage_airnotifier_get_user_devices::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umessage_airnotifier_is_system_configured* Umessage_airnotifier_is_system_configured::message_airnotifier_is_system_configured(
			const FString ServerURL,
			const FString Token)
{
	Umessage_airnotifier_is_system_configured* Node = NewObject<Umessage_airnotifier_is_system_configured>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=message_airnotifier_is_system_configured";

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umessage_airnotifier_is_system_configured::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umessage_airnotifier_is_system_configured::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umessage_airnotifier_is_system_configured::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umessage_popup_get_popup_notifications* Umessage_popup_get_popup_notifications::message_popup_get_popup_notifications(
			const FString ServerURL,
			const FString Token,
			const int32 _useridto,
			const int32 _newestfirst,
			const int32 _limit,
			const int32 _offset)
{
	Umessage_popup_get_popup_notifications* Node = NewObject<Umessage_popup_get_popup_notifications>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=message_popup_get_popup_notifications&useridto=" + FString::FromInt(_useridto) + "&newestfirst=" + FString::FromInt(_newestfirst) + "&limit=" + FString::FromInt(_limit) + "&offset=" + FString::FromInt(_offset);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umessage_popup_get_popup_notifications::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umessage_popup_get_popup_notifications::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umessage_popup_get_popup_notifications::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umessage_popup_get_unread_popup_notification_count* Umessage_popup_get_unread_popup_notification_count::message_popup_get_unread_popup_notification_count(
			const FString ServerURL,
			const FString Token,
			const int32 _useridto)
{
	Umessage_popup_get_unread_popup_notification_count* Node = NewObject<Umessage_popup_get_unread_popup_notification_count>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=message_popup_get_unread_popup_notification_count&useridto=" + FString::FromInt(_useridto);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umessage_popup_get_unread_popup_notification_count::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umessage_popup_get_unread_popup_notification_count::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umessage_popup_get_unread_popup_notification_count::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_assign_copy_previous_attempt* Umod_assign_copy_previous_attempt::mod_assign_copy_previous_attempt(
			const FString ServerURL,
			const FString Token,
			const int32 _assignmentid)
{
	Umod_assign_copy_previous_attempt* Node = NewObject<Umod_assign_copy_previous_attempt>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_assign_copy_previous_attempt&assignmentid=" + FString::FromInt(_assignmentid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_assign_copy_previous_attempt::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_assign_copy_previous_attempt::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_assign_copy_previous_attempt::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_assign_get_assignments* Umod_assign_get_assignments::mod_assign_get_assignments(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids,
			const FString _capabilities,
			const int32 _includenotenrolledcourses)
{
	Umod_assign_get_assignments* Node = NewObject<Umod_assign_get_assignments>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_assign_get_assignments&courseids[0]=" + FString::FromInt(_courseids) + "&capabilities[0]=" + _capabilities + "&includenotenrolledcourses=" + FString::FromInt(_includenotenrolledcourses);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_assign_get_assignments::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_assign_get_assignments::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_assign_get_assignments::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_assign_get_grades* Umod_assign_get_grades::mod_assign_get_grades(
			const FString ServerURL,
			const FString Token,
			const int32 _assignmentids,
			const int32 _since)
{
	Umod_assign_get_grades* Node = NewObject<Umod_assign_get_grades>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_assign_get_grades&assignmentids[0]=" + FString::FromInt(_assignmentids) + "&since=" + FString::FromInt(_since);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_assign_get_grades::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_assign_get_grades::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_assign_get_grades::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_assign_get_participant* Umod_assign_get_participant::mod_assign_get_participant(
			const FString ServerURL,
			const FString Token,
			const int32 _assignid,
			const int32 _userid,
			const int32 _embeduser)
{
	Umod_assign_get_participant* Node = NewObject<Umod_assign_get_participant>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_assign_get_participant&assignid=" + FString::FromInt(_assignid) + "&userid=" + FString::FromInt(_userid) + "&embeduser=" + FString::FromInt(_embeduser);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_assign_get_participant::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_assign_get_participant::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_assign_get_participant::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_assign_get_submission_status* Umod_assign_get_submission_status::mod_assign_get_submission_status(
			const FString ServerURL,
			const FString Token,
			const int32 _assignid,
			const int32 _userid,
			const int32 _groupid)
{
	Umod_assign_get_submission_status* Node = NewObject<Umod_assign_get_submission_status>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_assign_get_submission_status&assignid=" + FString::FromInt(_assignid) + "&userid=" + FString::FromInt(_userid) + "&groupid=" + FString::FromInt(_groupid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_assign_get_submission_status::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_assign_get_submission_status::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_assign_get_submission_status::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_assign_get_submissions* Umod_assign_get_submissions::mod_assign_get_submissions(
			const FString ServerURL,
			const FString Token,
			const int32 _assignmentids,
			const FString _status,
			const int32 _since,
			const int32 _before)
{
	Umod_assign_get_submissions* Node = NewObject<Umod_assign_get_submissions>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_assign_get_submissions&assignmentids[0]=" + FString::FromInt(_assignmentids) + "&status=" + _status + "&since=" + FString::FromInt(_since) + "&before=" + FString::FromInt(_before);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_assign_get_submissions::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_assign_get_submissions::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_assign_get_submissions::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_assign_get_user_flags* Umod_assign_get_user_flags::mod_assign_get_user_flags(
			const FString ServerURL,
			const FString Token,
			const int32 _assignmentids)
{
	Umod_assign_get_user_flags* Node = NewObject<Umod_assign_get_user_flags>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_assign_get_user_flags&assignmentids[0]=" + FString::FromInt(_assignmentids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_assign_get_user_flags::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_assign_get_user_flags::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_assign_get_user_flags::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_assign_get_user_mappings* Umod_assign_get_user_mappings::mod_assign_get_user_mappings(
			const FString ServerURL,
			const FString Token,
			const int32 _assignmentids)
{
	Umod_assign_get_user_mappings* Node = NewObject<Umod_assign_get_user_mappings>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_assign_get_user_mappings&assignmentids[0]=" + FString::FromInt(_assignmentids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_assign_get_user_mappings::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_assign_get_user_mappings::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_assign_get_user_mappings::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_assign_list_participants* Umod_assign_list_participants::mod_assign_list_participants(
			const FString ServerURL,
			const FString Token,
			const int32 _assignid,
			const int32 _groupid,
			const FString _filter,
			const int32 _skip,
			const int32 _limit,
			const int32 _onlyids,
			const int32 _includeenrolments,
			const int32 _tablesort)
{
	Umod_assign_list_participants* Node = NewObject<Umod_assign_list_participants>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_assign_list_participants&assignid=" + FString::FromInt(_assignid) + "&groupid=" + FString::FromInt(_groupid) + "&filter=" + _filter + "&skip=" + FString::FromInt(_skip) + "&limit=" + FString::FromInt(_limit) + "&onlyids=" + FString::FromInt(_onlyids) + "&includeenrolments=" + FString::FromInt(_includeenrolments) + "&tablesort=" + FString::FromInt(_tablesort);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_assign_list_participants::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_assign_list_participants::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_assign_list_participants::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_assign_lock_submissions* Umod_assign_lock_submissions::mod_assign_lock_submissions(
			const FString ServerURL,
			const FString Token,
			const int32 _assignmentid,
			const int32 _userids)
{
	Umod_assign_lock_submissions* Node = NewObject<Umod_assign_lock_submissions>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_assign_lock_submissions&assignmentid=" + FString::FromInt(_assignmentid) + "&userids[0]=" + FString::FromInt(_userids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_assign_lock_submissions::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_assign_lock_submissions::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_assign_lock_submissions::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_assign_reveal_identities* Umod_assign_reveal_identities::mod_assign_reveal_identities(
			const FString ServerURL,
			const FString Token,
			const int32 _assignmentid)
{
	Umod_assign_reveal_identities* Node = NewObject<Umod_assign_reveal_identities>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_assign_reveal_identities&assignmentid=" + FString::FromInt(_assignmentid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_assign_reveal_identities::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_assign_reveal_identities::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_assign_reveal_identities::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_assign_revert_submissions_to_draft* Umod_assign_revert_submissions_to_draft::mod_assign_revert_submissions_to_draft(
			const FString ServerURL,
			const FString Token,
			const int32 _assignmentid,
			const int32 _userids)
{
	Umod_assign_revert_submissions_to_draft* Node = NewObject<Umod_assign_revert_submissions_to_draft>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_assign_revert_submissions_to_draft&assignmentid=" + FString::FromInt(_assignmentid) + "&userids[0]=" + FString::FromInt(_userids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_assign_revert_submissions_to_draft::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_assign_revert_submissions_to_draft::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_assign_revert_submissions_to_draft::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_assign_save_grade* Umod_assign_save_grade::mod_assign_save_grade(
			const FString ServerURL,
			const FString Token,
			const int32 _assignmentid,
			const int32 _userid,
			const float _grade,
			const int32 _attemptnumber,
			const int32 _addattempt,
			const FString _workflowstate,
			const int32 _applytoall,
			const FString _plugindataassignfeedbackcomments_editortext,
			const int32 _plugindataassignfeedbackcomments_editorformat,
			const int32 _plugindatafiles_filemanager,
			const int32 _advancedgradingdataguidecriteriacriterionid,
			const int32 _advancedgradingdataguidecriteriafillingscriterionid,
			const int32 _advancedgradingdataguidecriteriafillingslevelid,
			const FString _advancedgradingdataguidecriteriafillingsremark,
			const int32 _advancedgradingdataguidecriteriafillingsremarkformat,
			const float _advancedgradingdataguidecriteriafillingsscore,
			const int32 _advancedgradingdatarubriccriteriacriterionid,
			const int32 _advancedgradingdatarubriccriteriafillingscriterionid,
			const int32 _advancedgradingdatarubriccriteriafillingslevelid,
			const FString _advancedgradingdatarubriccriteriafillingsremark,
			const int32 _advancedgradingdatarubriccriteriafillingsremarkformat)
{
	Umod_assign_save_grade* Node = NewObject<Umod_assign_save_grade>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_assign_save_grade&assignmentid=" + FString::FromInt(_assignmentid) + "&userid=" + FString::FromInt(_userid) + "&grade=" + FString::SanitizeFloat(_grade) + "&attemptnumber=" + FString::FromInt(_attemptnumber) + "&addattempt=" + FString::FromInt(_addattempt) + "&workflowstate=" + _workflowstate + "&applytoall=" + FString::FromInt(_applytoall) + "&plugindata[assignfeedbackcomments_editor][text]=" + _plugindataassignfeedbackcomments_editortext + "&plugindata[assignfeedbackcomments_editor][format]=" + FString::FromInt(_plugindataassignfeedbackcomments_editorformat) + "&plugindata[files_filemanager]=" + FString::FromInt(_plugindatafiles_filemanager) + "&advancedgradingdata[guide][criteria][0][criterionid]=" + FString::FromInt(_advancedgradingdataguidecriteriacriterionid) + "&advancedgradingdata[guide][criteria][0][fillings][0][criterionid]=" + FString::FromInt(_advancedgradingdataguidecriteriafillingscriterionid) + "&advancedgradingdata[guide][criteria][0][fillings][0][levelid]=" + FString::FromInt(_advancedgradingdataguidecriteriafillingslevelid) + "&advancedgradingdata[guide][criteria][0][fillings][0][remark]=" + _advancedgradingdataguidecriteriafillingsremark + "&advancedgradingdata[guide][criteria][0][fillings][0][remarkformat]=" + FString::FromInt(_advancedgradingdataguidecriteriafillingsremarkformat) + "&advancedgradingdata[guide][criteria][0][fillings][0][score]=" + FString::SanitizeFloat(_advancedgradingdataguidecriteriafillingsscore) + "&advancedgradingdata[rubric][criteria][0][criterionid]=" + FString::FromInt(_advancedgradingdatarubriccriteriacriterionid) + "&advancedgradingdata[rubric][criteria][0][fillings][0][criterionid]=" + FString::FromInt(_advancedgradingdatarubriccriteriafillingscriterionid) + "&advancedgradingdata[rubric][criteria][0][fillings][0][levelid]=" + FString::FromInt(_advancedgradingdatarubriccriteriafillingslevelid) + "&advancedgradingdata[rubric][criteria][0][fillings][0][remark]=" + _advancedgradingdatarubriccriteriafillingsremark + "&advancedgradingdata[rubric][criteria][0][fillings][0][remarkformat]=" + FString::FromInt(_advancedgradingdatarubriccriteriafillingsremarkformat);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_assign_save_grade::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_assign_save_grade::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_assign_save_grade::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_assign_save_grades* Umod_assign_save_grades::mod_assign_save_grades(
			const FString ServerURL,
			const FString Token,
			const int32 _assignmentid,
			const int32 _applytoall,
			const int32 _gradesuserid,
			const float _gradesgrade,
			const int32 _gradesattemptnumber,
			const int32 _gradesaddattempt,
			const FString _gradesworkflowstate,
			const FString _gradesplugindataassignfeedbackcomments_editortext,
			const int32 _gradesplugindataassignfeedbackcomments_editorformat,
			const int32 _gradesplugindatafiles_filemanager,
			const int32 _gradesadvancedgradingdataguidecriteriacriterionid,
			const int32 _gradesadvancedgradingdataguidecriteriafillingscriterionid,
			const int32 _gradesadvancedgradingdataguidecriteriafillingslevelid,
			const FString _gradesadvancedgradingdataguidecriteriafillingsremark,
			const int32 _gradesadvancedgradingdataguidecriteriafillingsremarkformat,
			const float _gradesadvancedgradingdataguidecriteriafillingsscore,
			const int32 _gradesadvancedgradingdatarubriccriteriacriterionid,
			const int32 _gradesadvancedgradingdatarubriccriteriafillingscriterionid,
			const int32 _gradesadvancedgradingdatarubriccriteriafillingslevelid,
			const FString _gradesadvancedgradingdatarubriccriteriafillingsremark,
			const int32 _gradesadvancedgradingdatarubriccriteriafillingsremarkformat)
{
	Umod_assign_save_grades* Node = NewObject<Umod_assign_save_grades>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_assign_save_grades&assignmentid=" + FString::FromInt(_assignmentid) + "&applytoall=" + FString::FromInt(_applytoall) + "&grades[0][userid]=" + FString::FromInt(_gradesuserid) + "&grades[0][grade]=" + FString::SanitizeFloat(_gradesgrade) + "&grades[0][attemptnumber]=" + FString::FromInt(_gradesattemptnumber) + "&grades[0][addattempt]=" + FString::FromInt(_gradesaddattempt) + "&grades[0][workflowstate]=" + _gradesworkflowstate + "&grades[0][plugindata][assignfeedbackcomments_editor][text]=" + _gradesplugindataassignfeedbackcomments_editortext + "&grades[0][plugindata][assignfeedbackcomments_editor][format]=" + FString::FromInt(_gradesplugindataassignfeedbackcomments_editorformat) + "&grades[0][plugindata][files_filemanager]=" + FString::FromInt(_gradesplugindatafiles_filemanager) + "&grades[0][advancedgradingdata][guide][criteria][0][criterionid]=" + FString::FromInt(_gradesadvancedgradingdataguidecriteriacriterionid) + "&grades[0][advancedgradingdata][guide][criteria][0][fillings][0][criterionid]=" + FString::FromInt(_gradesadvancedgradingdataguidecriteriafillingscriterionid) + "&grades[0][advancedgradingdata][guide][criteria][0][fillings][0][levelid]=" + FString::FromInt(_gradesadvancedgradingdataguidecriteriafillingslevelid) + "&grades[0][advancedgradingdata][guide][criteria][0][fillings][0][remark]=" + _gradesadvancedgradingdataguidecriteriafillingsremark + "&grades[0][advancedgradingdata][guide][criteria][0][fillings][0][remarkformat]=" + FString::FromInt(_gradesadvancedgradingdataguidecriteriafillingsremarkformat) + "&grades[0][advancedgradingdata][guide][criteria][0][fillings][0][score]=" + FString::SanitizeFloat(_gradesadvancedgradingdataguidecriteriafillingsscore) + "&grades[0][advancedgradingdata][rubric][criteria][0][criterionid]=" + FString::FromInt(_gradesadvancedgradingdatarubriccriteriacriterionid) + "&grades[0][advancedgradingdata][rubric][criteria][0][fillings][0][criterionid]=" + FString::FromInt(_gradesadvancedgradingdatarubriccriteriafillingscriterionid) + "&grades[0][advancedgradingdata][rubric][criteria][0][fillings][0][levelid]=" + FString::FromInt(_gradesadvancedgradingdatarubriccriteriafillingslevelid) + "&grades[0][advancedgradingdata][rubric][criteria][0][fillings][0][remark]=" + _gradesadvancedgradingdatarubriccriteriafillingsremark + "&grades[0][advancedgradingdata][rubric][criteria][0][fillings][0][remarkformat]=" + FString::FromInt(_gradesadvancedgradingdatarubriccriteriafillingsremarkformat);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_assign_save_grades::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_assign_save_grades::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_assign_save_grades::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_assign_save_submission* Umod_assign_save_submission::mod_assign_save_submission(
			const FString ServerURL,
			const FString Token,
			const int32 _assignmentid,
			const FString _plugindataonlinetext_editortext,
			const int32 _plugindataonlinetext_editorformat,
			const int32 _plugindataonlinetext_editoritemid,
			const int32 _plugindatafiles_filemanager)
{
	Umod_assign_save_submission* Node = NewObject<Umod_assign_save_submission>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_assign_save_submission&assignmentid=" + FString::FromInt(_assignmentid) + "&plugindata[onlinetext_editor][text]=" + _plugindataonlinetext_editortext + "&plugindata[onlinetext_editor][format]=" + FString::FromInt(_plugindataonlinetext_editorformat) + "&plugindata[onlinetext_editor][itemid]=" + FString::FromInt(_plugindataonlinetext_editoritemid) + "&plugindata[files_filemanager]=" + FString::FromInt(_plugindatafiles_filemanager);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_assign_save_submission::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_assign_save_submission::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_assign_save_submission::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_assign_save_user_extensions* Umod_assign_save_user_extensions::mod_assign_save_user_extensions(
			const FString ServerURL,
			const FString Token,
			const int32 _assignmentid,
			const int32 _userids,
			const int32 _dates)
{
	Umod_assign_save_user_extensions* Node = NewObject<Umod_assign_save_user_extensions>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_assign_save_user_extensions&assignmentid=" + FString::FromInt(_assignmentid) + "&userids[0]=" + FString::FromInt(_userids) + "&dates[0]=" + FString::FromInt(_dates);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_assign_save_user_extensions::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_assign_save_user_extensions::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_assign_save_user_extensions::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_assign_set_user_flags* Umod_assign_set_user_flags::mod_assign_set_user_flags(
			const FString ServerURL,
			const FString Token,
			const int32 _assignmentid,
			const int32 _userflagsuserid,
			const int32 _userflagslocked,
			const int32 _userflagsmailed,
			const int32 _userflagsextensionduedate,
			const FString _userflagsworkflowstate,
			const int32 _userflagsallocatedmarker)
{
	Umod_assign_set_user_flags* Node = NewObject<Umod_assign_set_user_flags>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_assign_set_user_flags&assignmentid=" + FString::FromInt(_assignmentid) + "&userflags[0][userid]=" + FString::FromInt(_userflagsuserid) + "&userflags[0][locked]=" + FString::FromInt(_userflagslocked) + "&userflags[0][mailed]=" + FString::FromInt(_userflagsmailed) + "&userflags[0][extensionduedate]=" + FString::FromInt(_userflagsextensionduedate) + "&userflags[0][workflowstate]=" + _userflagsworkflowstate + "&userflags[0][allocatedmarker]=" + FString::FromInt(_userflagsallocatedmarker);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_assign_set_user_flags::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_assign_set_user_flags::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_assign_set_user_flags::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_assign_start_submission* Umod_assign_start_submission::mod_assign_start_submission(
			const FString ServerURL,
			const FString Token,
			const int32 _assignid)
{
	Umod_assign_start_submission* Node = NewObject<Umod_assign_start_submission>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_assign_start_submission&assignid=" + FString::FromInt(_assignid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_assign_start_submission::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_assign_start_submission::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_assign_start_submission::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_assign_submit_for_grading* Umod_assign_submit_for_grading::mod_assign_submit_for_grading(
			const FString ServerURL,
			const FString Token,
			const int32 _assignmentid,
			const int32 _acceptsubmissionstatement)
{
	Umod_assign_submit_for_grading* Node = NewObject<Umod_assign_submit_for_grading>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_assign_submit_for_grading&assignmentid=" + FString::FromInt(_assignmentid) + "&acceptsubmissionstatement=" + FString::FromInt(_acceptsubmissionstatement);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_assign_submit_for_grading::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_assign_submit_for_grading::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_assign_submit_for_grading::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_assign_submit_grading_form* Umod_assign_submit_grading_form::mod_assign_submit_grading_form(
			const FString ServerURL,
			const FString Token,
			const int32 _assignmentid,
			const int32 _userid,
			const FString _jsonformdata)
{
	Umod_assign_submit_grading_form* Node = NewObject<Umod_assign_submit_grading_form>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_assign_submit_grading_form&assignmentid=" + FString::FromInt(_assignmentid) + "&userid=" + FString::FromInt(_userid) + "&jsonformdata=" + _jsonformdata;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_assign_submit_grading_form::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_assign_submit_grading_form::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_assign_submit_grading_form::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_assign_unlock_submissions* Umod_assign_unlock_submissions::mod_assign_unlock_submissions(
			const FString ServerURL,
			const FString Token,
			const int32 _assignmentid,
			const int32 _userids)
{
	Umod_assign_unlock_submissions* Node = NewObject<Umod_assign_unlock_submissions>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_assign_unlock_submissions&assignmentid=" + FString::FromInt(_assignmentid) + "&userids[0]=" + FString::FromInt(_userids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_assign_unlock_submissions::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_assign_unlock_submissions::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_assign_unlock_submissions::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_assign_view_assign* Umod_assign_view_assign::mod_assign_view_assign(
			const FString ServerURL,
			const FString Token,
			const int32 _assignid)
{
	Umod_assign_view_assign* Node = NewObject<Umod_assign_view_assign>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_assign_view_assign&assignid=" + FString::FromInt(_assignid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_assign_view_assign::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_assign_view_assign::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_assign_view_assign::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_assign_view_grading_table* Umod_assign_view_grading_table::mod_assign_view_grading_table(
			const FString ServerURL,
			const FString Token,
			const int32 _assignid)
{
	Umod_assign_view_grading_table* Node = NewObject<Umod_assign_view_grading_table>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_assign_view_grading_table&assignid=" + FString::FromInt(_assignid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_assign_view_grading_table::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_assign_view_grading_table::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_assign_view_grading_table::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_assign_view_submission_status* Umod_assign_view_submission_status::mod_assign_view_submission_status(
			const FString ServerURL,
			const FString Token,
			const int32 _assignid)
{
	Umod_assign_view_submission_status* Node = NewObject<Umod_assign_view_submission_status>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_assign_view_submission_status&assignid=" + FString::FromInt(_assignid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_assign_view_submission_status::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_assign_view_submission_status::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_assign_view_submission_status::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_bigbluebuttonbn_can_join* Umod_bigbluebuttonbn_can_join::mod_bigbluebuttonbn_can_join(
			const FString ServerURL,
			const FString Token,
			const int32 _cmid,
			const int32 _groupid)
{
	Umod_bigbluebuttonbn_can_join* Node = NewObject<Umod_bigbluebuttonbn_can_join>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_bigbluebuttonbn_can_join&cmid=" + FString::FromInt(_cmid) + "&groupid=" + FString::FromInt(_groupid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_bigbluebuttonbn_can_join::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_bigbluebuttonbn_can_join::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_bigbluebuttonbn_can_join::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_bigbluebuttonbn_completion_validate* Umod_bigbluebuttonbn_completion_validate::mod_bigbluebuttonbn_completion_validate(
			const FString ServerURL,
			const FString Token,
			const int32 _bigbluebuttonbnid)
{
	Umod_bigbluebuttonbn_completion_validate* Node = NewObject<Umod_bigbluebuttonbn_completion_validate>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_bigbluebuttonbn_completion_validate&bigbluebuttonbnid=" + FString::FromInt(_bigbluebuttonbnid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_bigbluebuttonbn_completion_validate::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_bigbluebuttonbn_completion_validate::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_bigbluebuttonbn_completion_validate::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_bigbluebuttonbn_end_meeting* Umod_bigbluebuttonbn_end_meeting::mod_bigbluebuttonbn_end_meeting(
			const FString ServerURL,
			const FString Token,
			const int32 _bigbluebuttonbnid,
			const int32 _groupid)
{
	Umod_bigbluebuttonbn_end_meeting* Node = NewObject<Umod_bigbluebuttonbn_end_meeting>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_bigbluebuttonbn_end_meeting&bigbluebuttonbnid=" + FString::FromInt(_bigbluebuttonbnid) + "&groupid=" + FString::FromInt(_groupid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_bigbluebuttonbn_end_meeting::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_bigbluebuttonbn_end_meeting::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_bigbluebuttonbn_end_meeting::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_bigbluebuttonbn_get_bigbluebuttonbns_by_courses* Umod_bigbluebuttonbn_get_bigbluebuttonbns_by_courses::mod_bigbluebuttonbn_get_bigbluebuttonbns_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids)
{
	Umod_bigbluebuttonbn_get_bigbluebuttonbns_by_courses* Node = NewObject<Umod_bigbluebuttonbn_get_bigbluebuttonbns_by_courses>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_bigbluebuttonbn_get_bigbluebuttonbns_by_courses&courseids[0]=" + FString::FromInt(_courseids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_bigbluebuttonbn_get_bigbluebuttonbns_by_courses::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_bigbluebuttonbn_get_bigbluebuttonbns_by_courses::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_bigbluebuttonbn_get_bigbluebuttonbns_by_courses::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_bigbluebuttonbn_get_join_url* Umod_bigbluebuttonbn_get_join_url::mod_bigbluebuttonbn_get_join_url(
			const FString ServerURL,
			const FString Token,
			const int32 _cmid,
			const int32 _groupid)
{
	Umod_bigbluebuttonbn_get_join_url* Node = NewObject<Umod_bigbluebuttonbn_get_join_url>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_bigbluebuttonbn_get_join_url&cmid=" + FString::FromInt(_cmid) + "&groupid=" + FString::FromInt(_groupid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_bigbluebuttonbn_get_join_url::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_bigbluebuttonbn_get_join_url::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_bigbluebuttonbn_get_join_url::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_bigbluebuttonbn_get_recordings* Umod_bigbluebuttonbn_get_recordings::mod_bigbluebuttonbn_get_recordings(
			const FString ServerURL,
			const FString Token,
			const int32 _bigbluebuttonbnid,
			const FString _tools,
			const int32 _groupid)
{
	Umod_bigbluebuttonbn_get_recordings* Node = NewObject<Umod_bigbluebuttonbn_get_recordings>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_bigbluebuttonbn_get_recordings&bigbluebuttonbnid=" + FString::FromInt(_bigbluebuttonbnid) + "&tools=" + _tools + "&groupid=" + FString::FromInt(_groupid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_bigbluebuttonbn_get_recordings::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_bigbluebuttonbn_get_recordings::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_bigbluebuttonbn_get_recordings::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_bigbluebuttonbn_get_recordings_to_import* Umod_bigbluebuttonbn_get_recordings_to_import::mod_bigbluebuttonbn_get_recordings_to_import(
			const FString ServerURL,
			const FString Token,
			const int32 _destinationinstanceid,
			const int32 _sourcebigbluebuttonbnid,
			const int32 _sourcecourseid,
			const FString _tools,
			const int32 _groupid)
{
	Umod_bigbluebuttonbn_get_recordings_to_import* Node = NewObject<Umod_bigbluebuttonbn_get_recordings_to_import>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_bigbluebuttonbn_get_recordings_to_import&destinationinstanceid=" + FString::FromInt(_destinationinstanceid) + "&sourcebigbluebuttonbnid=" + FString::FromInt(_sourcebigbluebuttonbnid) + "&sourcecourseid=" + FString::FromInt(_sourcecourseid) + "&tools=" + _tools + "&groupid=" + FString::FromInt(_groupid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_bigbluebuttonbn_get_recordings_to_import::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_bigbluebuttonbn_get_recordings_to_import::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_bigbluebuttonbn_get_recordings_to_import::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_bigbluebuttonbn_meeting_info* Umod_bigbluebuttonbn_meeting_info::mod_bigbluebuttonbn_meeting_info(
			const FString ServerURL,
			const FString Token,
			const int32 _bigbluebuttonbnid,
			const int32 _groupid,
			const int32 _updatecache)
{
	Umod_bigbluebuttonbn_meeting_info* Node = NewObject<Umod_bigbluebuttonbn_meeting_info>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_bigbluebuttonbn_meeting_info&bigbluebuttonbnid=" + FString::FromInt(_bigbluebuttonbnid) + "&groupid=" + FString::FromInt(_groupid) + "&updatecache=" + FString::FromInt(_updatecache);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_bigbluebuttonbn_meeting_info::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_bigbluebuttonbn_meeting_info::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_bigbluebuttonbn_meeting_info::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_bigbluebuttonbn_update_recording* Umod_bigbluebuttonbn_update_recording::mod_bigbluebuttonbn_update_recording(
			const FString ServerURL,
			const FString Token,
			const int32 _bigbluebuttonbnid,
			const int32 _recordingid,
			const FString _action,
			const FString _additionaloptions)
{
	Umod_bigbluebuttonbn_update_recording* Node = NewObject<Umod_bigbluebuttonbn_update_recording>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_bigbluebuttonbn_update_recording&bigbluebuttonbnid=" + FString::FromInt(_bigbluebuttonbnid) + "&recordingid=" + FString::FromInt(_recordingid) + "&action=" + _action + "&additionaloptions=" + _additionaloptions;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_bigbluebuttonbn_update_recording::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_bigbluebuttonbn_update_recording::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_bigbluebuttonbn_update_recording::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_bigbluebuttonbn_view_bigbluebuttonbn* Umod_bigbluebuttonbn_view_bigbluebuttonbn::mod_bigbluebuttonbn_view_bigbluebuttonbn(
			const FString ServerURL,
			const FString Token,
			const int32 _bigbluebuttonbnid)
{
	Umod_bigbluebuttonbn_view_bigbluebuttonbn* Node = NewObject<Umod_bigbluebuttonbn_view_bigbluebuttonbn>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_bigbluebuttonbn_view_bigbluebuttonbn&bigbluebuttonbnid=" + FString::FromInt(_bigbluebuttonbnid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_bigbluebuttonbn_view_bigbluebuttonbn::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_bigbluebuttonbn_view_bigbluebuttonbn::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_bigbluebuttonbn_view_bigbluebuttonbn::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_book_get_books_by_courses* Umod_book_get_books_by_courses::mod_book_get_books_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids)
{
	Umod_book_get_books_by_courses* Node = NewObject<Umod_book_get_books_by_courses>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_book_get_books_by_courses&courseids[0]=" + FString::FromInt(_courseids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_book_get_books_by_courses::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_book_get_books_by_courses::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_book_get_books_by_courses::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_book_view_book* Umod_book_view_book::mod_book_view_book(
			const FString ServerURL,
			const FString Token,
			const int32 _bookid,
			const int32 _chapterid)
{
	Umod_book_view_book* Node = NewObject<Umod_book_view_book>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_book_view_book&bookid=" + FString::FromInt(_bookid) + "&chapterid=" + FString::FromInt(_chapterid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_book_view_book::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_book_view_book::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_book_view_book::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_chat_get_chat_latest_messages* Umod_chat_get_chat_latest_messages::mod_chat_get_chat_latest_messages(
			const FString ServerURL,
			const FString Token,
			const FString _chatsid,
			const int32 _chatlasttime)
{
	Umod_chat_get_chat_latest_messages* Node = NewObject<Umod_chat_get_chat_latest_messages>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_chat_get_chat_latest_messages&chatsid=" + _chatsid + "&chatlasttime=" + FString::FromInt(_chatlasttime);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_chat_get_chat_latest_messages::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_chat_get_chat_latest_messages::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_chat_get_chat_latest_messages::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_chat_get_chat_users* Umod_chat_get_chat_users::mod_chat_get_chat_users(
			const FString ServerURL,
			const FString Token,
			const FString _chatsid)
{
	Umod_chat_get_chat_users* Node = NewObject<Umod_chat_get_chat_users>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_chat_get_chat_users&chatsid=" + _chatsid;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_chat_get_chat_users::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_chat_get_chat_users::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_chat_get_chat_users::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_chat_get_chats_by_courses* Umod_chat_get_chats_by_courses::mod_chat_get_chats_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids)
{
	Umod_chat_get_chats_by_courses* Node = NewObject<Umod_chat_get_chats_by_courses>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_chat_get_chats_by_courses&courseids[0]=" + FString::FromInt(_courseids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_chat_get_chats_by_courses::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_chat_get_chats_by_courses::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_chat_get_chats_by_courses::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_chat_get_session_messages* Umod_chat_get_session_messages::mod_chat_get_session_messages(
			const FString ServerURL,
			const FString Token,
			const int32 _chatid,
			const int32 _sessionstart,
			const int32 _sessionend,
			const int32 _groupid)
{
	Umod_chat_get_session_messages* Node = NewObject<Umod_chat_get_session_messages>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_chat_get_session_messages&chatid=" + FString::FromInt(_chatid) + "&sessionstart=" + FString::FromInt(_sessionstart) + "&sessionend=" + FString::FromInt(_sessionend) + "&groupid=" + FString::FromInt(_groupid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_chat_get_session_messages::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_chat_get_session_messages::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_chat_get_session_messages::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_chat_get_sessions* Umod_chat_get_sessions::mod_chat_get_sessions(
			const FString ServerURL,
			const FString Token,
			const int32 _chatid,
			const int32 _groupid,
			const int32 _showall)
{
	Umod_chat_get_sessions* Node = NewObject<Umod_chat_get_sessions>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_chat_get_sessions&chatid=" + FString::FromInt(_chatid) + "&groupid=" + FString::FromInt(_groupid) + "&showall=" + FString::FromInt(_showall);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_chat_get_sessions::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_chat_get_sessions::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_chat_get_sessions::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_chat_login_user* Umod_chat_login_user::mod_chat_login_user(
			const FString ServerURL,
			const FString Token,
			const FString _chatsid,
			const int32 _chatlasttime)
{
	Umod_chat_login_user* Node = NewObject<Umod_chat_login_user>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_chat_login_user&chatsid=" + _chatsid + "&chatlasttime=" + FString::FromInt(_chatlasttime);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_chat_login_user::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_chat_login_user::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_chat_login_user::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_chat_send_chat_message* Umod_chat_send_chat_message::mod_chat_send_chat_message(
			const FString ServerURL,
			const FString Token,
			const FString _chatsid,
			const FString _messagetext,
			const FString _beepid)
{
	Umod_chat_send_chat_message* Node = NewObject<Umod_chat_send_chat_message>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_chat_send_chat_message&chatsid=" + _chatsid + "&messagetext=" + _messagetext + "&beepid=" + _beepid;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_chat_send_chat_message::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_chat_send_chat_message::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_chat_send_chat_message::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_chat_view_chat* Umod_chat_view_chat::mod_chat_view_chat(
			const FString ServerURL,
			const FString Token,
			const int32 _chatid)
{
	Umod_chat_view_chat* Node = NewObject<Umod_chat_view_chat>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_chat_view_chat&chatid=" + FString::FromInt(_chatid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_chat_view_chat::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_chat_view_chat::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_chat_view_chat::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_choice_delete_choice_responses* Umod_choice_delete_choice_responses::mod_choice_delete_choice_responses(
			const FString ServerURL,
			const FString Token,
			const int32 _choiceid,
			const int32 _responses)
{
	Umod_choice_delete_choice_responses* Node = NewObject<Umod_choice_delete_choice_responses>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_choice_delete_choice_responses&choiceid=" + FString::FromInt(_choiceid) + "&responses[0]=" + FString::FromInt(_responses);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_choice_delete_choice_responses::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_choice_delete_choice_responses::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_choice_delete_choice_responses::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_choice_get_choice_options* Umod_choice_get_choice_options::mod_choice_get_choice_options(
			const FString ServerURL,
			const FString Token,
			const int32 _choiceid)
{
	Umod_choice_get_choice_options* Node = NewObject<Umod_choice_get_choice_options>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_choice_get_choice_options&choiceid=" + FString::FromInt(_choiceid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_choice_get_choice_options::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_choice_get_choice_options::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_choice_get_choice_options::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_choice_get_choice_results* Umod_choice_get_choice_results::mod_choice_get_choice_results(
			const FString ServerURL,
			const FString Token,
			const int32 _choiceid)
{
	Umod_choice_get_choice_results* Node = NewObject<Umod_choice_get_choice_results>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_choice_get_choice_results&choiceid=" + FString::FromInt(_choiceid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_choice_get_choice_results::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_choice_get_choice_results::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_choice_get_choice_results::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_choice_get_choices_by_courses* Umod_choice_get_choices_by_courses::mod_choice_get_choices_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids)
{
	Umod_choice_get_choices_by_courses* Node = NewObject<Umod_choice_get_choices_by_courses>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_choice_get_choices_by_courses&courseids[0]=" + FString::FromInt(_courseids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_choice_get_choices_by_courses::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_choice_get_choices_by_courses::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_choice_get_choices_by_courses::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_choice_submit_choice_response* Umod_choice_submit_choice_response::mod_choice_submit_choice_response(
			const FString ServerURL,
			const FString Token,
			const int32 _choiceid,
			const int32 _responses)
{
	Umod_choice_submit_choice_response* Node = NewObject<Umod_choice_submit_choice_response>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_choice_submit_choice_response&choiceid=" + FString::FromInt(_choiceid) + "&responses[0]=" + FString::FromInt(_responses);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_choice_submit_choice_response::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_choice_submit_choice_response::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_choice_submit_choice_response::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_choice_view_choice* Umod_choice_view_choice::mod_choice_view_choice(
			const FString ServerURL,
			const FString Token,
			const int32 _choiceid)
{
	Umod_choice_view_choice* Node = NewObject<Umod_choice_view_choice>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_choice_view_choice&choiceid=" + FString::FromInt(_choiceid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_choice_view_choice::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_choice_view_choice::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_choice_view_choice::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_data_add_entry* Umod_data_add_entry::mod_data_add_entry(
			const FString ServerURL,
			const FString Token,
			const int32 _databaseid,
			const int32 _datafieldid,
			const FString _datavalue,
			const int32 _groupid,
			const FString _datasubfield)
{
	Umod_data_add_entry* Node = NewObject<Umod_data_add_entry>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_data_add_entry&databaseid=" + FString::FromInt(_databaseid) + "&groupid=" + FString::FromInt(_groupid) + "&data[0][fieldid]=" + FString::FromInt(_datafieldid) + "&data[0][subfield]=" + _datasubfield + "&data[0][value]=" + _datavalue;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_data_add_entry::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_data_add_entry::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_data_add_entry::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_data_approve_entry* Umod_data_approve_entry::mod_data_approve_entry(
			const FString ServerURL,
			const FString Token,
			const int32 _entryid,
			const int32 _approve)
{
	Umod_data_approve_entry* Node = NewObject<Umod_data_approve_entry>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_data_approve_entry&entryid=" + FString::FromInt(_entryid) + "&approve=" + FString::FromInt(_approve);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_data_approve_entry::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_data_approve_entry::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_data_approve_entry::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_data_delete_entry* Umod_data_delete_entry::mod_data_delete_entry(
			const FString ServerURL,
			const FString Token,
			const int32 _entryid)
{
	Umod_data_delete_entry* Node = NewObject<Umod_data_delete_entry>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_data_delete_entry&entryid=" + FString::FromInt(_entryid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_data_delete_entry::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_data_delete_entry::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_data_delete_entry::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_data_delete_saved_preset* Umod_data_delete_saved_preset::mod_data_delete_saved_preset(
			const FString ServerURL,
			const FString Token,
			const int32 _dataid,
			const FString _presetnames)
{
	Umod_data_delete_saved_preset* Node = NewObject<Umod_data_delete_saved_preset>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_data_delete_saved_preset&dataid=" + FString::FromInt(_dataid) + "&presetnames[0]=" + _presetnames;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_data_delete_saved_preset::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_data_delete_saved_preset::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_data_delete_saved_preset::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_data_get_data_access_information* Umod_data_get_data_access_information::mod_data_get_data_access_information(
			const FString ServerURL,
			const FString Token,
			const int32 _databaseid,
			const int32 _groupid)
{
	Umod_data_get_data_access_information* Node = NewObject<Umod_data_get_data_access_information>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_data_get_data_access_information&databaseid=" + FString::FromInt(_databaseid) + "&groupid=" + FString::FromInt(_groupid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_data_get_data_access_information::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_data_get_data_access_information::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_data_get_data_access_information::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_data_get_databases_by_courses* Umod_data_get_databases_by_courses::mod_data_get_databases_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids)
{
	Umod_data_get_databases_by_courses* Node = NewObject<Umod_data_get_databases_by_courses>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_data_get_databases_by_courses&courseids[0]=" + FString::FromInt(_courseids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_data_get_databases_by_courses::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_data_get_databases_by_courses::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_data_get_databases_by_courses::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_data_get_entries* Umod_data_get_entries::mod_data_get_entries(
			const FString ServerURL,
			const FString Token,
			const int32 _databaseid,
			const int32 _groupid,
			const int32 _returncontents,
			const int32 _sort,
			const FString _order,
			const int32 _page,
			const int32 _perpage)
{
	Umod_data_get_entries* Node = NewObject<Umod_data_get_entries>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_data_get_entries&databaseid=" + FString::FromInt(_databaseid) + "&groupid=" + FString::FromInt(_groupid) + "&returncontents=" + FString::FromInt(_returncontents) + "&sort=" + FString::FromInt(_sort) + "&order=" + _order + "&page=" + FString::FromInt(_page) + "&perpage=" + FString::FromInt(_perpage);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_data_get_entries::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_data_get_entries::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_data_get_entries::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_data_get_entry* Umod_data_get_entry::mod_data_get_entry(
			const FString ServerURL,
			const FString Token,
			const int32 _entryid,
			const int32 _returncontents)
{
	Umod_data_get_entry* Node = NewObject<Umod_data_get_entry>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_data_get_entry&entryid=" + FString::FromInt(_entryid) + "&returncontents=" + FString::FromInt(_returncontents);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_data_get_entry::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_data_get_entry::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_data_get_entry::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_data_get_fields* Umod_data_get_fields::mod_data_get_fields(
			const FString ServerURL,
			const FString Token,
			const int32 _databaseid)
{
	Umod_data_get_fields* Node = NewObject<Umod_data_get_fields>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_data_get_fields&databaseid=" + FString::FromInt(_databaseid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_data_get_fields::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_data_get_fields::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_data_get_fields::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_data_get_mapping_information* Umod_data_get_mapping_information::mod_data_get_mapping_information(
			const FString ServerURL,
			const FString Token,
			const int32 _cmid,
			const FString _importedpreset)
{
	Umod_data_get_mapping_information* Node = NewObject<Umod_data_get_mapping_information>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_data_get_mapping_information&cmid=" + FString::FromInt(_cmid) + "&importedpreset=" + _importedpreset;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_data_get_mapping_information::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_data_get_mapping_information::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_data_get_mapping_information::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_data_search_entries* Umod_data_search_entries::mod_data_search_entries(
			const FString ServerURL,
			const FString Token,
			const int32 _databaseid,
			const FString _advsearchname,
			const FString _advsearchvalue,
			const int32 _groupid,
			const int32 _returncontents,
			const FString _search,
			const int32 _sort,
			const FString _order,
			const int32 _page,
			const int32 _perpage)
{
	Umod_data_search_entries* Node = NewObject<Umod_data_search_entries>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_data_search_entries&databaseid=" + FString::FromInt(_databaseid) + "&groupid=" + FString::FromInt(_groupid) + "&returncontents=" + FString::FromInt(_returncontents) + "&search=" + _search + "&advsearch[0][name]=" + _advsearchname + "&advsearch[0][value]=" + _advsearchvalue + "&sort=" + FString::FromInt(_sort) + "&order=" + _order + "&page=" + FString::FromInt(_page) + "&perpage=" + FString::FromInt(_perpage);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_data_search_entries::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_data_search_entries::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_data_search_entries::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_data_update_entry* Umod_data_update_entry::mod_data_update_entry(
			const FString ServerURL,
			const FString Token,
			const int32 _entryid,
			const int32 _datafieldid,
			const FString _datavalue,
			const FString _datasubfield)
{
	Umod_data_update_entry* Node = NewObject<Umod_data_update_entry>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_data_update_entry&entryid=" + FString::FromInt(_entryid) + "&data[0][fieldid]=" + FString::FromInt(_datafieldid) + "&data[0][subfield]=" + _datasubfield + "&data[0][value]=" + _datavalue;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_data_update_entry::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_data_update_entry::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_data_update_entry::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_data_view_database* Umod_data_view_database::mod_data_view_database(
			const FString ServerURL,
			const FString Token,
			const int32 _databaseid)
{
	Umod_data_view_database* Node = NewObject<Umod_data_view_database>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_data_view_database&databaseid=" + FString::FromInt(_databaseid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_data_view_database::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_data_view_database::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_data_view_database::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_feedback_get_analysis* Umod_feedback_get_analysis::mod_feedback_get_analysis(
			const FString ServerURL,
			const FString Token,
			const int32 _feedbackid,
			const int32 _groupid,
			const int32 _courseid)
{
	Umod_feedback_get_analysis* Node = NewObject<Umod_feedback_get_analysis>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_feedback_get_analysis&feedbackid=" + FString::FromInt(_feedbackid) + "&groupid=" + FString::FromInt(_groupid) + "&courseid=" + FString::FromInt(_courseid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_feedback_get_analysis::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_feedback_get_analysis::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_feedback_get_analysis::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_feedback_get_current_completed_tmp* Umod_feedback_get_current_completed_tmp::mod_feedback_get_current_completed_tmp(
			const FString ServerURL,
			const FString Token,
			const int32 _feedbackid,
			const int32 _courseid)
{
	Umod_feedback_get_current_completed_tmp* Node = NewObject<Umod_feedback_get_current_completed_tmp>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_feedback_get_current_completed_tmp&feedbackid=" + FString::FromInt(_feedbackid) + "&courseid=" + FString::FromInt(_courseid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_feedback_get_current_completed_tmp::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_feedback_get_current_completed_tmp::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_feedback_get_current_completed_tmp::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_feedback_get_feedback_access_information* Umod_feedback_get_feedback_access_information::mod_feedback_get_feedback_access_information(
			const FString ServerURL,
			const FString Token,
			const int32 _feedbackid,
			const int32 _courseid)
{
	Umod_feedback_get_feedback_access_information* Node = NewObject<Umod_feedback_get_feedback_access_information>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_feedback_get_feedback_access_information&feedbackid=" + FString::FromInt(_feedbackid) + "&courseid=" + FString::FromInt(_courseid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_feedback_get_feedback_access_information::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_feedback_get_feedback_access_information::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_feedback_get_feedback_access_information::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_feedback_get_feedbacks_by_courses* Umod_feedback_get_feedbacks_by_courses::mod_feedback_get_feedbacks_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids)
{
	Umod_feedback_get_feedbacks_by_courses* Node = NewObject<Umod_feedback_get_feedbacks_by_courses>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_feedback_get_feedbacks_by_courses&courseids[0]=" + FString::FromInt(_courseids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_feedback_get_feedbacks_by_courses::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_feedback_get_feedbacks_by_courses::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_feedback_get_feedbacks_by_courses::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_feedback_get_finished_responses* Umod_feedback_get_finished_responses::mod_feedback_get_finished_responses(
			const FString ServerURL,
			const FString Token,
			const int32 _feedbackid,
			const int32 _courseid)
{
	Umod_feedback_get_finished_responses* Node = NewObject<Umod_feedback_get_finished_responses>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_feedback_get_finished_responses&feedbackid=" + FString::FromInt(_feedbackid) + "&courseid=" + FString::FromInt(_courseid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_feedback_get_finished_responses::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_feedback_get_finished_responses::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_feedback_get_finished_responses::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_feedback_get_items* Umod_feedback_get_items::mod_feedback_get_items(
			const FString ServerURL,
			const FString Token,
			const int32 _feedbackid,
			const int32 _courseid)
{
	Umod_feedback_get_items* Node = NewObject<Umod_feedback_get_items>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_feedback_get_items&feedbackid=" + FString::FromInt(_feedbackid) + "&courseid=" + FString::FromInt(_courseid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_feedback_get_items::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_feedback_get_items::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_feedback_get_items::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_feedback_get_last_completed* Umod_feedback_get_last_completed::mod_feedback_get_last_completed(
			const FString ServerURL,
			const FString Token,
			const int32 _feedbackid,
			const int32 _courseid)
{
	Umod_feedback_get_last_completed* Node = NewObject<Umod_feedback_get_last_completed>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_feedback_get_last_completed&feedbackid=" + FString::FromInt(_feedbackid) + "&courseid=" + FString::FromInt(_courseid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_feedback_get_last_completed::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_feedback_get_last_completed::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_feedback_get_last_completed::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_feedback_get_non_respondents* Umod_feedback_get_non_respondents::mod_feedback_get_non_respondents(
			const FString ServerURL,
			const FString Token,
			const int32 _feedbackid,
			const int32 _groupid,
			const FString _sort,
			const int32 _page,
			const int32 _perpage,
			const int32 _courseid)
{
	Umod_feedback_get_non_respondents* Node = NewObject<Umod_feedback_get_non_respondents>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_feedback_get_non_respondents&feedbackid=" + FString::FromInt(_feedbackid) + "&groupid=" + FString::FromInt(_groupid) + "&sort=" + _sort + "&page=" + FString::FromInt(_page) + "&perpage=" + FString::FromInt(_perpage) + "&courseid=" + FString::FromInt(_courseid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_feedback_get_non_respondents::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_feedback_get_non_respondents::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_feedback_get_non_respondents::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_feedback_get_page_items* Umod_feedback_get_page_items::mod_feedback_get_page_items(
			const FString ServerURL,
			const FString Token,
			const int32 _feedbackid,
			const int32 _page,
			const int32 _courseid)
{
	Umod_feedback_get_page_items* Node = NewObject<Umod_feedback_get_page_items>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_feedback_get_page_items&feedbackid=" + FString::FromInt(_feedbackid) + "&page=" + FString::FromInt(_page) + "&courseid=" + FString::FromInt(_courseid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_feedback_get_page_items::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_feedback_get_page_items::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_feedback_get_page_items::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_feedback_get_responses_analysis* Umod_feedback_get_responses_analysis::mod_feedback_get_responses_analysis(
			const FString ServerURL,
			const FString Token,
			const int32 _feedbackid,
			const int32 _groupid,
			const int32 _page,
			const int32 _perpage,
			const int32 _courseid)
{
	Umod_feedback_get_responses_analysis* Node = NewObject<Umod_feedback_get_responses_analysis>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_feedback_get_responses_analysis&feedbackid=" + FString::FromInt(_feedbackid) + "&groupid=" + FString::FromInt(_groupid) + "&page=" + FString::FromInt(_page) + "&perpage=" + FString::FromInt(_perpage) + "&courseid=" + FString::FromInt(_courseid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_feedback_get_responses_analysis::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_feedback_get_responses_analysis::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_feedback_get_responses_analysis::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_feedback_get_unfinished_responses* Umod_feedback_get_unfinished_responses::mod_feedback_get_unfinished_responses(
			const FString ServerURL,
			const FString Token,
			const int32 _feedbackid,
			const int32 _courseid)
{
	Umod_feedback_get_unfinished_responses* Node = NewObject<Umod_feedback_get_unfinished_responses>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_feedback_get_unfinished_responses&feedbackid=" + FString::FromInt(_feedbackid) + "&courseid=" + FString::FromInt(_courseid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_feedback_get_unfinished_responses::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_feedback_get_unfinished_responses::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_feedback_get_unfinished_responses::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_feedback_launch_feedback* Umod_feedback_launch_feedback::mod_feedback_launch_feedback(
			const FString ServerURL,
			const FString Token,
			const int32 _feedbackid,
			const int32 _courseid)
{
	Umod_feedback_launch_feedback* Node = NewObject<Umod_feedback_launch_feedback>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_feedback_launch_feedback&feedbackid=" + FString::FromInt(_feedbackid) + "&courseid=" + FString::FromInt(_courseid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_feedback_launch_feedback::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_feedback_launch_feedback::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_feedback_launch_feedback::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_feedback_process_page* Umod_feedback_process_page::mod_feedback_process_page(
			const FString ServerURL,
			const FString Token,
			const int32 _feedbackid,
			const int32 _page,
			const FString _responsesname,
			const FString _responsesvalue,
			const int32 _goprevious,
			const int32 _courseid)
{
	Umod_feedback_process_page* Node = NewObject<Umod_feedback_process_page>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_feedback_process_page&feedbackid=" + FString::FromInt(_feedbackid) + "&page=" + FString::FromInt(_page) + "&responses[0][name]=" + _responsesname + "&responses[0][value]=" + _responsesvalue + "&goprevious=" + FString::FromInt(_goprevious) + "&courseid=" + FString::FromInt(_courseid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_feedback_process_page::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_feedback_process_page::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_feedback_process_page::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_feedback_view_feedback* Umod_feedback_view_feedback::mod_feedback_view_feedback(
			const FString ServerURL,
			const FString Token,
			const int32 _feedbackid,
			const int32 _moduleviewed,
			const int32 _courseid)
{
	Umod_feedback_view_feedback* Node = NewObject<Umod_feedback_view_feedback>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_feedback_view_feedback&feedbackid=" + FString::FromInt(_feedbackid) + "&moduleviewed=" + FString::FromInt(_moduleviewed) + "&courseid=" + FString::FromInt(_courseid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_feedback_view_feedback::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_feedback_view_feedback::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_feedback_view_feedback::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_folder_get_folders_by_courses* Umod_folder_get_folders_by_courses::mod_folder_get_folders_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids)
{
	Umod_folder_get_folders_by_courses* Node = NewObject<Umod_folder_get_folders_by_courses>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_folder_get_folders_by_courses&courseids[0]=" + FString::FromInt(_courseids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_folder_get_folders_by_courses::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_folder_get_folders_by_courses::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_folder_get_folders_by_courses::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_folder_view_folder* Umod_folder_view_folder::mod_folder_view_folder(
			const FString ServerURL,
			const FString Token,
			const int32 _folderid)
{
	Umod_folder_view_folder* Node = NewObject<Umod_folder_view_folder>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_folder_view_folder&folderid=" + FString::FromInt(_folderid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_folder_view_folder::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_folder_view_folder::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_folder_view_folder::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_forum_add_discussion* Umod_forum_add_discussion::mod_forum_add_discussion(
			const FString ServerURL,
			const FString Token,
			const int32 _forumid,
			const FString _subject,
			const FString _message,
			const FString _optionsname,
			const FString _optionsvalue,
			const int32 _groupid)
{
	Umod_forum_add_discussion* Node = NewObject<Umod_forum_add_discussion>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_forum_add_discussion&forumid=" + FString::FromInt(_forumid) + "&subject=" + _subject + "&message=" + _message + "&groupid=" + FString::FromInt(_groupid) + "&options[0][name]=" + _optionsname + "&options[0][value]=" + _optionsvalue;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_forum_add_discussion::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_forum_add_discussion::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_forum_add_discussion::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_forum_add_discussion_post* Umod_forum_add_discussion_post::mod_forum_add_discussion_post(
			const FString ServerURL,
			const FString Token,
			const int32 _postid,
			const FString _subject,
			const FString _optionsname,
			const FString _optionsvalue,
			const FString _message,
			const int32 _messageformat)
{
	Umod_forum_add_discussion_post* Node = NewObject<Umod_forum_add_discussion_post>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_forum_add_discussion_post&postid=" + FString::FromInt(_postid) + "&subject=" + _subject + "&message=" + _message + "&options[0][name]=" + _optionsname + "&options[0][value]=" + _optionsvalue + "&messageformat=" + FString::FromInt(_messageformat);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_forum_add_discussion_post::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_forum_add_discussion_post::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_forum_add_discussion_post::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_forum_can_add_discussion* Umod_forum_can_add_discussion::mod_forum_can_add_discussion(
			const FString ServerURL,
			const FString Token,
			const int32 _forumid,
			const int32 _groupid)
{
	Umod_forum_can_add_discussion* Node = NewObject<Umod_forum_can_add_discussion>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_forum_can_add_discussion&forumid=" + FString::FromInt(_forumid) + "&groupid=" + FString::FromInt(_groupid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_forum_can_add_discussion::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_forum_can_add_discussion::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_forum_can_add_discussion::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_forum_delete_post* Umod_forum_delete_post::mod_forum_delete_post(
			const FString ServerURL,
			const FString Token,
			const int32 _postid)
{
	Umod_forum_delete_post* Node = NewObject<Umod_forum_delete_post>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_forum_delete_post&postid=" + FString::FromInt(_postid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_forum_delete_post::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_forum_delete_post::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_forum_delete_post::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_forum_get_discussion_post* Umod_forum_get_discussion_post::mod_forum_get_discussion_post(
			const FString ServerURL,
			const FString Token,
			const int32 _postid)
{
	Umod_forum_get_discussion_post* Node = NewObject<Umod_forum_get_discussion_post>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_forum_get_discussion_post&postid=" + FString::FromInt(_postid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_forum_get_discussion_post::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_forum_get_discussion_post::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_forum_get_discussion_post::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_forum_get_discussion_posts* Umod_forum_get_discussion_posts::mod_forum_get_discussion_posts(
			const FString ServerURL,
			const FString Token,
			const int32 _discussionid,
			const FString _sortby,
			const FString _sortdirection,
			const int32 _includeinlineattachments)
{
	Umod_forum_get_discussion_posts* Node = NewObject<Umod_forum_get_discussion_posts>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_forum_get_discussion_posts&discussionid=" + FString::FromInt(_discussionid) + "&sortby=" + _sortby + "&sortdirection=" + _sortdirection + "&includeinlineattachments=" + FString::FromInt(_includeinlineattachments);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_forum_get_discussion_posts::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_forum_get_discussion_posts::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_forum_get_discussion_posts::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_forum_get_discussion_posts_by_userid* Umod_forum_get_discussion_posts_by_userid::mod_forum_get_discussion_posts_by_userid(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _cmid,
			const FString _sortby,
			const FString _sortdirection)
{
	Umod_forum_get_discussion_posts_by_userid* Node = NewObject<Umod_forum_get_discussion_posts_by_userid>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_forum_get_discussion_posts_by_userid&userid=" + FString::FromInt(_userid) + "&cmid=" + FString::FromInt(_cmid) + "&sortby=" + _sortby + "&sortdirection=" + _sortdirection;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_forum_get_discussion_posts_by_userid::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_forum_get_discussion_posts_by_userid::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_forum_get_discussion_posts_by_userid::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_forum_get_forum_access_information* Umod_forum_get_forum_access_information::mod_forum_get_forum_access_information(
			const FString ServerURL,
			const FString Token,
			const int32 _forumid)
{
	Umod_forum_get_forum_access_information* Node = NewObject<Umod_forum_get_forum_access_information>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_forum_get_forum_access_information&forumid=" + FString::FromInt(_forumid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_forum_get_forum_access_information::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_forum_get_forum_access_information::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_forum_get_forum_access_information::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_forum_get_forum_discussions* Umod_forum_get_forum_discussions::mod_forum_get_forum_discussions(
			const FString ServerURL,
			const FString Token,
			const int32 _forumid,
			const int32 _sortorder,
			const int32 _page,
			const int32 _perpage,
			const int32 _groupid)
{
	Umod_forum_get_forum_discussions* Node = NewObject<Umod_forum_get_forum_discussions>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_forum_get_forum_discussions&forumid=" + FString::FromInt(_forumid) + "&sortorder=" + FString::FromInt(_sortorder) + "&page=" + FString::FromInt(_page) + "&perpage=" + FString::FromInt(_perpage) + "&groupid=" + FString::FromInt(_groupid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_forum_get_forum_discussions::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_forum_get_forum_discussions::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_forum_get_forum_discussions::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_forum_get_forums_by_courses* Umod_forum_get_forums_by_courses::mod_forum_get_forums_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids)
{
	Umod_forum_get_forums_by_courses* Node = NewObject<Umod_forum_get_forums_by_courses>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_forum_get_forums_by_courses&courseids[0]=" + FString::FromInt(_courseids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_forum_get_forums_by_courses::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_forum_get_forums_by_courses::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_forum_get_forums_by_courses::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_forum_prepare_draft_area_for_post* Umod_forum_prepare_draft_area_for_post::mod_forum_prepare_draft_area_for_post(
			const FString ServerURL,
			const FString Token,
			const int32 _postid,
			const FString _area,
			const FString _filestokeepfilename,
			const FString _filestokeepfilepath,
			const int32 _draftitemid)
{
	Umod_forum_prepare_draft_area_for_post* Node = NewObject<Umod_forum_prepare_draft_area_for_post>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_forum_prepare_draft_area_for_post&postid=" + FString::FromInt(_postid) + "&area=" + _area + "&draftitemid=" + FString::FromInt(_draftitemid) + "&filestokeep[0][filename]=" + _filestokeepfilename + "&filestokeep[0][filepath]=" + _filestokeepfilepath;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_forum_prepare_draft_area_for_post::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_forum_prepare_draft_area_for_post::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_forum_prepare_draft_area_for_post::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_forum_set_lock_state* Umod_forum_set_lock_state::mod_forum_set_lock_state(
			const FString ServerURL,
			const FString Token,
			const int32 _forumid,
			const int32 _discussionid,
			const int32 _targetstate)
{
	Umod_forum_set_lock_state* Node = NewObject<Umod_forum_set_lock_state>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_forum_set_lock_state&forumid=" + FString::FromInt(_forumid) + "&discussionid=" + FString::FromInt(_discussionid) + "&targetstate=" + FString::FromInt(_targetstate);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_forum_set_lock_state::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_forum_set_lock_state::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_forum_set_lock_state::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_forum_set_pin_state* Umod_forum_set_pin_state::mod_forum_set_pin_state(
			const FString ServerURL,
			const FString Token,
			const int32 _discussionid,
			const int32 _targetstate)
{
	Umod_forum_set_pin_state* Node = NewObject<Umod_forum_set_pin_state>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_forum_set_pin_state&discussionid=" + FString::FromInt(_discussionid) + "&targetstate=" + FString::FromInt(_targetstate);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_forum_set_pin_state::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_forum_set_pin_state::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_forum_set_pin_state::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_forum_set_subscription_state* Umod_forum_set_subscription_state::mod_forum_set_subscription_state(
			const FString ServerURL,
			const FString Token,
			const int32 _forumid,
			const int32 _discussionid,
			const int32 _targetstate)
{
	Umod_forum_set_subscription_state* Node = NewObject<Umod_forum_set_subscription_state>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_forum_set_subscription_state&forumid=" + FString::FromInt(_forumid) + "&discussionid=" + FString::FromInt(_discussionid) + "&targetstate=" + FString::FromInt(_targetstate);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_forum_set_subscription_state::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_forum_set_subscription_state::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_forum_set_subscription_state::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_forum_toggle_favourite_state* Umod_forum_toggle_favourite_state::mod_forum_toggle_favourite_state(
			const FString ServerURL,
			const FString Token,
			const int32 _discussionid,
			const int32 _targetstate)
{
	Umod_forum_toggle_favourite_state* Node = NewObject<Umod_forum_toggle_favourite_state>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_forum_toggle_favourite_state&discussionid=" + FString::FromInt(_discussionid) + "&targetstate=" + FString::FromInt(_targetstate);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_forum_toggle_favourite_state::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_forum_toggle_favourite_state::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_forum_toggle_favourite_state::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_forum_update_discussion_post* Umod_forum_update_discussion_post::mod_forum_update_discussion_post(
			const FString ServerURL,
			const FString Token,
			const int32 _postid,
			const FString _optionsname,
			const FString _optionsvalue,
			const FString _subject,
			const FString _message,
			const int32 _messageformat)
{
	Umod_forum_update_discussion_post* Node = NewObject<Umod_forum_update_discussion_post>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_forum_update_discussion_post&postid=" + FString::FromInt(_postid) + "&subject=" + _subject + "&message=" + _message + "&messageformat=" + FString::FromInt(_messageformat) + "&options[0][name]=" + _optionsname + "&options[0][value]=" + _optionsvalue;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_forum_update_discussion_post::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_forum_update_discussion_post::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_forum_update_discussion_post::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_forum_view_forum* Umod_forum_view_forum::mod_forum_view_forum(
			const FString ServerURL,
			const FString Token,
			const int32 _forumid)
{
	Umod_forum_view_forum* Node = NewObject<Umod_forum_view_forum>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_forum_view_forum&forumid=" + FString::FromInt(_forumid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_forum_view_forum::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_forum_view_forum::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_forum_view_forum::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_forum_view_forum_discussion* Umod_forum_view_forum_discussion::mod_forum_view_forum_discussion(
			const FString ServerURL,
			const FString Token,
			const int32 _discussionid)
{
	Umod_forum_view_forum_discussion* Node = NewObject<Umod_forum_view_forum_discussion>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_forum_view_forum_discussion&discussionid=" + FString::FromInt(_discussionid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_forum_view_forum_discussion::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_forum_view_forum_discussion::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_forum_view_forum_discussion::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_glossary_add_entry* Umod_glossary_add_entry::mod_glossary_add_entry(
			const FString ServerURL,
			const FString Token,
			const int32 _glossaryid,
			const FString _concept,
			const FString _definition,
			const int32 _definitionformat,
			const FString _optionsname,
			const FString _optionsvalue)
{
	Umod_glossary_add_entry* Node = NewObject<Umod_glossary_add_entry>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_glossary_add_entry&glossaryid=" + FString::FromInt(_glossaryid) + "&concept=" + _concept + "&definition=" + _definition + "&definitionformat=" + FString::FromInt(_definitionformat) + "&options[0][name]=" + _optionsname + "&options[0][value]=" + _optionsvalue;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_glossary_add_entry::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_glossary_add_entry::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_glossary_add_entry::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_glossary_delete_entry* Umod_glossary_delete_entry::mod_glossary_delete_entry(
			const FString ServerURL,
			const FString Token,
			const int32 _entryid)
{
	Umod_glossary_delete_entry* Node = NewObject<Umod_glossary_delete_entry>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_glossary_delete_entry&entryid=" + FString::FromInt(_entryid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_glossary_delete_entry::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_glossary_delete_entry::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_glossary_delete_entry::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_glossary_get_authors* Umod_glossary_get_authors::mod_glossary_get_authors(
			const FString ServerURL,
			const FString Token,
			const int32 _id,
			const int32 _from,
			const int32 _limit,
			const int32 _optionsincludenotapproved)
{
	Umod_glossary_get_authors* Node = NewObject<Umod_glossary_get_authors>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_glossary_get_authors&id=" + FString::FromInt(_id) + "&from=" + FString::FromInt(_from) + "&limit=" + FString::FromInt(_limit) + "&options[includenotapproved]=" + FString::FromInt(_optionsincludenotapproved);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_glossary_get_authors::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_glossary_get_authors::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_glossary_get_authors::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_glossary_get_categories* Umod_glossary_get_categories::mod_glossary_get_categories(
			const FString ServerURL,
			const FString Token,
			const int32 _id,
			const int32 _from,
			const int32 _limit)
{
	Umod_glossary_get_categories* Node = NewObject<Umod_glossary_get_categories>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_glossary_get_categories&id=" + FString::FromInt(_id) + "&from=" + FString::FromInt(_from) + "&limit=" + FString::FromInt(_limit);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_glossary_get_categories::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_glossary_get_categories::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_glossary_get_categories::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_glossary_get_entries_by_author* Umod_glossary_get_entries_by_author::mod_glossary_get_entries_by_author(
			const FString ServerURL,
			const FString Token,
			const int32 _id,
			const FString _letter,
			const FString _field,
			const FString _sort,
			const int32 _from,
			const int32 _limit,
			const int32 _optionsincludenotapproved)
{
	Umod_glossary_get_entries_by_author* Node = NewObject<Umod_glossary_get_entries_by_author>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_glossary_get_entries_by_author&id=" + FString::FromInt(_id) + "&letter=" + _letter + "&field=" + _field + "&sort=" + _sort + "&from=" + FString::FromInt(_from) + "&limit=" + FString::FromInt(_limit) + "&options[includenotapproved]=" + FString::FromInt(_optionsincludenotapproved);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_glossary_get_entries_by_author::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_glossary_get_entries_by_author::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_glossary_get_entries_by_author::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_glossary_get_entries_by_author_id* Umod_glossary_get_entries_by_author_id::mod_glossary_get_entries_by_author_id(
			const FString ServerURL,
			const FString Token,
			const int32 _id,
			const int32 _authorid,
			const FString _order,
			const FString _sort,
			const int32 _from,
			const int32 _limit,
			const int32 _optionsincludenotapproved)
{
	Umod_glossary_get_entries_by_author_id* Node = NewObject<Umod_glossary_get_entries_by_author_id>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_glossary_get_entries_by_author_id&id=" + FString::FromInt(_id) + "&authorid=" + FString::FromInt(_authorid) + "&order=" + _order + "&sort=" + _sort + "&from=" + FString::FromInt(_from) + "&limit=" + FString::FromInt(_limit) + "&options[includenotapproved]=" + FString::FromInt(_optionsincludenotapproved);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_glossary_get_entries_by_author_id::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_glossary_get_entries_by_author_id::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_glossary_get_entries_by_author_id::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_glossary_get_entries_by_category* Umod_glossary_get_entries_by_category::mod_glossary_get_entries_by_category(
			const FString ServerURL,
			const FString Token,
			const int32 _id,
			const int32 _categoryid,
			const int32 _from,
			const int32 _limit,
			const int32 _optionsincludenotapproved)
{
	Umod_glossary_get_entries_by_category* Node = NewObject<Umod_glossary_get_entries_by_category>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_glossary_get_entries_by_category&id=" + FString::FromInt(_id) + "&categoryid=" + FString::FromInt(_categoryid) + "&from=" + FString::FromInt(_from) + "&limit=" + FString::FromInt(_limit) + "&options[includenotapproved]=" + FString::FromInt(_optionsincludenotapproved);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_glossary_get_entries_by_category::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_glossary_get_entries_by_category::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_glossary_get_entries_by_category::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_glossary_get_entries_by_date* Umod_glossary_get_entries_by_date::mod_glossary_get_entries_by_date(
			const FString ServerURL,
			const FString Token,
			const int32 _id,
			const FString _order,
			const FString _sort,
			const int32 _from,
			const int32 _limit,
			const int32 _optionsincludenotapproved)
{
	Umod_glossary_get_entries_by_date* Node = NewObject<Umod_glossary_get_entries_by_date>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_glossary_get_entries_by_date&id=" + FString::FromInt(_id) + "&order=" + _order + "&sort=" + _sort + "&from=" + FString::FromInt(_from) + "&limit=" + FString::FromInt(_limit) + "&options[includenotapproved]=" + FString::FromInt(_optionsincludenotapproved);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_glossary_get_entries_by_date::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_glossary_get_entries_by_date::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_glossary_get_entries_by_date::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_glossary_get_entries_by_letter* Umod_glossary_get_entries_by_letter::mod_glossary_get_entries_by_letter(
			const FString ServerURL,
			const FString Token,
			const int32 _id,
			const FString _letter,
			const int32 _from,
			const int32 _limit,
			const int32 _optionsincludenotapproved)
{
	Umod_glossary_get_entries_by_letter* Node = NewObject<Umod_glossary_get_entries_by_letter>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_glossary_get_entries_by_letter&id=" + FString::FromInt(_id) + "&letter=" + _letter + "&from=" + FString::FromInt(_from) + "&limit=" + FString::FromInt(_limit) + "&options[includenotapproved]=" + FString::FromInt(_optionsincludenotapproved);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_glossary_get_entries_by_letter::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_glossary_get_entries_by_letter::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_glossary_get_entries_by_letter::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_glossary_get_entries_by_search* Umod_glossary_get_entries_by_search::mod_glossary_get_entries_by_search(
			const FString ServerURL,
			const FString Token,
			const int32 _id,
			const FString _query,
			const int32 _fullsearch,
			const FString _order,
			const FString _sort,
			const int32 _from,
			const int32 _limit,
			const int32 _optionsincludenotapproved)
{
	Umod_glossary_get_entries_by_search* Node = NewObject<Umod_glossary_get_entries_by_search>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_glossary_get_entries_by_search&id=" + FString::FromInt(_id) + "&query=" + _query + "&fullsearch=" + FString::FromInt(_fullsearch) + "&order=" + _order + "&sort=" + _sort + "&from=" + FString::FromInt(_from) + "&limit=" + FString::FromInt(_limit) + "&options[includenotapproved]=" + FString::FromInt(_optionsincludenotapproved);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_glossary_get_entries_by_search::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_glossary_get_entries_by_search::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_glossary_get_entries_by_search::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_glossary_get_entries_by_term* Umod_glossary_get_entries_by_term::mod_glossary_get_entries_by_term(
			const FString ServerURL,
			const FString Token,
			const int32 _id,
			const FString _term,
			const int32 _from,
			const int32 _limit,
			const int32 _optionsincludenotapproved)
{
	Umod_glossary_get_entries_by_term* Node = NewObject<Umod_glossary_get_entries_by_term>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_glossary_get_entries_by_term&id=" + FString::FromInt(_id) + "&term=" + _term + "&from=" + FString::FromInt(_from) + "&limit=" + FString::FromInt(_limit) + "&options[includenotapproved]=" + FString::FromInt(_optionsincludenotapproved);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_glossary_get_entries_by_term::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_glossary_get_entries_by_term::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_glossary_get_entries_by_term::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_glossary_get_entries_to_approve* Umod_glossary_get_entries_to_approve::mod_glossary_get_entries_to_approve(
			const FString ServerURL,
			const FString Token,
			const int32 _id,
			const FString _letter,
			const FString _order,
			const FString _sort,
			const int32 _from,
			const int32 _limit)
{
	Umod_glossary_get_entries_to_approve* Node = NewObject<Umod_glossary_get_entries_to_approve>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_glossary_get_entries_to_approve&id=" + FString::FromInt(_id) + "&letter=" + _letter + "&order=" + _order + "&sort=" + _sort + "&from=" + FString::FromInt(_from) + "&limit=" + FString::FromInt(_limit);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_glossary_get_entries_to_approve::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_glossary_get_entries_to_approve::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_glossary_get_entries_to_approve::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_glossary_get_entry_by_id* Umod_glossary_get_entry_by_id::mod_glossary_get_entry_by_id(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Umod_glossary_get_entry_by_id* Node = NewObject<Umod_glossary_get_entry_by_id>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_glossary_get_entry_by_id&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_glossary_get_entry_by_id::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_glossary_get_entry_by_id::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_glossary_get_entry_by_id::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_glossary_get_glossaries_by_courses* Umod_glossary_get_glossaries_by_courses::mod_glossary_get_glossaries_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids)
{
	Umod_glossary_get_glossaries_by_courses* Node = NewObject<Umod_glossary_get_glossaries_by_courses>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_glossary_get_glossaries_by_courses&courseids[0]=" + FString::FromInt(_courseids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_glossary_get_glossaries_by_courses::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_glossary_get_glossaries_by_courses::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_glossary_get_glossaries_by_courses::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_glossary_prepare_entry_for_edition* Umod_glossary_prepare_entry_for_edition::mod_glossary_prepare_entry_for_edition(
			const FString ServerURL,
			const FString Token,
			const int32 _entryid)
{
	Umod_glossary_prepare_entry_for_edition* Node = NewObject<Umod_glossary_prepare_entry_for_edition>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_glossary_prepare_entry_for_edition&entryid=" + FString::FromInt(_entryid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_glossary_prepare_entry_for_edition::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_glossary_prepare_entry_for_edition::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_glossary_prepare_entry_for_edition::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_glossary_update_entry* Umod_glossary_update_entry::mod_glossary_update_entry(
			const FString ServerURL,
			const FString Token,
			const int32 _entryid,
			const FString _concept,
			const FString _definition,
			const int32 _definitionformat,
			const FString _optionsname,
			const FString _optionsvalue)
{
	Umod_glossary_update_entry* Node = NewObject<Umod_glossary_update_entry>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_glossary_update_entry&entryid=" + FString::FromInt(_entryid) + "&concept=" + _concept + "&definition=" + _definition + "&definitionformat=" + FString::FromInt(_definitionformat) + "&options[0][name]=" + _optionsname + "&options[0][value]=" + _optionsvalue;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_glossary_update_entry::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_glossary_update_entry::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_glossary_update_entry::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_glossary_view_entry* Umod_glossary_view_entry::mod_glossary_view_entry(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Umod_glossary_view_entry* Node = NewObject<Umod_glossary_view_entry>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_glossary_view_entry&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_glossary_view_entry::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_glossary_view_entry::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_glossary_view_entry::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_glossary_view_glossary* Umod_glossary_view_glossary::mod_glossary_view_glossary(
			const FString ServerURL,
			const FString Token,
			const int32 _id,
			const FString _mode)
{
	Umod_glossary_view_glossary* Node = NewObject<Umod_glossary_view_glossary>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_glossary_view_glossary&id=" + FString::FromInt(_id) + "&mode=" + _mode;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_glossary_view_glossary::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_glossary_view_glossary::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_glossary_view_glossary::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_h5pactivity_get_attempts* Umod_h5pactivity_get_attempts::mod_h5pactivity_get_attempts(
			const FString ServerURL,
			const FString Token,
			const int32 _h5pactivityid,
			const int32 _userids)
{
	Umod_h5pactivity_get_attempts* Node = NewObject<Umod_h5pactivity_get_attempts>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_h5pactivity_get_attempts&h5pactivityid=" + FString::FromInt(_h5pactivityid) + "&userids[0]=" + FString::FromInt(_userids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_h5pactivity_get_attempts::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_h5pactivity_get_attempts::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_h5pactivity_get_attempts::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_h5pactivity_get_h5pactivities_by_courses* Umod_h5pactivity_get_h5pactivities_by_courses::mod_h5pactivity_get_h5pactivities_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids)
{
	Umod_h5pactivity_get_h5pactivities_by_courses* Node = NewObject<Umod_h5pactivity_get_h5pactivities_by_courses>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_h5pactivity_get_h5pactivities_by_courses&courseids[0]=" + FString::FromInt(_courseids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_h5pactivity_get_h5pactivities_by_courses::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_h5pactivity_get_h5pactivities_by_courses::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_h5pactivity_get_h5pactivities_by_courses::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_h5pactivity_get_h5pactivity_access_information* Umod_h5pactivity_get_h5pactivity_access_information::mod_h5pactivity_get_h5pactivity_access_information(
			const FString ServerURL,
			const FString Token,
			const int32 _h5pactivityid)
{
	Umod_h5pactivity_get_h5pactivity_access_information* Node = NewObject<Umod_h5pactivity_get_h5pactivity_access_information>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_h5pactivity_get_h5pactivity_access_information&h5pactivityid=" + FString::FromInt(_h5pactivityid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_h5pactivity_get_h5pactivity_access_information::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_h5pactivity_get_h5pactivity_access_information::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_h5pactivity_get_h5pactivity_access_information::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_h5pactivity_get_results* Umod_h5pactivity_get_results::mod_h5pactivity_get_results(
			const FString ServerURL,
			const FString Token,
			const int32 _h5pactivityid,
			const int32 _attemptids)
{
	Umod_h5pactivity_get_results* Node = NewObject<Umod_h5pactivity_get_results>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_h5pactivity_get_results&h5pactivityid=" + FString::FromInt(_h5pactivityid) + "&attemptids[0]=" + FString::FromInt(_attemptids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_h5pactivity_get_results::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_h5pactivity_get_results::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_h5pactivity_get_results::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_h5pactivity_get_user_attempts* Umod_h5pactivity_get_user_attempts::mod_h5pactivity_get_user_attempts(
			const FString ServerURL,
			const FString Token,
			const int32 _h5pactivityid,
			const FString _sortorder,
			const int32 _page,
			const int32 _perpage,
			const FString _firstinitial,
			const FString _lastinitial)
{
	Umod_h5pactivity_get_user_attempts* Node = NewObject<Umod_h5pactivity_get_user_attempts>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_h5pactivity_get_user_attempts&h5pactivityid=" + FString::FromInt(_h5pactivityid) + "&sortorder=" + _sortorder + "&page=" + FString::FromInt(_page) + "&perpage=" + FString::FromInt(_perpage) + "&firstinitial=" + _firstinitial + "&lastinitial=" + _lastinitial;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_h5pactivity_get_user_attempts::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_h5pactivity_get_user_attempts::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_h5pactivity_get_user_attempts::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_h5pactivity_log_report_viewed* Umod_h5pactivity_log_report_viewed::mod_h5pactivity_log_report_viewed(
			const FString ServerURL,
			const FString Token,
			const int32 _h5pactivityid,
			const int32 _userid,
			const int32 _attemptid)
{
	Umod_h5pactivity_log_report_viewed* Node = NewObject<Umod_h5pactivity_log_report_viewed>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_h5pactivity_log_report_viewed&h5pactivityid=" + FString::FromInt(_h5pactivityid) + "&userid=" + FString::FromInt(_userid) + "&attemptid=" + FString::FromInt(_attemptid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_h5pactivity_log_report_viewed::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_h5pactivity_log_report_viewed::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_h5pactivity_log_report_viewed::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_h5pactivity_view_h5pactivity* Umod_h5pactivity_view_h5pactivity::mod_h5pactivity_view_h5pactivity(
			const FString ServerURL,
			const FString Token,
			const int32 _h5pactivityid)
{
	Umod_h5pactivity_view_h5pactivity* Node = NewObject<Umod_h5pactivity_view_h5pactivity>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_h5pactivity_view_h5pactivity&h5pactivityid=" + FString::FromInt(_h5pactivityid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_h5pactivity_view_h5pactivity::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_h5pactivity_view_h5pactivity::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_h5pactivity_view_h5pactivity::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_imscp_get_imscps_by_courses* Umod_imscp_get_imscps_by_courses::mod_imscp_get_imscps_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids)
{
	Umod_imscp_get_imscps_by_courses* Node = NewObject<Umod_imscp_get_imscps_by_courses>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_imscp_get_imscps_by_courses&courseids[0]=" + FString::FromInt(_courseids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_imscp_get_imscps_by_courses::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_imscp_get_imscps_by_courses::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_imscp_get_imscps_by_courses::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_imscp_view_imscp* Umod_imscp_view_imscp::mod_imscp_view_imscp(
			const FString ServerURL,
			const FString Token,
			const int32 _imscpid)
{
	Umod_imscp_view_imscp* Node = NewObject<Umod_imscp_view_imscp>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_imscp_view_imscp&imscpid=" + FString::FromInt(_imscpid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_imscp_view_imscp::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_imscp_view_imscp::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_imscp_view_imscp::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_label_get_labels_by_courses* Umod_label_get_labels_by_courses::mod_label_get_labels_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids)
{
	Umod_label_get_labels_by_courses* Node = NewObject<Umod_label_get_labels_by_courses>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_label_get_labels_by_courses&courseids[0]=" + FString::FromInt(_courseids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_label_get_labels_by_courses::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_label_get_labels_by_courses::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_label_get_labels_by_courses::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_lesson_finish_attempt* Umod_lesson_finish_attempt::mod_lesson_finish_attempt(
			const FString ServerURL,
			const FString Token,
			const int32 _lessonid,
			const FString _password,
			const int32 _outoftime,
			const int32 _review)
{
	Umod_lesson_finish_attempt* Node = NewObject<Umod_lesson_finish_attempt>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_lesson_finish_attempt&lessonid=" + FString::FromInt(_lessonid) + "&password=" + _password + "&outoftime=" + FString::FromInt(_outoftime) + "&review=" + FString::FromInt(_review);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_lesson_finish_attempt::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_lesson_finish_attempt::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_lesson_finish_attempt::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_lesson_get_attempts_overview* Umod_lesson_get_attempts_overview::mod_lesson_get_attempts_overview(
			const FString ServerURL,
			const FString Token,
			const int32 _lessonid,
			const int32 _groupid)
{
	Umod_lesson_get_attempts_overview* Node = NewObject<Umod_lesson_get_attempts_overview>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_lesson_get_attempts_overview&lessonid=" + FString::FromInt(_lessonid) + "&groupid=" + FString::FromInt(_groupid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_lesson_get_attempts_overview::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_lesson_get_attempts_overview::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_lesson_get_attempts_overview::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_lesson_get_content_pages_viewed* Umod_lesson_get_content_pages_viewed::mod_lesson_get_content_pages_viewed(
			const FString ServerURL,
			const FString Token,
			const int32 _lessonid,
			const int32 _lessonattempt,
			const int32 _userid)
{
	Umod_lesson_get_content_pages_viewed* Node = NewObject<Umod_lesson_get_content_pages_viewed>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_lesson_get_content_pages_viewed&lessonid=" + FString::FromInt(_lessonid) + "&lessonattempt=" + FString::FromInt(_lessonattempt) + "&userid=" + FString::FromInt(_userid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_lesson_get_content_pages_viewed::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_lesson_get_content_pages_viewed::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_lesson_get_content_pages_viewed::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_lesson_get_lesson* Umod_lesson_get_lesson::mod_lesson_get_lesson(
			const FString ServerURL,
			const FString Token,
			const int32 _lessonid,
			const FString _password)
{
	Umod_lesson_get_lesson* Node = NewObject<Umod_lesson_get_lesson>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_lesson_get_lesson&lessonid=" + FString::FromInt(_lessonid) + "&password=" + _password;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_lesson_get_lesson::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_lesson_get_lesson::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_lesson_get_lesson::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_lesson_get_lesson_access_information* Umod_lesson_get_lesson_access_information::mod_lesson_get_lesson_access_information(
			const FString ServerURL,
			const FString Token,
			const int32 _lessonid)
{
	Umod_lesson_get_lesson_access_information* Node = NewObject<Umod_lesson_get_lesson_access_information>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_lesson_get_lesson_access_information&lessonid=" + FString::FromInt(_lessonid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_lesson_get_lesson_access_information::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_lesson_get_lesson_access_information::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_lesson_get_lesson_access_information::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_lesson_get_lessons_by_courses* Umod_lesson_get_lessons_by_courses::mod_lesson_get_lessons_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids)
{
	Umod_lesson_get_lessons_by_courses* Node = NewObject<Umod_lesson_get_lessons_by_courses>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_lesson_get_lessons_by_courses&courseids[0]=" + FString::FromInt(_courseids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_lesson_get_lessons_by_courses::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_lesson_get_lessons_by_courses::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_lesson_get_lessons_by_courses::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_lesson_get_page_data* Umod_lesson_get_page_data::mod_lesson_get_page_data(
			const FString ServerURL,
			const FString Token,
			const int32 _lessonid,
			const int32 _pageid,
			const FString _password,
			const int32 _review,
			const int32 _returncontents)
{
	Umod_lesson_get_page_data* Node = NewObject<Umod_lesson_get_page_data>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_lesson_get_page_data&lessonid=" + FString::FromInt(_lessonid) + "&pageid=" + FString::FromInt(_pageid) + "&password=" + _password + "&review=" + FString::FromInt(_review) + "&returncontents=" + FString::FromInt(_returncontents);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_lesson_get_page_data::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_lesson_get_page_data::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_lesson_get_page_data::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_lesson_get_pages* Umod_lesson_get_pages::mod_lesson_get_pages(
			const FString ServerURL,
			const FString Token,
			const int32 _lessonid,
			const FString _password)
{
	Umod_lesson_get_pages* Node = NewObject<Umod_lesson_get_pages>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_lesson_get_pages&lessonid=" + FString::FromInt(_lessonid) + "&password=" + _password;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_lesson_get_pages::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_lesson_get_pages::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_lesson_get_pages::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_lesson_get_pages_possible_jumps* Umod_lesson_get_pages_possible_jumps::mod_lesson_get_pages_possible_jumps(
			const FString ServerURL,
			const FString Token,
			const int32 _lessonid)
{
	Umod_lesson_get_pages_possible_jumps* Node = NewObject<Umod_lesson_get_pages_possible_jumps>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_lesson_get_pages_possible_jumps&lessonid=" + FString::FromInt(_lessonid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_lesson_get_pages_possible_jumps::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_lesson_get_pages_possible_jumps::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_lesson_get_pages_possible_jumps::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_lesson_get_questions_attempts* Umod_lesson_get_questions_attempts::mod_lesson_get_questions_attempts(
			const FString ServerURL,
			const FString Token,
			const int32 _lessonid,
			const int32 _attempt,
			const int32 _correct,
			const int32 _pageid,
			const int32 _userid)
{
	Umod_lesson_get_questions_attempts* Node = NewObject<Umod_lesson_get_questions_attempts>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_lesson_get_questions_attempts&lessonid=" + FString::FromInt(_lessonid) + "&attempt=" + FString::FromInt(_attempt) + "&correct=" + FString::FromInt(_correct) + "&pageid=" + FString::FromInt(_pageid) + "&userid=" + FString::FromInt(_userid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_lesson_get_questions_attempts::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_lesson_get_questions_attempts::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_lesson_get_questions_attempts::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_lesson_get_user_attempt* Umod_lesson_get_user_attempt::mod_lesson_get_user_attempt(
			const FString ServerURL,
			const FString Token,
			const int32 _lessonid,
			const int32 _userid,
			const int32 _lessonattempt)
{
	Umod_lesson_get_user_attempt* Node = NewObject<Umod_lesson_get_user_attempt>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_lesson_get_user_attempt&lessonid=" + FString::FromInt(_lessonid) + "&userid=" + FString::FromInt(_userid) + "&lessonattempt=" + FString::FromInt(_lessonattempt);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_lesson_get_user_attempt::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_lesson_get_user_attempt::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_lesson_get_user_attempt::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_lesson_get_user_attempt_grade* Umod_lesson_get_user_attempt_grade::mod_lesson_get_user_attempt_grade(
			const FString ServerURL,
			const FString Token,
			const int32 _lessonid,
			const int32 _lessonattempt,
			const int32 _userid)
{
	Umod_lesson_get_user_attempt_grade* Node = NewObject<Umod_lesson_get_user_attempt_grade>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_lesson_get_user_attempt_grade&lessonid=" + FString::FromInt(_lessonid) + "&lessonattempt=" + FString::FromInt(_lessonattempt) + "&userid=" + FString::FromInt(_userid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_lesson_get_user_attempt_grade::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_lesson_get_user_attempt_grade::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_lesson_get_user_attempt_grade::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_lesson_get_user_grade* Umod_lesson_get_user_grade::mod_lesson_get_user_grade(
			const FString ServerURL,
			const FString Token,
			const int32 _lessonid,
			const int32 _userid)
{
	Umod_lesson_get_user_grade* Node = NewObject<Umod_lesson_get_user_grade>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_lesson_get_user_grade&lessonid=" + FString::FromInt(_lessonid) + "&userid=" + FString::FromInt(_userid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_lesson_get_user_grade::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_lesson_get_user_grade::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_lesson_get_user_grade::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_lesson_get_user_timers* Umod_lesson_get_user_timers::mod_lesson_get_user_timers(
			const FString ServerURL,
			const FString Token,
			const int32 _lessonid,
			const int32 _userid)
{
	Umod_lesson_get_user_timers* Node = NewObject<Umod_lesson_get_user_timers>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_lesson_get_user_timers&lessonid=" + FString::FromInt(_lessonid) + "&userid=" + FString::FromInt(_userid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_lesson_get_user_timers::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_lesson_get_user_timers::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_lesson_get_user_timers::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_lesson_launch_attempt* Umod_lesson_launch_attempt::mod_lesson_launch_attempt(
			const FString ServerURL,
			const FString Token,
			const int32 _lessonid,
			const FString _password,
			const int32 _pageid,
			const int32 _review)
{
	Umod_lesson_launch_attempt* Node = NewObject<Umod_lesson_launch_attempt>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_lesson_launch_attempt&lessonid=" + FString::FromInt(_lessonid) + "&password=" + _password + "&pageid=" + FString::FromInt(_pageid) + "&review=" + FString::FromInt(_review);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_lesson_launch_attempt::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_lesson_launch_attempt::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_lesson_launch_attempt::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_lesson_process_page* Umod_lesson_process_page::mod_lesson_process_page(
			const FString ServerURL,
			const FString Token,
			const int32 _lessonid,
			const int32 _pageid,
			const FString _dataname,
			const FString _datavalue,
			const FString _password,
			const int32 _review)
{
	Umod_lesson_process_page* Node = NewObject<Umod_lesson_process_page>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_lesson_process_page&lessonid=" + FString::FromInt(_lessonid) + "&pageid=" + FString::FromInt(_pageid) + "&data[0][name]=" + _dataname + "&data[0][value]=" + _datavalue + "&password=" + _password + "&review=" + FString::FromInt(_review);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_lesson_process_page::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_lesson_process_page::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_lesson_process_page::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_lesson_view_lesson* Umod_lesson_view_lesson::mod_lesson_view_lesson(
			const FString ServerURL,
			const FString Token,
			const int32 _lessonid,
			const FString _password)
{
	Umod_lesson_view_lesson* Node = NewObject<Umod_lesson_view_lesson>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_lesson_view_lesson&lessonid=" + FString::FromInt(_lessonid) + "&password=" + _password;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_lesson_view_lesson::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_lesson_view_lesson::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_lesson_view_lesson::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_lti_create_tool_proxy* Umod_lti_create_tool_proxy::mod_lti_create_tool_proxy(
			const FString ServerURL,
			const FString Token,
			const FString _regurl,
			const FString _name,
			const FString _capabilityoffered,
			const FString _serviceoffered)
{
	Umod_lti_create_tool_proxy* Node = NewObject<Umod_lti_create_tool_proxy>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_lti_create_tool_proxy&name=" + _name + "&regurl=" + _regurl + "&capabilityoffered[0]=" + _capabilityoffered + "&serviceoffered[0]=" + _serviceoffered;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_lti_create_tool_proxy::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_lti_create_tool_proxy::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_lti_create_tool_proxy::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_lti_create_tool_type* Umod_lti_create_tool_type::mod_lti_create_tool_type(
			const FString ServerURL,
			const FString Token,
			const FString _cartridgeurl,
			const FString _key,
			const FString _secret)
{
	Umod_lti_create_tool_type* Node = NewObject<Umod_lti_create_tool_type>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_lti_create_tool_type&cartridgeurl=" + _cartridgeurl + "&key=" + _key + "&secret=" + _secret;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_lti_create_tool_type::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_lti_create_tool_type::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_lti_create_tool_type::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_lti_delete_tool_proxy* Umod_lti_delete_tool_proxy::mod_lti_delete_tool_proxy(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Umod_lti_delete_tool_proxy* Node = NewObject<Umod_lti_delete_tool_proxy>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_lti_delete_tool_proxy&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_lti_delete_tool_proxy::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_lti_delete_tool_proxy::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_lti_delete_tool_proxy::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_lti_delete_tool_type* Umod_lti_delete_tool_type::mod_lti_delete_tool_type(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Umod_lti_delete_tool_type* Node = NewObject<Umod_lti_delete_tool_type>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_lti_delete_tool_type&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_lti_delete_tool_type::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_lti_delete_tool_type::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_lti_delete_tool_type::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_lti_get_ltis_by_courses* Umod_lti_get_ltis_by_courses::mod_lti_get_ltis_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids)
{
	Umod_lti_get_ltis_by_courses* Node = NewObject<Umod_lti_get_ltis_by_courses>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_lti_get_ltis_by_courses&courseids[0]=" + FString::FromInt(_courseids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_lti_get_ltis_by_courses::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_lti_get_ltis_by_courses::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_lti_get_ltis_by_courses::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_lti_get_tool_launch_data* Umod_lti_get_tool_launch_data::mod_lti_get_tool_launch_data(
			const FString ServerURL,
			const FString Token,
			const int32 _toolid)
{
	Umod_lti_get_tool_launch_data* Node = NewObject<Umod_lti_get_tool_launch_data>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_lti_get_tool_launch_data&toolid=" + FString::FromInt(_toolid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_lti_get_tool_launch_data::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_lti_get_tool_launch_data::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_lti_get_tool_launch_data::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_lti_get_tool_proxies* Umod_lti_get_tool_proxies::mod_lti_get_tool_proxies(
			const FString ServerURL,
			const FString Token,
			const int32 _orphanedonly)
{
	Umod_lti_get_tool_proxies* Node = NewObject<Umod_lti_get_tool_proxies>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_lti_get_tool_proxies&orphanedonly=" + FString::FromInt(_orphanedonly);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_lti_get_tool_proxies::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_lti_get_tool_proxies::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_lti_get_tool_proxies::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_lti_get_tool_proxy_registration_request* Umod_lti_get_tool_proxy_registration_request::mod_lti_get_tool_proxy_registration_request(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Umod_lti_get_tool_proxy_registration_request* Node = NewObject<Umod_lti_get_tool_proxy_registration_request>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_lti_get_tool_proxy_registration_request&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_lti_get_tool_proxy_registration_request::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_lti_get_tool_proxy_registration_request::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_lti_get_tool_proxy_registration_request::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_lti_get_tool_types* Umod_lti_get_tool_types::mod_lti_get_tool_types(
			const FString ServerURL,
			const FString Token,
			const int32 _toolproxyid)
{
	Umod_lti_get_tool_types* Node = NewObject<Umod_lti_get_tool_types>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_lti_get_tool_types&toolproxyid=" + FString::FromInt(_toolproxyid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_lti_get_tool_types::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_lti_get_tool_types::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_lti_get_tool_types::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_lti_get_tool_types_and_proxies* Umod_lti_get_tool_types_and_proxies::mod_lti_get_tool_types_and_proxies(
			const FString ServerURL,
			const FString Token,
			const int32 _toolproxyid,
			const int32 _orphanedonly,
			const int32 _limit,
			const int32 _offset)
{
	Umod_lti_get_tool_types_and_proxies* Node = NewObject<Umod_lti_get_tool_types_and_proxies>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_lti_get_tool_types_and_proxies&toolproxyid=" + FString::FromInt(_toolproxyid) + "&orphanedonly=" + FString::FromInt(_orphanedonly) + "&limit=" + FString::FromInt(_limit) + "&offset=" + FString::FromInt(_offset);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_lti_get_tool_types_and_proxies::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_lti_get_tool_types_and_proxies::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_lti_get_tool_types_and_proxies::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_lti_get_tool_types_and_proxies_count* Umod_lti_get_tool_types_and_proxies_count::mod_lti_get_tool_types_and_proxies_count(
			const FString ServerURL,
			const FString Token,
			const int32 _toolproxyid,
			const int32 _orphanedonly)
{
	Umod_lti_get_tool_types_and_proxies_count* Node = NewObject<Umod_lti_get_tool_types_and_proxies_count>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_lti_get_tool_types_and_proxies_count&toolproxyid=" + FString::FromInt(_toolproxyid) + "&orphanedonly=" + FString::FromInt(_orphanedonly);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_lti_get_tool_types_and_proxies_count::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_lti_get_tool_types_and_proxies_count::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_lti_get_tool_types_and_proxies_count::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_lti_is_cartridge* Umod_lti_is_cartridge::mod_lti_is_cartridge(
			const FString ServerURL,
			const FString Token,
			const FString _url)
{
	Umod_lti_is_cartridge* Node = NewObject<Umod_lti_is_cartridge>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_lti_is_cartridge&url=" + _url;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_lti_is_cartridge::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_lti_is_cartridge::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_lti_is_cartridge::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_lti_update_tool_type* Umod_lti_update_tool_type::mod_lti_update_tool_type(
			const FString ServerURL,
			const FString Token,
			const int32 _id,
			const FString _name,
			const FString _description,
			const int32 _state)
{
	Umod_lti_update_tool_type* Node = NewObject<Umod_lti_update_tool_type>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_lti_update_tool_type&id=" + FString::FromInt(_id) + "&name=" + _name + "&description=" + _description + "&state=" + FString::FromInt(_state);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_lti_update_tool_type::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_lti_update_tool_type::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_lti_update_tool_type::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_lti_view_lti* Umod_lti_view_lti::mod_lti_view_lti(
			const FString ServerURL,
			const FString Token,
			const int32 _ltiid)
{
	Umod_lti_view_lti* Node = NewObject<Umod_lti_view_lti>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_lti_view_lti&ltiid=" + FString::FromInt(_ltiid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_lti_view_lti::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_lti_view_lti::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_lti_view_lti::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_page_get_pages_by_courses* Umod_page_get_pages_by_courses::mod_page_get_pages_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids)
{
	Umod_page_get_pages_by_courses* Node = NewObject<Umod_page_get_pages_by_courses>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_page_get_pages_by_courses&courseids[0]=" + FString::FromInt(_courseids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_page_get_pages_by_courses::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_page_get_pages_by_courses::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_page_get_pages_by_courses::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_page_view_page* Umod_page_view_page::mod_page_view_page(
			const FString ServerURL,
			const FString Token,
			const int32 _pageid)
{
	Umod_page_view_page* Node = NewObject<Umod_page_view_page>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_page_view_page&pageid=" + FString::FromInt(_pageid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_page_view_page::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_page_view_page::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_page_view_page::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_quiz_get_attempt_access_information* Umod_quiz_get_attempt_access_information::mod_quiz_get_attempt_access_information(
			const FString ServerURL,
			const FString Token,
			const int32 _quizid,
			const int32 _attemptid)
{
	Umod_quiz_get_attempt_access_information* Node = NewObject<Umod_quiz_get_attempt_access_information>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_quiz_get_attempt_access_information&quizid=" + FString::FromInt(_quizid) + "&attemptid=" + FString::FromInt(_attemptid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_quiz_get_attempt_access_information::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_quiz_get_attempt_access_information::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_quiz_get_attempt_access_information::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_quiz_get_attempt_data* Umod_quiz_get_attempt_data::mod_quiz_get_attempt_data(
			const FString ServerURL,
			const FString Token,
			const int32 _attemptid,
			const int32 _page,
			const FString _preflightdataname,
			const FString _preflightdatavalue)
{
	Umod_quiz_get_attempt_data* Node = NewObject<Umod_quiz_get_attempt_data>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_quiz_get_attempt_data&attemptid=" + FString::FromInt(_attemptid) + "&page=" + FString::FromInt(_page) + "&preflightdata[0][name]=" + _preflightdataname + "&preflightdata[0][value]=" + _preflightdatavalue;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_quiz_get_attempt_data::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_quiz_get_attempt_data::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_quiz_get_attempt_data::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_quiz_get_attempt_review* Umod_quiz_get_attempt_review::mod_quiz_get_attempt_review(
			const FString ServerURL,
			const FString Token,
			const int32 _attemptid,
			const int32 _page)
{
	Umod_quiz_get_attempt_review* Node = NewObject<Umod_quiz_get_attempt_review>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_quiz_get_attempt_review&attemptid=" + FString::FromInt(_attemptid) + "&page=" + FString::FromInt(_page);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_quiz_get_attempt_review::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_quiz_get_attempt_review::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_quiz_get_attempt_review::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_quiz_get_attempt_summary* Umod_quiz_get_attempt_summary::mod_quiz_get_attempt_summary(
			const FString ServerURL,
			const FString Token,
			const int32 _attemptid,
			const FString _preflightdataname,
			const FString _preflightdatavalue)
{
	Umod_quiz_get_attempt_summary* Node = NewObject<Umod_quiz_get_attempt_summary>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_quiz_get_attempt_summary&attemptid=" + FString::FromInt(_attemptid) + "&preflightdata[0][name]=" + _preflightdataname + "&preflightdata[0][value]=" + _preflightdatavalue;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_quiz_get_attempt_summary::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_quiz_get_attempt_summary::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_quiz_get_attempt_summary::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_quiz_get_combined_review_options* Umod_quiz_get_combined_review_options::mod_quiz_get_combined_review_options(
			const FString ServerURL,
			const FString Token,
			const int32 _quizid,
			const int32 _userid)
{
	Umod_quiz_get_combined_review_options* Node = NewObject<Umod_quiz_get_combined_review_options>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_quiz_get_combined_review_options&quizid=" + FString::FromInt(_quizid) + "&userid=" + FString::FromInt(_userid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_quiz_get_combined_review_options::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_quiz_get_combined_review_options::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_quiz_get_combined_review_options::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_quiz_get_quiz_access_information* Umod_quiz_get_quiz_access_information::mod_quiz_get_quiz_access_information(
			const FString ServerURL,
			const FString Token,
			const int32 _quizid)
{
	Umod_quiz_get_quiz_access_information* Node = NewObject<Umod_quiz_get_quiz_access_information>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_quiz_get_quiz_access_information&quizid=" + FString::FromInt(_quizid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_quiz_get_quiz_access_information::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_quiz_get_quiz_access_information::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_quiz_get_quiz_access_information::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_quiz_get_quiz_feedback_for_grade* Umod_quiz_get_quiz_feedback_for_grade::mod_quiz_get_quiz_feedback_for_grade(
			const FString ServerURL,
			const FString Token,
			const int32 _quizid,
			const float _grade)
{
	Umod_quiz_get_quiz_feedback_for_grade* Node = NewObject<Umod_quiz_get_quiz_feedback_for_grade>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_quiz_get_quiz_feedback_for_grade&quizid=" + FString::FromInt(_quizid) + "&grade=" + FString::SanitizeFloat(_grade);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_quiz_get_quiz_feedback_for_grade::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_quiz_get_quiz_feedback_for_grade::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_quiz_get_quiz_feedback_for_grade::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_quiz_get_quiz_required_qtypes* Umod_quiz_get_quiz_required_qtypes::mod_quiz_get_quiz_required_qtypes(
			const FString ServerURL,
			const FString Token,
			const int32 _quizid)
{
	Umod_quiz_get_quiz_required_qtypes* Node = NewObject<Umod_quiz_get_quiz_required_qtypes>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_quiz_get_quiz_required_qtypes&quizid=" + FString::FromInt(_quizid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_quiz_get_quiz_required_qtypes::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_quiz_get_quiz_required_qtypes::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_quiz_get_quiz_required_qtypes::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_quiz_get_quizzes_by_courses* Umod_quiz_get_quizzes_by_courses::mod_quiz_get_quizzes_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids)
{
	Umod_quiz_get_quizzes_by_courses* Node = NewObject<Umod_quiz_get_quizzes_by_courses>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_quiz_get_quizzes_by_courses&courseids[0]=" + FString::FromInt(_courseids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_quiz_get_quizzes_by_courses::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_quiz_get_quizzes_by_courses::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_quiz_get_quizzes_by_courses::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_quiz_get_user_attempts* Umod_quiz_get_user_attempts::mod_quiz_get_user_attempts(
			const FString ServerURL,
			const FString Token,
			const int32 _quizid,
			const int32 _userid,
			const FString _status,
			const int32 _includepreviews)
{
	Umod_quiz_get_user_attempts* Node = NewObject<Umod_quiz_get_user_attempts>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_quiz_get_user_attempts&quizid=" + FString::FromInt(_quizid) + "&userid=" + FString::FromInt(_userid) + "&status=" + _status + "&includepreviews=" + FString::FromInt(_includepreviews);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_quiz_get_user_attempts::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_quiz_get_user_attempts::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_quiz_get_user_attempts::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_quiz_get_user_best_grade* Umod_quiz_get_user_best_grade::mod_quiz_get_user_best_grade(
			const FString ServerURL,
			const FString Token,
			const int32 _quizid,
			const int32 _userid)
{
	Umod_quiz_get_user_best_grade* Node = NewObject<Umod_quiz_get_user_best_grade>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_quiz_get_user_best_grade&quizid=" + FString::FromInt(_quizid) + "&userid=" + FString::FromInt(_userid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_quiz_get_user_best_grade::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_quiz_get_user_best_grade::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_quiz_get_user_best_grade::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_quiz_process_attempt* Umod_quiz_process_attempt::mod_quiz_process_attempt(
			const FString ServerURL,
			const FString Token,
			const int32 _attemptid,
			const FString _dataname,
			const FString _datavalue,
			const FString _preflightdataname,
			const FString _preflightdatavalue,
			const int32 _finishattempt,
			const int32 _timeup)
{
	Umod_quiz_process_attempt* Node = NewObject<Umod_quiz_process_attempt>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_quiz_process_attempt&attemptid=" + FString::FromInt(_attemptid) + "&data[0][name]=" + _dataname + "&data[0][value]=" + _datavalue + "&finishattempt=" + FString::FromInt(_finishattempt) + "&timeup=" + FString::FromInt(_timeup) + "&preflightdata[0][name]=" + _preflightdataname + "&preflightdata[0][value]=" + _preflightdatavalue;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_quiz_process_attempt::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_quiz_process_attempt::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_quiz_process_attempt::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_quiz_save_attempt* Umod_quiz_save_attempt::mod_quiz_save_attempt(
			const FString ServerURL,
			const FString Token,
			const int32 _attemptid,
			const FString _dataname,
			const FString _datavalue,
			const FString _preflightdataname,
			const FString _preflightdatavalue)
{
	Umod_quiz_save_attempt* Node = NewObject<Umod_quiz_save_attempt>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_quiz_save_attempt&attemptid=" + FString::FromInt(_attemptid) + "&data[0][name]=" + _dataname + "&data[0][value]=" + _datavalue + "&preflightdata[0][name]=" + _preflightdataname + "&preflightdata[0][value]=" + _preflightdatavalue;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_quiz_save_attempt::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_quiz_save_attempt::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_quiz_save_attempt::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_quiz_set_question_version* Umod_quiz_set_question_version::mod_quiz_set_question_version(
			const FString ServerURL,
			const FString Token,
			const int32 _slotid,
			const int32 _newversion)
{
	Umod_quiz_set_question_version* Node = NewObject<Umod_quiz_set_question_version>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_quiz_set_question_version&slotid=" + FString::FromInt(_slotid) + "&newversion=" + FString::FromInt(_newversion);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_quiz_set_question_version::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_quiz_set_question_version::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_quiz_set_question_version::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_quiz_start_attempt* Umod_quiz_start_attempt::mod_quiz_start_attempt(
			const FString ServerURL,
			const FString Token,
			const int32 _quizid,
			const FString _preflightdataname,
			const FString _preflightdatavalue,
			const int32 _forcenew)
{
	Umod_quiz_start_attempt* Node = NewObject<Umod_quiz_start_attempt>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_quiz_start_attempt&quizid=" + FString::FromInt(_quizid) + "&preflightdata[0][name]=" + _preflightdataname + "&preflightdata[0][value]=" + _preflightdatavalue + "&forcenew=" + FString::FromInt(_forcenew);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_quiz_start_attempt::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_quiz_start_attempt::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_quiz_start_attempt::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_quiz_view_attempt* Umod_quiz_view_attempt::mod_quiz_view_attempt(
			const FString ServerURL,
			const FString Token,
			const int32 _attemptid,
			const int32 _page,
			const FString _preflightdataname,
			const FString _preflightdatavalue)
{
	Umod_quiz_view_attempt* Node = NewObject<Umod_quiz_view_attempt>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_quiz_view_attempt&attemptid=" + FString::FromInt(_attemptid) + "&page=" + FString::FromInt(_page) + "&preflightdata[0][name]=" + _preflightdataname + "&preflightdata[0][value]=" + _preflightdatavalue;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_quiz_view_attempt::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_quiz_view_attempt::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_quiz_view_attempt::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_quiz_view_attempt_review* Umod_quiz_view_attempt_review::mod_quiz_view_attempt_review(
			const FString ServerURL,
			const FString Token,
			const int32 _attemptid)
{
	Umod_quiz_view_attempt_review* Node = NewObject<Umod_quiz_view_attempt_review>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_quiz_view_attempt_review&attemptid=" + FString::FromInt(_attemptid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_quiz_view_attempt_review::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_quiz_view_attempt_review::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_quiz_view_attempt_review::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_quiz_view_attempt_summary* Umod_quiz_view_attempt_summary::mod_quiz_view_attempt_summary(
			const FString ServerURL,
			const FString Token,
			const int32 _attemptid,
			const FString _preflightdataname,
			const FString _preflightdatavalue)
{
	Umod_quiz_view_attempt_summary* Node = NewObject<Umod_quiz_view_attempt_summary>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_quiz_view_attempt_summary&attemptid=" + FString::FromInt(_attemptid) + "&preflightdata[0][name]=" + _preflightdataname + "&preflightdata[0][value]=" + _preflightdatavalue;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_quiz_view_attempt_summary::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_quiz_view_attempt_summary::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_quiz_view_attempt_summary::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_quiz_view_quiz* Umod_quiz_view_quiz::mod_quiz_view_quiz(
			const FString ServerURL,
			const FString Token,
			const int32 _quizid)
{
	Umod_quiz_view_quiz* Node = NewObject<Umod_quiz_view_quiz>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_quiz_view_quiz&quizid=" + FString::FromInt(_quizid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_quiz_view_quiz::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_quiz_view_quiz::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_quiz_view_quiz::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_resource_get_resources_by_courses* Umod_resource_get_resources_by_courses::mod_resource_get_resources_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids)
{
	Umod_resource_get_resources_by_courses* Node = NewObject<Umod_resource_get_resources_by_courses>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_resource_get_resources_by_courses&courseids[0]=" + FString::FromInt(_courseids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_resource_get_resources_by_courses::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_resource_get_resources_by_courses::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_resource_get_resources_by_courses::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_resource_view_resource* Umod_resource_view_resource::mod_resource_view_resource(
			const FString ServerURL,
			const FString Token,
			const int32 _resourceid)
{
	Umod_resource_view_resource* Node = NewObject<Umod_resource_view_resource>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_resource_view_resource&resourceid=" + FString::FromInt(_resourceid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_resource_view_resource::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_resource_view_resource::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_resource_view_resource::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_scorm_get_scorm_access_information* Umod_scorm_get_scorm_access_information::mod_scorm_get_scorm_access_information(
			const FString ServerURL,
			const FString Token,
			const int32 _scormid)
{
	Umod_scorm_get_scorm_access_information* Node = NewObject<Umod_scorm_get_scorm_access_information>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_scorm_get_scorm_access_information&scormid=" + FString::FromInt(_scormid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_scorm_get_scorm_access_information::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_scorm_get_scorm_access_information::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_scorm_get_scorm_access_information::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_scorm_get_scorm_attempt_count* Umod_scorm_get_scorm_attempt_count::mod_scorm_get_scorm_attempt_count(
			const FString ServerURL,
			const FString Token,
			const int32 _scormid,
			const int32 _userid,
			const int32 _ignoremissingcompletion)
{
	Umod_scorm_get_scorm_attempt_count* Node = NewObject<Umod_scorm_get_scorm_attempt_count>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_scorm_get_scorm_attempt_count&scormid=" + FString::FromInt(_scormid) + "&userid=" + FString::FromInt(_userid) + "&ignoremissingcompletion=" + FString::FromInt(_ignoremissingcompletion);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_scorm_get_scorm_attempt_count::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_scorm_get_scorm_attempt_count::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_scorm_get_scorm_attempt_count::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_scorm_get_scorm_sco_tracks* Umod_scorm_get_scorm_sco_tracks::mod_scorm_get_scorm_sco_tracks(
			const FString ServerURL,
			const FString Token,
			const int32 _scoid,
			const int32 _userid,
			const int32 _attempt)
{
	Umod_scorm_get_scorm_sco_tracks* Node = NewObject<Umod_scorm_get_scorm_sco_tracks>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_scorm_get_scorm_sco_tracks&scoid=" + FString::FromInt(_scoid) + "&userid=" + FString::FromInt(_userid) + "&attempt=" + FString::FromInt(_attempt);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_scorm_get_scorm_sco_tracks::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_scorm_get_scorm_sco_tracks::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_scorm_get_scorm_sco_tracks::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_scorm_get_scorm_scoes* Umod_scorm_get_scorm_scoes::mod_scorm_get_scorm_scoes(
			const FString ServerURL,
			const FString Token,
			const int32 _scormid,
			const FString _organization)
{
	Umod_scorm_get_scorm_scoes* Node = NewObject<Umod_scorm_get_scorm_scoes>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_scorm_get_scorm_scoes&scormid=" + FString::FromInt(_scormid) + "&organization=" + _organization;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_scorm_get_scorm_scoes::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_scorm_get_scorm_scoes::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_scorm_get_scorm_scoes::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_scorm_get_scorm_user_data* Umod_scorm_get_scorm_user_data::mod_scorm_get_scorm_user_data(
			const FString ServerURL,
			const FString Token,
			const int32 _scormid,
			const int32 _attempt)
{
	Umod_scorm_get_scorm_user_data* Node = NewObject<Umod_scorm_get_scorm_user_data>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_scorm_get_scorm_user_data&scormid=" + FString::FromInt(_scormid) + "&attempt=" + FString::FromInt(_attempt);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_scorm_get_scorm_user_data::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_scorm_get_scorm_user_data::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_scorm_get_scorm_user_data::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_scorm_get_scorms_by_courses* Umod_scorm_get_scorms_by_courses::mod_scorm_get_scorms_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids)
{
	Umod_scorm_get_scorms_by_courses* Node = NewObject<Umod_scorm_get_scorms_by_courses>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_scorm_get_scorms_by_courses&courseids[0]=" + FString::FromInt(_courseids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_scorm_get_scorms_by_courses::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_scorm_get_scorms_by_courses::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_scorm_get_scorms_by_courses::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_scorm_insert_scorm_tracks* Umod_scorm_insert_scorm_tracks::mod_scorm_insert_scorm_tracks(
			const FString ServerURL,
			const FString Token,
			const int32 _scoid,
			const int32 _attempt,
			const FString _trackselement,
			const FString _tracksvalue)
{
	Umod_scorm_insert_scorm_tracks* Node = NewObject<Umod_scorm_insert_scorm_tracks>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_scorm_insert_scorm_tracks&scoid=" + FString::FromInt(_scoid) + "&attempt=" + FString::FromInt(_attempt) + "&tracks[0][element]=" + _trackselement + "&tracks[0][value]=" + _tracksvalue;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_scorm_insert_scorm_tracks::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_scorm_insert_scorm_tracks::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_scorm_insert_scorm_tracks::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_scorm_launch_sco* Umod_scorm_launch_sco::mod_scorm_launch_sco(
			const FString ServerURL,
			const FString Token,
			const int32 _scormid,
			const int32 _scoid)
{
	Umod_scorm_launch_sco* Node = NewObject<Umod_scorm_launch_sco>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_scorm_launch_sco&scormid=" + FString::FromInt(_scormid) + "&scoid=" + FString::FromInt(_scoid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_scorm_launch_sco::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_scorm_launch_sco::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_scorm_launch_sco::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_scorm_view_scorm* Umod_scorm_view_scorm::mod_scorm_view_scorm(
			const FString ServerURL,
			const FString Token,
			const int32 _scormid)
{
	Umod_scorm_view_scorm* Node = NewObject<Umod_scorm_view_scorm>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_scorm_view_scorm&scormid=" + FString::FromInt(_scormid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_scorm_view_scorm::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_scorm_view_scorm::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_scorm_view_scorm::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_survey_get_questions* Umod_survey_get_questions::mod_survey_get_questions(
			const FString ServerURL,
			const FString Token,
			const int32 _surveyid)
{
	Umod_survey_get_questions* Node = NewObject<Umod_survey_get_questions>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_survey_get_questions&surveyid=" + FString::FromInt(_surveyid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_survey_get_questions::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_survey_get_questions::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_survey_get_questions::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_survey_get_surveys_by_courses* Umod_survey_get_surveys_by_courses::mod_survey_get_surveys_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids)
{
	Umod_survey_get_surveys_by_courses* Node = NewObject<Umod_survey_get_surveys_by_courses>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_survey_get_surveys_by_courses&courseids[0]=" + FString::FromInt(_courseids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_survey_get_surveys_by_courses::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_survey_get_surveys_by_courses::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_survey_get_surveys_by_courses::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_survey_submit_answers* Umod_survey_submit_answers::mod_survey_submit_answers(
			const FString ServerURL,
			const FString Token,
			const int32 _surveyid,
			const FString _answerskey,
			const FString _answersvalue)
{
	Umod_survey_submit_answers* Node = NewObject<Umod_survey_submit_answers>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_survey_submit_answers&surveyid=" + FString::FromInt(_surveyid) + "&answers[0][key]=" + _answerskey + "&answers[0][value]=" + _answersvalue;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_survey_submit_answers::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_survey_submit_answers::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_survey_submit_answers::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_survey_view_survey* Umod_survey_view_survey::mod_survey_view_survey(
			const FString ServerURL,
			const FString Token,
			const int32 _surveyid)
{
	Umod_survey_view_survey* Node = NewObject<Umod_survey_view_survey>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_survey_view_survey&surveyid=" + FString::FromInt(_surveyid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_survey_view_survey::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_survey_view_survey::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_survey_view_survey::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_url_get_urls_by_courses* Umod_url_get_urls_by_courses::mod_url_get_urls_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids)
{
	Umod_url_get_urls_by_courses* Node = NewObject<Umod_url_get_urls_by_courses>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_url_get_urls_by_courses&courseids[0]=" + FString::FromInt(_courseids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_url_get_urls_by_courses::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_url_get_urls_by_courses::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_url_get_urls_by_courses::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_url_view_url* Umod_url_view_url::mod_url_view_url(
			const FString ServerURL,
			const FString Token,
			const int32 _urlid)
{
	Umod_url_view_url* Node = NewObject<Umod_url_view_url>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_url_view_url&urlid=" + FString::FromInt(_urlid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_url_view_url::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_url_view_url::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_url_view_url::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_wiki_edit_page* Umod_wiki_edit_page::mod_wiki_edit_page(
			const FString ServerURL,
			const FString Token,
			const int32 _pageid,
			const FString _content,
			const FString _section)
{
	Umod_wiki_edit_page* Node = NewObject<Umod_wiki_edit_page>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_wiki_edit_page&pageid=" + FString::FromInt(_pageid) + "&content=" + _content + "&section=" + _section;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_wiki_edit_page::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_wiki_edit_page::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_wiki_edit_page::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_wiki_get_page_contents* Umod_wiki_get_page_contents::mod_wiki_get_page_contents(
			const FString ServerURL,
			const FString Token,
			const int32 _pageid)
{
	Umod_wiki_get_page_contents* Node = NewObject<Umod_wiki_get_page_contents>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_wiki_get_page_contents&pageid=" + FString::FromInt(_pageid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_wiki_get_page_contents::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_wiki_get_page_contents::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_wiki_get_page_contents::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_wiki_get_page_for_editing* Umod_wiki_get_page_for_editing::mod_wiki_get_page_for_editing(
			const FString ServerURL,
			const FString Token,
			const int32 _pageid,
			const FString _section,
			const int32 _lockonly)
{
	Umod_wiki_get_page_for_editing* Node = NewObject<Umod_wiki_get_page_for_editing>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_wiki_get_page_for_editing&pageid=" + FString::FromInt(_pageid) + "&section=" + _section + "&lockonly=" + FString::FromInt(_lockonly);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_wiki_get_page_for_editing::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_wiki_get_page_for_editing::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_wiki_get_page_for_editing::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_wiki_get_subwiki_files* Umod_wiki_get_subwiki_files::mod_wiki_get_subwiki_files(
			const FString ServerURL,
			const FString Token,
			const int32 _wikiid,
			const int32 _groupid,
			const int32 _userid)
{
	Umod_wiki_get_subwiki_files* Node = NewObject<Umod_wiki_get_subwiki_files>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_wiki_get_subwiki_files&wikiid=" + FString::FromInt(_wikiid) + "&groupid=" + FString::FromInt(_groupid) + "&userid=" + FString::FromInt(_userid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_wiki_get_subwiki_files::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_wiki_get_subwiki_files::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_wiki_get_subwiki_files::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_wiki_get_subwiki_pages* Umod_wiki_get_subwiki_pages::mod_wiki_get_subwiki_pages(
			const FString ServerURL,
			const FString Token,
			const int32 _wikiid,
			const int32 _groupid,
			const int32 _userid,
			const FString _optionssortby,
			const FString _optionssortdirection,
			const int32 _optionsincludecontent)
{
	Umod_wiki_get_subwiki_pages* Node = NewObject<Umod_wiki_get_subwiki_pages>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_wiki_get_subwiki_pages&wikiid=" + FString::FromInt(_wikiid) + "&groupid=" + FString::FromInt(_groupid) + "&userid=" + FString::FromInt(_userid) + "&options[sortby]=" + _optionssortby + "&options[sortdirection]=" + _optionssortdirection + "&options[includecontent]=" + FString::FromInt(_optionsincludecontent);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_wiki_get_subwiki_pages::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_wiki_get_subwiki_pages::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_wiki_get_subwiki_pages::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_wiki_get_subwikis* Umod_wiki_get_subwikis::mod_wiki_get_subwikis(
			const FString ServerURL,
			const FString Token,
			const int32 _wikiid)
{
	Umod_wiki_get_subwikis* Node = NewObject<Umod_wiki_get_subwikis>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_wiki_get_subwikis&wikiid=" + FString::FromInt(_wikiid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_wiki_get_subwikis::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_wiki_get_subwikis::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_wiki_get_subwikis::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_wiki_get_wikis_by_courses* Umod_wiki_get_wikis_by_courses::mod_wiki_get_wikis_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids)
{
	Umod_wiki_get_wikis_by_courses* Node = NewObject<Umod_wiki_get_wikis_by_courses>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_wiki_get_wikis_by_courses&courseids[0]=" + FString::FromInt(_courseids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_wiki_get_wikis_by_courses::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_wiki_get_wikis_by_courses::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_wiki_get_wikis_by_courses::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_wiki_new_page* Umod_wiki_new_page::mod_wiki_new_page(
			const FString ServerURL,
			const FString Token,
			const FString _title,
			const FString _content,
			const FString _contentformat,
			const int32 _subwikiid,
			const int32 _wikiid,
			const int32 _userid,
			const int32 _groupid)
{
	Umod_wiki_new_page* Node = NewObject<Umod_wiki_new_page>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_wiki_new_page&title=" + _title + "&content=" + _content + "&contentformat=" + _contentformat + "&subwikiid=" + FString::FromInt(_subwikiid) + "&wikiid=" + FString::FromInt(_wikiid) + "&userid=" + FString::FromInt(_userid) + "&groupid=" + FString::FromInt(_groupid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_wiki_new_page::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_wiki_new_page::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_wiki_new_page::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_wiki_view_page* Umod_wiki_view_page::mod_wiki_view_page(
			const FString ServerURL,
			const FString Token,
			const int32 _pageid)
{
	Umod_wiki_view_page* Node = NewObject<Umod_wiki_view_page>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_wiki_view_page&pageid=" + FString::FromInt(_pageid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_wiki_view_page::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_wiki_view_page::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_wiki_view_page::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_wiki_view_wiki* Umod_wiki_view_wiki::mod_wiki_view_wiki(
			const FString ServerURL,
			const FString Token,
			const int32 _wikiid)
{
	Umod_wiki_view_wiki* Node = NewObject<Umod_wiki_view_wiki>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_wiki_view_wiki&wikiid=" + FString::FromInt(_wikiid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_wiki_view_wiki::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_wiki_view_wiki::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_wiki_view_wiki::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_workshop_add_submission* Umod_workshop_add_submission::mod_workshop_add_submission(
			const FString ServerURL,
			const FString Token,
			const int32 _workshopid,
			const FString _title,
			const FString _content,
			const int32 _contentformat,
			const int32 _inlineattachmentsid,
			const int32 _attachmentsid)
{
	Umod_workshop_add_submission* Node = NewObject<Umod_workshop_add_submission>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_workshop_add_submission&workshopid=" + FString::FromInt(_workshopid) + "&title=" + _title + "&content=" + _content + "&contentformat=" + FString::FromInt(_contentformat) + "&inlineattachmentsid=" + FString::FromInt(_inlineattachmentsid) + "&attachmentsid=" + FString::FromInt(_attachmentsid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_workshop_add_submission::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_workshop_add_submission::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_workshop_add_submission::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_workshop_delete_submission* Umod_workshop_delete_submission::mod_workshop_delete_submission(
			const FString ServerURL,
			const FString Token,
			const int32 _submissionid)
{
	Umod_workshop_delete_submission* Node = NewObject<Umod_workshop_delete_submission>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_workshop_delete_submission&submissionid=" + FString::FromInt(_submissionid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_workshop_delete_submission::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_workshop_delete_submission::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_workshop_delete_submission::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_workshop_evaluate_assessment* Umod_workshop_evaluate_assessment::mod_workshop_evaluate_assessment(
			const FString ServerURL,
			const FString Token,
			const int32 _assessmentid,
			const FString _feedbacktext,
			const int32 _feedbackformat,
			const int32 _weight,
			const FString _gradinggradeover)
{
	Umod_workshop_evaluate_assessment* Node = NewObject<Umod_workshop_evaluate_assessment>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_workshop_evaluate_assessment&assessmentid=" + FString::FromInt(_assessmentid) + "&feedbacktext=" + _feedbacktext + "&feedbackformat=" + FString::FromInt(_feedbackformat) + "&weight=" + FString::FromInt(_weight) + "&gradinggradeover=" + _gradinggradeover;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_workshop_evaluate_assessment::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_workshop_evaluate_assessment::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_workshop_evaluate_assessment::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_workshop_evaluate_submission* Umod_workshop_evaluate_submission::mod_workshop_evaluate_submission(
			const FString ServerURL,
			const FString Token,
			const int32 _submissionid,
			const FString _feedbacktext,
			const int32 _feedbackformat,
			const int32 _published,
			const FString _gradeover)
{
	Umod_workshop_evaluate_submission* Node = NewObject<Umod_workshop_evaluate_submission>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_workshop_evaluate_submission&submissionid=" + FString::FromInt(_submissionid) + "&feedbacktext=" + _feedbacktext + "&feedbackformat=" + FString::FromInt(_feedbackformat) + "&published=" + FString::FromInt(_published) + "&gradeover=" + _gradeover;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_workshop_evaluate_submission::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_workshop_evaluate_submission::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_workshop_evaluate_submission::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_workshop_get_assessment* Umod_workshop_get_assessment::mod_workshop_get_assessment(
			const FString ServerURL,
			const FString Token,
			const int32 _assessmentid)
{
	Umod_workshop_get_assessment* Node = NewObject<Umod_workshop_get_assessment>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_workshop_get_assessment&assessmentid=" + FString::FromInt(_assessmentid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_workshop_get_assessment::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_workshop_get_assessment::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_workshop_get_assessment::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_workshop_get_assessment_form_definition* Umod_workshop_get_assessment_form_definition::mod_workshop_get_assessment_form_definition(
			const FString ServerURL,
			const FString Token,
			const int32 _assessmentid,
			const FString _mode)
{
	Umod_workshop_get_assessment_form_definition* Node = NewObject<Umod_workshop_get_assessment_form_definition>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_workshop_get_assessment_form_definition&assessmentid=" + FString::FromInt(_assessmentid) + "&mode=" + _mode;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_workshop_get_assessment_form_definition::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_workshop_get_assessment_form_definition::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_workshop_get_assessment_form_definition::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_workshop_get_grades* Umod_workshop_get_grades::mod_workshop_get_grades(
			const FString ServerURL,
			const FString Token,
			const int32 _workshopid,
			const int32 _userid)
{
	Umod_workshop_get_grades* Node = NewObject<Umod_workshop_get_grades>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_workshop_get_grades&workshopid=" + FString::FromInt(_workshopid) + "&userid=" + FString::FromInt(_userid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_workshop_get_grades::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_workshop_get_grades::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_workshop_get_grades::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_workshop_get_grades_report* Umod_workshop_get_grades_report::mod_workshop_get_grades_report(
			const FString ServerURL,
			const FString Token,
			const int32 _workshopid,
			const int32 _groupid,
			const FString _sortby,
			const FString _sortdirection,
			const int32 _page,
			const int32 _perpage)
{
	Umod_workshop_get_grades_report* Node = NewObject<Umod_workshop_get_grades_report>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_workshop_get_grades_report&workshopid=" + FString::FromInt(_workshopid) + "&groupid=" + FString::FromInt(_groupid) + "&sortby=" + _sortby + "&sortdirection=" + _sortdirection + "&page=" + FString::FromInt(_page) + "&perpage=" + FString::FromInt(_perpage);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_workshop_get_grades_report::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_workshop_get_grades_report::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_workshop_get_grades_report::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_workshop_get_reviewer_assessments* Umod_workshop_get_reviewer_assessments::mod_workshop_get_reviewer_assessments(
			const FString ServerURL,
			const FString Token,
			const int32 _workshopid,
			const int32 _userid)
{
	Umod_workshop_get_reviewer_assessments* Node = NewObject<Umod_workshop_get_reviewer_assessments>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_workshop_get_reviewer_assessments&workshopid=" + FString::FromInt(_workshopid) + "&userid=" + FString::FromInt(_userid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_workshop_get_reviewer_assessments::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_workshop_get_reviewer_assessments::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_workshop_get_reviewer_assessments::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_workshop_get_submission* Umod_workshop_get_submission::mod_workshop_get_submission(
			const FString ServerURL,
			const FString Token,
			const int32 _submissionid)
{
	Umod_workshop_get_submission* Node = NewObject<Umod_workshop_get_submission>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_workshop_get_submission&submissionid=" + FString::FromInt(_submissionid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_workshop_get_submission::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_workshop_get_submission::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_workshop_get_submission::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_workshop_get_submission_assessments* Umod_workshop_get_submission_assessments::mod_workshop_get_submission_assessments(
			const FString ServerURL,
			const FString Token,
			const int32 _submissionid)
{
	Umod_workshop_get_submission_assessments* Node = NewObject<Umod_workshop_get_submission_assessments>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_workshop_get_submission_assessments&submissionid=" + FString::FromInt(_submissionid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_workshop_get_submission_assessments::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_workshop_get_submission_assessments::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_workshop_get_submission_assessments::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_workshop_get_submissions* Umod_workshop_get_submissions::mod_workshop_get_submissions(
			const FString ServerURL,
			const FString Token,
			const int32 _workshopid,
			const int32 _userid,
			const int32 _groupid,
			const int32 _page,
			const int32 _perpage)
{
	Umod_workshop_get_submissions* Node = NewObject<Umod_workshop_get_submissions>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_workshop_get_submissions&workshopid=" + FString::FromInt(_workshopid) + "&userid=" + FString::FromInt(_userid) + "&groupid=" + FString::FromInt(_groupid) + "&page=" + FString::FromInt(_page) + "&perpage=" + FString::FromInt(_perpage);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_workshop_get_submissions::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_workshop_get_submissions::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_workshop_get_submissions::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_workshop_get_user_plan* Umod_workshop_get_user_plan::mod_workshop_get_user_plan(
			const FString ServerURL,
			const FString Token,
			const int32 _workshopid,
			const int32 _userid)
{
	Umod_workshop_get_user_plan* Node = NewObject<Umod_workshop_get_user_plan>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_workshop_get_user_plan&workshopid=" + FString::FromInt(_workshopid) + "&userid=" + FString::FromInt(_userid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_workshop_get_user_plan::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_workshop_get_user_plan::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_workshop_get_user_plan::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_workshop_get_workshop_access_information* Umod_workshop_get_workshop_access_information::mod_workshop_get_workshop_access_information(
			const FString ServerURL,
			const FString Token,
			const int32 _workshopid)
{
	Umod_workshop_get_workshop_access_information* Node = NewObject<Umod_workshop_get_workshop_access_information>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_workshop_get_workshop_access_information&workshopid=" + FString::FromInt(_workshopid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_workshop_get_workshop_access_information::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_workshop_get_workshop_access_information::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_workshop_get_workshop_access_information::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_workshop_get_workshops_by_courses* Umod_workshop_get_workshops_by_courses::mod_workshop_get_workshops_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids)
{
	Umod_workshop_get_workshops_by_courses* Node = NewObject<Umod_workshop_get_workshops_by_courses>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_workshop_get_workshops_by_courses&courseids[0]=" + FString::FromInt(_courseids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_workshop_get_workshops_by_courses::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_workshop_get_workshops_by_courses::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_workshop_get_workshops_by_courses::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_workshop_update_assessment* Umod_workshop_update_assessment::mod_workshop_update_assessment(
			const FString ServerURL,
			const FString Token,
			const int32 _assessmentid,
			const FString _dataname,
			const FString _datavalue)
{
	Umod_workshop_update_assessment* Node = NewObject<Umod_workshop_update_assessment>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_workshop_update_assessment&assessmentid=" + FString::FromInt(_assessmentid) + "&data[0][name]=" + _dataname + "&data[0][value]=" + _datavalue;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_workshop_update_assessment::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_workshop_update_assessment::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_workshop_update_assessment::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_workshop_update_submission* Umod_workshop_update_submission::mod_workshop_update_submission(
			const FString ServerURL,
			const FString Token,
			const int32 _submissionid,
			const FString _title,
			const FString _content,
			const int32 _contentformat,
			const int32 _inlineattachmentsid,
			const int32 _attachmentsid)
{
	Umod_workshop_update_submission* Node = NewObject<Umod_workshop_update_submission>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_workshop_update_submission&submissionid=" + FString::FromInt(_submissionid) + "&title=" + _title + "&content=" + _content + "&contentformat=" + FString::FromInt(_contentformat) + "&inlineattachmentsid=" + FString::FromInt(_inlineattachmentsid) + "&attachmentsid=" + FString::FromInt(_attachmentsid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_workshop_update_submission::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_workshop_update_submission::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_workshop_update_submission::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_workshop_view_submission* Umod_workshop_view_submission::mod_workshop_view_submission(
			const FString ServerURL,
			const FString Token,
			const int32 _submissionid)
{
	Umod_workshop_view_submission* Node = NewObject<Umod_workshop_view_submission>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_workshop_view_submission&submissionid=" + FString::FromInt(_submissionid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_workshop_view_submission::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_workshop_view_submission::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_workshop_view_submission::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Umod_workshop_view_workshop* Umod_workshop_view_workshop::mod_workshop_view_workshop(
			const FString ServerURL,
			const FString Token,
			const int32 _workshopid)
{
	Umod_workshop_view_workshop* Node = NewObject<Umod_workshop_view_workshop>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=mod_workshop_view_workshop&workshopid=" + FString::FromInt(_workshopid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Umod_workshop_view_workshop::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Umod_workshop_view_workshop::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Umod_workshop_view_workshop::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Upaygw_paypal_create_transaction_complete* Upaygw_paypal_create_transaction_complete::paygw_paypal_create_transaction_complete(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const FString _paymentarea,
			const int32 _itemid,
			const FString _orderid)
{
	Upaygw_paypal_create_transaction_complete* Node = NewObject<Upaygw_paypal_create_transaction_complete>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=paygw_paypal_create_transaction_complete&component=" + _component + "&paymentarea=" + _paymentarea + "&itemid=" + FString::FromInt(_itemid) + "&orderid=" + _orderid;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Upaygw_paypal_create_transaction_complete::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Upaygw_paypal_create_transaction_complete::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Upaygw_paypal_create_transaction_complete::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Upaygw_paypal_get_config_for_js* Upaygw_paypal_get_config_for_js::paygw_paypal_get_config_for_js(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const FString _paymentarea,
			const int32 _itemid)
{
	Upaygw_paypal_get_config_for_js* Node = NewObject<Upaygw_paypal_get_config_for_js>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=paygw_paypal_get_config_for_js&component=" + _component + "&paymentarea=" + _paymentarea + "&itemid=" + FString::FromInt(_itemid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Upaygw_paypal_get_config_for_js::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Upaygw_paypal_get_config_for_js::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Upaygw_paypal_get_config_for_js::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Uqbank_columnsortorder_set_columnbank_order* Uqbank_columnsortorder_set_columnbank_order::qbank_columnsortorder_set_columnbank_order(
			const FString ServerURL,
			const FString Token,
			const FString _columns)
{
	Uqbank_columnsortorder_set_columnbank_order* Node = NewObject<Uqbank_columnsortorder_set_columnbank_order>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=qbank_columnsortorder_set_columnbank_order&columns[0]=" + _columns;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Uqbank_columnsortorder_set_columnbank_order::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Uqbank_columnsortorder_set_columnbank_order::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Uqbank_columnsortorder_set_columnbank_order::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Uqbank_editquestion_set_status* Uqbank_editquestion_set_status::qbank_editquestion_set_status(
			const FString ServerURL,
			const FString Token,
			const int32 _questionid,
			const FString _status)
{
	Uqbank_editquestion_set_status* Node = NewObject<Uqbank_editquestion_set_status>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=qbank_editquestion_set_status&questionid=" + FString::FromInt(_questionid) + "&status=" + _status;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Uqbank_editquestion_set_status::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Uqbank_editquestion_set_status::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Uqbank_editquestion_set_status::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Uqbank_tagquestion_submit_tags_form* Uqbank_tagquestion_submit_tags_form::qbank_tagquestion_submit_tags_form(
			const FString ServerURL,
			const FString Token,
			const int32 _questionid,
			const int32 _contextid,
			const FString _formdata)
{
	Uqbank_tagquestion_submit_tags_form* Node = NewObject<Uqbank_tagquestion_submit_tags_form>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=qbank_tagquestion_submit_tags_form&questionid=" + FString::FromInt(_questionid) + "&contextid=" + FString::FromInt(_contextid) + "&formdata=" + _formdata;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Uqbank_tagquestion_submit_tags_form::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Uqbank_tagquestion_submit_tags_form::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Uqbank_tagquestion_submit_tags_form::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Uquizaccess_seb_validate_quiz_keys* Uquizaccess_seb_validate_quiz_keys::quizaccess_seb_validate_quiz_keys(
			const FString ServerURL,
			const FString Token,
			const int32 _cmid,
			const FString _url,
			const FString _configkey,
			const FString _browserexamkey)
{
	Uquizaccess_seb_validate_quiz_keys* Node = NewObject<Uquizaccess_seb_validate_quiz_keys>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=quizaccess_seb_validate_quiz_keys&cmid=" + FString::FromInt(_cmid) + "&url=" + _url + "&configkey=" + _configkey + "&browserexamkey=" + _browserexamkey;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Uquizaccess_seb_validate_quiz_keys::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Uquizaccess_seb_validate_quiz_keys::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Uquizaccess_seb_validate_quiz_keys::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ureport_competency_data_for_report* Ureport_competency_data_for_report::report_competency_data_for_report(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _userid,
			const int32 _moduleid)
{
	Ureport_competency_data_for_report* Node = NewObject<Ureport_competency_data_for_report>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=report_competency_data_for_report&courseid=" + FString::FromInt(_courseid) + "&userid=" + FString::FromInt(_userid) + "&moduleid=" + FString::FromInt(_moduleid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ureport_competency_data_for_report::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ureport_competency_data_for_report::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ureport_competency_data_for_report::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Ureport_insights_action_executed* Ureport_insights_action_executed::report_insights_action_executed(
			const FString ServerURL,
			const FString Token,
			const FString _actionname,
			const int32 _predictionids)
{
	Ureport_insights_action_executed* Node = NewObject<Ureport_insights_action_executed>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=report_insights_action_executed&actionname=" + _actionname + "&predictionids[0]=" + FString::FromInt(_predictionids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Ureport_insights_action_executed::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Ureport_insights_action_executed::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Ureport_insights_action_executed::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utiny_autosave_reset_session* Utiny_autosave_reset_session::tiny_autosave_reset_session(
			const FString ServerURL,
			const FString Token,
			const int32 _contextid,
			const FString _pagehash,
			const FString _pageinstance,
			const FString _elementid)
{
	Utiny_autosave_reset_session* Node = NewObject<Utiny_autosave_reset_session>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tiny_autosave_reset_session&contextid=" + FString::FromInt(_contextid) + "&pagehash=" + _pagehash + "&pageinstance=" + _pageinstance + "&elementid=" + _elementid;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utiny_autosave_reset_session::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utiny_autosave_reset_session::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utiny_autosave_reset_session::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utiny_autosave_resume_session* Utiny_autosave_resume_session::tiny_autosave_resume_session(
			const FString ServerURL,
			const FString Token,
			const int32 _contextid,
			const FString _pagehash,
			const FString _pageinstance,
			const FString _elementid,
			const int32 _draftid)
{
	Utiny_autosave_resume_session* Node = NewObject<Utiny_autosave_resume_session>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tiny_autosave_resume_session&contextid=" + FString::FromInt(_contextid) + "&pagehash=" + _pagehash + "&pageinstance=" + _pageinstance + "&elementid=" + _elementid + "&draftid=" + FString::FromInt(_draftid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utiny_autosave_resume_session::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utiny_autosave_resume_session::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utiny_autosave_resume_session::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utiny_autosave_update_session* Utiny_autosave_update_session::tiny_autosave_update_session(
			const FString ServerURL,
			const FString Token,
			const int32 _contextid,
			const FString _pagehash,
			const FString _pageinstance,
			const FString _elementid,
			const FString _drafttext)
{
	Utiny_autosave_update_session* Node = NewObject<Utiny_autosave_update_session>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tiny_autosave_update_session&contextid=" + FString::FromInt(_contextid) + "&pagehash=" + _pagehash + "&pageinstance=" + _pageinstance + "&elementid=" + _elementid + "&drafttext=" + _drafttext;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utiny_autosave_update_session::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utiny_autosave_update_session::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utiny_autosave_update_session::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utiny_equation_filter* Utiny_equation_filter::tiny_equation_filter(
			const FString ServerURL,
			const FString Token,
			const int32 _contextid,
			const FString _content)
{
	Utiny_equation_filter* Node = NewObject<Utiny_equation_filter>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tiny_equation_filter&contextid=" + FString::FromInt(_contextid) + "&content=" + _content;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utiny_equation_filter::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utiny_equation_filter::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utiny_equation_filter::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_analytics_potential_contexts* Utool_analytics_potential_contexts::tool_analytics_potential_contexts(
			const FString ServerURL,
			const FString Token,
			const FString _query,
			const int32 _modelid)
{
	Utool_analytics_potential_contexts* Node = NewObject<Utool_analytics_potential_contexts>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_analytics_potential_contexts&query=" + _query + "&modelid=" + FString::FromInt(_modelid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_analytics_potential_contexts::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_analytics_potential_contexts::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_analytics_potential_contexts::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_behat_get_entity_generator* Utool_behat_get_entity_generator::tool_behat_get_entity_generator(
			const FString ServerURL,
			const FString Token,
			const FString _entitytype)
{
	Utool_behat_get_entity_generator* Node = NewObject<Utool_behat_get_entity_generator>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_behat_get_entity_generator&entitytype=" + _entitytype;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_behat_get_entity_generator::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_behat_get_entity_generator::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_behat_get_entity_generator::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_dataprivacy_approve_data_request* Utool_dataprivacy_approve_data_request::tool_dataprivacy_approve_data_request(
			const FString ServerURL,
			const FString Token,
			const int32 _requestid)
{
	Utool_dataprivacy_approve_data_request* Node = NewObject<Utool_dataprivacy_approve_data_request>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_dataprivacy_approve_data_request&requestid=" + FString::FromInt(_requestid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_dataprivacy_approve_data_request::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_dataprivacy_approve_data_request::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_dataprivacy_approve_data_request::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_dataprivacy_bulk_approve_data_requests* Utool_dataprivacy_bulk_approve_data_requests::tool_dataprivacy_bulk_approve_data_requests(
			const FString ServerURL,
			const FString Token,
			const int32 _requestids)
{
	Utool_dataprivacy_bulk_approve_data_requests* Node = NewObject<Utool_dataprivacy_bulk_approve_data_requests>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_dataprivacy_bulk_approve_data_requests&requestids[0]=" + FString::FromInt(_requestids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_dataprivacy_bulk_approve_data_requests::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_dataprivacy_bulk_approve_data_requests::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_dataprivacy_bulk_approve_data_requests::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_dataprivacy_bulk_deny_data_requests* Utool_dataprivacy_bulk_deny_data_requests::tool_dataprivacy_bulk_deny_data_requests(
			const FString ServerURL,
			const FString Token,
			const int32 _requestids)
{
	Utool_dataprivacy_bulk_deny_data_requests* Node = NewObject<Utool_dataprivacy_bulk_deny_data_requests>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_dataprivacy_bulk_deny_data_requests&requestids[0]=" + FString::FromInt(_requestids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_dataprivacy_bulk_deny_data_requests::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_dataprivacy_bulk_deny_data_requests::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_dataprivacy_bulk_deny_data_requests::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_dataprivacy_cancel_data_request* Utool_dataprivacy_cancel_data_request::tool_dataprivacy_cancel_data_request(
			const FString ServerURL,
			const FString Token,
			const int32 _requestid)
{
	Utool_dataprivacy_cancel_data_request* Node = NewObject<Utool_dataprivacy_cancel_data_request>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_dataprivacy_cancel_data_request&requestid=" + FString::FromInt(_requestid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_dataprivacy_cancel_data_request::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_dataprivacy_cancel_data_request::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_dataprivacy_cancel_data_request::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_dataprivacy_confirm_contexts_for_deletion* Utool_dataprivacy_confirm_contexts_for_deletion::tool_dataprivacy_confirm_contexts_for_deletion(
			const FString ServerURL,
			const FString Token,
			const int32 _ids)
{
	Utool_dataprivacy_confirm_contexts_for_deletion* Node = NewObject<Utool_dataprivacy_confirm_contexts_for_deletion>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_dataprivacy_confirm_contexts_for_deletion&ids[0]=" + FString::FromInt(_ids);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_dataprivacy_confirm_contexts_for_deletion::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_dataprivacy_confirm_contexts_for_deletion::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_dataprivacy_confirm_contexts_for_deletion::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_dataprivacy_contact_dpo* Utool_dataprivacy_contact_dpo::tool_dataprivacy_contact_dpo(
			const FString ServerURL,
			const FString Token,
			const FString _message)
{
	Utool_dataprivacy_contact_dpo* Node = NewObject<Utool_dataprivacy_contact_dpo>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_dataprivacy_contact_dpo&message=" + _message;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_dataprivacy_contact_dpo::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_dataprivacy_contact_dpo::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_dataprivacy_contact_dpo::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_dataprivacy_create_category_form* Utool_dataprivacy_create_category_form::tool_dataprivacy_create_category_form(
			const FString ServerURL,
			const FString Token,
			const FString _jsonformdata)
{
	Utool_dataprivacy_create_category_form* Node = NewObject<Utool_dataprivacy_create_category_form>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_dataprivacy_create_category_form&jsonformdata=" + _jsonformdata;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_dataprivacy_create_category_form::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_dataprivacy_create_category_form::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_dataprivacy_create_category_form::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_dataprivacy_create_purpose_form* Utool_dataprivacy_create_purpose_form::tool_dataprivacy_create_purpose_form(
			const FString ServerURL,
			const FString Token,
			const FString _jsonformdata)
{
	Utool_dataprivacy_create_purpose_form* Node = NewObject<Utool_dataprivacy_create_purpose_form>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_dataprivacy_create_purpose_form&jsonformdata=" + _jsonformdata;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_dataprivacy_create_purpose_form::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_dataprivacy_create_purpose_form::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_dataprivacy_create_purpose_form::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_dataprivacy_delete_category* Utool_dataprivacy_delete_category::tool_dataprivacy_delete_category(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Utool_dataprivacy_delete_category* Node = NewObject<Utool_dataprivacy_delete_category>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_dataprivacy_delete_category&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_dataprivacy_delete_category::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_dataprivacy_delete_category::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_dataprivacy_delete_category::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_dataprivacy_delete_purpose* Utool_dataprivacy_delete_purpose::tool_dataprivacy_delete_purpose(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Utool_dataprivacy_delete_purpose* Node = NewObject<Utool_dataprivacy_delete_purpose>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_dataprivacy_delete_purpose&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_dataprivacy_delete_purpose::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_dataprivacy_delete_purpose::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_dataprivacy_delete_purpose::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_dataprivacy_deny_data_request* Utool_dataprivacy_deny_data_request::tool_dataprivacy_deny_data_request(
			const FString ServerURL,
			const FString Token,
			const int32 _requestid)
{
	Utool_dataprivacy_deny_data_request* Node = NewObject<Utool_dataprivacy_deny_data_request>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_dataprivacy_deny_data_request&requestid=" + FString::FromInt(_requestid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_dataprivacy_deny_data_request::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_dataprivacy_deny_data_request::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_dataprivacy_deny_data_request::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_dataprivacy_get_activity_options* Utool_dataprivacy_get_activity_options::tool_dataprivacy_get_activity_options(
			const FString ServerURL,
			const FString Token,
			const int32 _nodefaults)
{
	Utool_dataprivacy_get_activity_options* Node = NewObject<Utool_dataprivacy_get_activity_options>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_dataprivacy_get_activity_options&nodefaults=" + FString::FromInt(_nodefaults);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_dataprivacy_get_activity_options::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_dataprivacy_get_activity_options::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_dataprivacy_get_activity_options::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_dataprivacy_get_category_options* Utool_dataprivacy_get_category_options::tool_dataprivacy_get_category_options(
			const FString ServerURL,
			const FString Token,
			const int32 _includeinherit,
			const int32 _includenotset)
{
	Utool_dataprivacy_get_category_options* Node = NewObject<Utool_dataprivacy_get_category_options>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_dataprivacy_get_category_options&includeinherit=" + FString::FromInt(_includeinherit) + "&includenotset=" + FString::FromInt(_includenotset);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_dataprivacy_get_category_options::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_dataprivacy_get_category_options::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_dataprivacy_get_category_options::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_dataprivacy_get_data_request* Utool_dataprivacy_get_data_request::tool_dataprivacy_get_data_request(
			const FString ServerURL,
			const FString Token,
			const int32 _requestid)
{
	Utool_dataprivacy_get_data_request* Node = NewObject<Utool_dataprivacy_get_data_request>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_dataprivacy_get_data_request&requestid=" + FString::FromInt(_requestid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_dataprivacy_get_data_request::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_dataprivacy_get_data_request::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_dataprivacy_get_data_request::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_dataprivacy_get_purpose_options* Utool_dataprivacy_get_purpose_options::tool_dataprivacy_get_purpose_options(
			const FString ServerURL,
			const FString Token,
			const int32 _includeinherit,
			const int32 _includenotset)
{
	Utool_dataprivacy_get_purpose_options* Node = NewObject<Utool_dataprivacy_get_purpose_options>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_dataprivacy_get_purpose_options&includeinherit=" + FString::FromInt(_includeinherit) + "&includenotset=" + FString::FromInt(_includenotset);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_dataprivacy_get_purpose_options::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_dataprivacy_get_purpose_options::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_dataprivacy_get_purpose_options::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_dataprivacy_get_users* Utool_dataprivacy_get_users::tool_dataprivacy_get_users(
			const FString ServerURL,
			const FString Token,
			const FString _query)
{
	Utool_dataprivacy_get_users* Node = NewObject<Utool_dataprivacy_get_users>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_dataprivacy_get_users&query=" + _query;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_dataprivacy_get_users::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_dataprivacy_get_users::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_dataprivacy_get_users::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_dataprivacy_mark_complete* Utool_dataprivacy_mark_complete::tool_dataprivacy_mark_complete(
			const FString ServerURL,
			const FString Token,
			const int32 _requestid)
{
	Utool_dataprivacy_mark_complete* Node = NewObject<Utool_dataprivacy_mark_complete>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_dataprivacy_mark_complete&requestid=" + FString::FromInt(_requestid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_dataprivacy_mark_complete::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_dataprivacy_mark_complete::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_dataprivacy_mark_complete::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_dataprivacy_set_context_defaults* Utool_dataprivacy_set_context_defaults::tool_dataprivacy_set_context_defaults(
			const FString ServerURL,
			const FString Token,
			const int32 _contextlevel,
			const int32 _category,
			const int32 _purpose,
			const FString _activity,
			const int32 _override)
{
	Utool_dataprivacy_set_context_defaults* Node = NewObject<Utool_dataprivacy_set_context_defaults>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_dataprivacy_set_context_defaults&contextlevel=" + FString::FromInt(_contextlevel) + "&category=" + FString::FromInt(_category) + "&purpose=" + FString::FromInt(_purpose) + "&activity=" + _activity + "&override=" + FString::FromInt(_override);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_dataprivacy_set_context_defaults::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_dataprivacy_set_context_defaults::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_dataprivacy_set_context_defaults::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_dataprivacy_set_context_form* Utool_dataprivacy_set_context_form::tool_dataprivacy_set_context_form(
			const FString ServerURL,
			const FString Token,
			const FString _jsonformdata)
{
	Utool_dataprivacy_set_context_form* Node = NewObject<Utool_dataprivacy_set_context_form>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_dataprivacy_set_context_form&jsonformdata=" + _jsonformdata;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_dataprivacy_set_context_form::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_dataprivacy_set_context_form::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_dataprivacy_set_context_form::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_dataprivacy_set_contextlevel_form* Utool_dataprivacy_set_contextlevel_form::tool_dataprivacy_set_contextlevel_form(
			const FString ServerURL,
			const FString Token,
			const FString _jsonformdata)
{
	Utool_dataprivacy_set_contextlevel_form* Node = NewObject<Utool_dataprivacy_set_contextlevel_form>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_dataprivacy_set_contextlevel_form&jsonformdata=" + _jsonformdata;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_dataprivacy_set_contextlevel_form::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_dataprivacy_set_contextlevel_form::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_dataprivacy_set_contextlevel_form::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_dataprivacy_tree_extra_branches* Utool_dataprivacy_tree_extra_branches::tool_dataprivacy_tree_extra_branches(
			const FString ServerURL,
			const FString Token,
			const int32 _contextid,
			const FString _element)
{
	Utool_dataprivacy_tree_extra_branches* Node = NewObject<Utool_dataprivacy_tree_extra_branches>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_dataprivacy_tree_extra_branches&contextid=" + FString::FromInt(_contextid) + "&element=" + _element;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_dataprivacy_tree_extra_branches::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_dataprivacy_tree_extra_branches::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_dataprivacy_tree_extra_branches::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_lp_data_for_competencies_manage_page* Utool_lp_data_for_competencies_manage_page::tool_lp_data_for_competencies_manage_page(
			const FString ServerURL,
			const FString Token,
			const int32 _competencyframeworkid,
			const FString _search)
{
	Utool_lp_data_for_competencies_manage_page* Node = NewObject<Utool_lp_data_for_competencies_manage_page>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_lp_data_for_competencies_manage_page&competencyframeworkid=" + FString::FromInt(_competencyframeworkid) + "&search=" + _search;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_lp_data_for_competencies_manage_page::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_lp_data_for_competencies_manage_page::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_lp_data_for_competencies_manage_page::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_lp_data_for_competency_frameworks_manage_page* Utool_lp_data_for_competency_frameworks_manage_page::tool_lp_data_for_competency_frameworks_manage_page(
			const FString ServerURL,
			const FString Token,
			const int32 _pagecontextcontextid,
			const FString _pagecontextcontextlevel,
			const int32 _pagecontextinstanceid)
{
	Utool_lp_data_for_competency_frameworks_manage_page* Node = NewObject<Utool_lp_data_for_competency_frameworks_manage_page>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_lp_data_for_competency_frameworks_manage_page&pagecontext[contextid]=" + FString::FromInt(_pagecontextcontextid) + "&pagecontext[contextlevel]=" + _pagecontextcontextlevel + "&pagecontext[instanceid]=" + FString::FromInt(_pagecontextinstanceid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_lp_data_for_competency_frameworks_manage_page::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_lp_data_for_competency_frameworks_manage_page::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_lp_data_for_competency_frameworks_manage_page::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_lp_data_for_competency_summary* Utool_lp_data_for_competency_summary::tool_lp_data_for_competency_summary(
			const FString ServerURL,
			const FString Token,
			const int32 _competencyid,
			const int32 _includerelated,
			const int32 _includecourses)
{
	Utool_lp_data_for_competency_summary* Node = NewObject<Utool_lp_data_for_competency_summary>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_lp_data_for_competency_summary&competencyid=" + FString::FromInt(_competencyid) + "&includerelated=" + FString::FromInt(_includerelated) + "&includecourses=" + FString::FromInt(_includecourses);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_lp_data_for_competency_summary::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_lp_data_for_competency_summary::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_lp_data_for_competency_summary::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_lp_data_for_course_competencies_page* Utool_lp_data_for_course_competencies_page::tool_lp_data_for_course_competencies_page(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _moduleid)
{
	Utool_lp_data_for_course_competencies_page* Node = NewObject<Utool_lp_data_for_course_competencies_page>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_lp_data_for_course_competencies_page&courseid=" + FString::FromInt(_courseid) + "&moduleid=" + FString::FromInt(_moduleid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_lp_data_for_course_competencies_page::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_lp_data_for_course_competencies_page::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_lp_data_for_course_competencies_page::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_lp_data_for_plan_page* Utool_lp_data_for_plan_page::tool_lp_data_for_plan_page(
			const FString ServerURL,
			const FString Token,
			const int32 _planid)
{
	Utool_lp_data_for_plan_page* Node = NewObject<Utool_lp_data_for_plan_page>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_lp_data_for_plan_page&planid=" + FString::FromInt(_planid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_lp_data_for_plan_page::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_lp_data_for_plan_page::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_lp_data_for_plan_page::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_lp_data_for_plans_page* Utool_lp_data_for_plans_page::tool_lp_data_for_plans_page(
			const FString ServerURL,
			const FString Token,
			const int32 _userid)
{
	Utool_lp_data_for_plans_page* Node = NewObject<Utool_lp_data_for_plans_page>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_lp_data_for_plans_page&userid=" + FString::FromInt(_userid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_lp_data_for_plans_page::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_lp_data_for_plans_page::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_lp_data_for_plans_page::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_lp_data_for_related_competencies_section* Utool_lp_data_for_related_competencies_section::tool_lp_data_for_related_competencies_section(
			const FString ServerURL,
			const FString Token,
			const int32 _competencyid)
{
	Utool_lp_data_for_related_competencies_section* Node = NewObject<Utool_lp_data_for_related_competencies_section>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_lp_data_for_related_competencies_section&competencyid=" + FString::FromInt(_competencyid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_lp_data_for_related_competencies_section::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_lp_data_for_related_competencies_section::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_lp_data_for_related_competencies_section::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_lp_data_for_template_competencies_page* Utool_lp_data_for_template_competencies_page::tool_lp_data_for_template_competencies_page(
			const FString ServerURL,
			const FString Token,
			const int32 _templateid,
			const int32 _pagecontextcontextid,
			const FString _pagecontextcontextlevel,
			const int32 _pagecontextinstanceid)
{
	Utool_lp_data_for_template_competencies_page* Node = NewObject<Utool_lp_data_for_template_competencies_page>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_lp_data_for_template_competencies_page&templateid=" + FString::FromInt(_templateid) + "&pagecontext[contextid]=" + FString::FromInt(_pagecontextcontextid) + "&pagecontext[contextlevel]=" + _pagecontextcontextlevel + "&pagecontext[instanceid]=" + FString::FromInt(_pagecontextinstanceid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_lp_data_for_template_competencies_page::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_lp_data_for_template_competencies_page::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_lp_data_for_template_competencies_page::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_lp_data_for_templates_manage_page* Utool_lp_data_for_templates_manage_page::tool_lp_data_for_templates_manage_page(
			const FString ServerURL,
			const FString Token,
			const int32 _pagecontextcontextid,
			const FString _pagecontextcontextlevel,
			const int32 _pagecontextinstanceid)
{
	Utool_lp_data_for_templates_manage_page* Node = NewObject<Utool_lp_data_for_templates_manage_page>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_lp_data_for_templates_manage_page&pagecontext[contextid]=" + FString::FromInt(_pagecontextcontextid) + "&pagecontext[contextlevel]=" + _pagecontextcontextlevel + "&pagecontext[instanceid]=" + FString::FromInt(_pagecontextinstanceid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_lp_data_for_templates_manage_page::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_lp_data_for_templates_manage_page::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_lp_data_for_templates_manage_page::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_lp_data_for_user_competency_summary* Utool_lp_data_for_user_competency_summary::tool_lp_data_for_user_competency_summary(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _competencyid)
{
	Utool_lp_data_for_user_competency_summary* Node = NewObject<Utool_lp_data_for_user_competency_summary>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_lp_data_for_user_competency_summary&userid=" + FString::FromInt(_userid) + "&competencyid=" + FString::FromInt(_competencyid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_lp_data_for_user_competency_summary::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_lp_data_for_user_competency_summary::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_lp_data_for_user_competency_summary::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_lp_data_for_user_competency_summary_in_course* Utool_lp_data_for_user_competency_summary_in_course::tool_lp_data_for_user_competency_summary_in_course(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _competencyid,
			const int32 _courseid)
{
	Utool_lp_data_for_user_competency_summary_in_course* Node = NewObject<Utool_lp_data_for_user_competency_summary_in_course>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_lp_data_for_user_competency_summary_in_course&userid=" + FString::FromInt(_userid) + "&competencyid=" + FString::FromInt(_competencyid) + "&courseid=" + FString::FromInt(_courseid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_lp_data_for_user_competency_summary_in_course::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_lp_data_for_user_competency_summary_in_course::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_lp_data_for_user_competency_summary_in_course::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_lp_data_for_user_competency_summary_in_plan* Utool_lp_data_for_user_competency_summary_in_plan::tool_lp_data_for_user_competency_summary_in_plan(
			const FString ServerURL,
			const FString Token,
			const int32 _competencyid,
			const int32 _planid)
{
	Utool_lp_data_for_user_competency_summary_in_plan* Node = NewObject<Utool_lp_data_for_user_competency_summary_in_plan>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_lp_data_for_user_competency_summary_in_plan&competencyid=" + FString::FromInt(_competencyid) + "&planid=" + FString::FromInt(_planid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_lp_data_for_user_competency_summary_in_plan::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_lp_data_for_user_competency_summary_in_plan::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_lp_data_for_user_competency_summary_in_plan::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_lp_data_for_user_evidence_list_page* Utool_lp_data_for_user_evidence_list_page::tool_lp_data_for_user_evidence_list_page(
			const FString ServerURL,
			const FString Token,
			const int32 _userid)
{
	Utool_lp_data_for_user_evidence_list_page* Node = NewObject<Utool_lp_data_for_user_evidence_list_page>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_lp_data_for_user_evidence_list_page&userid=" + FString::FromInt(_userid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_lp_data_for_user_evidence_list_page::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_lp_data_for_user_evidence_list_page::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_lp_data_for_user_evidence_list_page::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_lp_data_for_user_evidence_page* Utool_lp_data_for_user_evidence_page::tool_lp_data_for_user_evidence_page(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Utool_lp_data_for_user_evidence_page* Node = NewObject<Utool_lp_data_for_user_evidence_page>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_lp_data_for_user_evidence_page&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_lp_data_for_user_evidence_page::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_lp_data_for_user_evidence_page::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_lp_data_for_user_evidence_page::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_lp_list_courses_using_competency* Utool_lp_list_courses_using_competency::tool_lp_list_courses_using_competency(
			const FString ServerURL,
			const FString Token,
			const int32 _id)
{
	Utool_lp_list_courses_using_competency* Node = NewObject<Utool_lp_list_courses_using_competency>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_lp_list_courses_using_competency&id=" + FString::FromInt(_id);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_lp_list_courses_using_competency::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_lp_list_courses_using_competency::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_lp_list_courses_using_competency::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_lp_search_cohorts* Utool_lp_search_cohorts::tool_lp_search_cohorts(
			const FString ServerURL,
			const FString Token,
			const FString _query,
			const int32 _contextcontextid,
			const FString _contextcontextlevel,
			const int32 _contextinstanceid,
			const FString _includes,
			const int32 _limitfrom,
			const int32 _limitnum)
{
	Utool_lp_search_cohorts* Node = NewObject<Utool_lp_search_cohorts>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_lp_search_cohorts&query=" + _query + "&context[contextid]=" + FString::FromInt(_contextcontextid) + "&context[contextlevel]=" + _contextcontextlevel + "&context[instanceid]=" + FString::FromInt(_contextinstanceid) + "&includes=" + _includes + "&limitfrom=" + FString::FromInt(_limitfrom) + "&limitnum=" + FString::FromInt(_limitnum);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_lp_search_cohorts::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_lp_search_cohorts::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_lp_search_cohorts::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_lp_search_users* Utool_lp_search_users::tool_lp_search_users(
			const FString ServerURL,
			const FString Token,
			const FString _query,
			const FString _capability,
			const int32 _limitfrom,
			const FString _limitnum)
{
	Utool_lp_search_users* Node = NewObject<Utool_lp_search_users>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_lp_search_users&query=" + _query + "&capability=" + _capability + "&limitfrom=" + FString::FromInt(_limitfrom) + "&limitnum=" + _limitnum;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_lp_search_users::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_lp_search_users::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_lp_search_users::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_mobile_call_external_functions* Utool_mobile_call_external_functions::tool_mobile_call_external_functions(
			const FString ServerURL,
			const FString Token,
			const FString _requestsfunction,
			const FString _requestsarguments,
			const int32 _requestssettingraw,
			const int32 _requestssettingfilter,
			const int32 _requestssettingfileurl,
			const FString _requestssettinglang)
{
	Utool_mobile_call_external_functions* Node = NewObject<Utool_mobile_call_external_functions>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_mobile_call_external_functions&requests[0][function]=" + _requestsfunction + "&requests[0][arguments]=" + _requestsarguments + "&requests[0][settingraw]=" + FString::FromInt(_requestssettingraw) + "&requests[0][settingfilter]=" + FString::FromInt(_requestssettingfilter) + "&requests[0][settingfileurl]=" + FString::FromInt(_requestssettingfileurl) + "&requests[0][settinglang]=" + _requestssettinglang;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_mobile_call_external_functions::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_mobile_call_external_functions::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_mobile_call_external_functions::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_mobile_get_autologin_key* Utool_mobile_get_autologin_key::tool_mobile_get_autologin_key(
			const FString ServerURL,
			const FString Token,
			const FString _privatetoken)
{
	Utool_mobile_get_autologin_key* Node = NewObject<Utool_mobile_get_autologin_key>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_mobile_get_autologin_key&privatetoken=" + _privatetoken;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_mobile_get_autologin_key::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_mobile_get_autologin_key::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_mobile_get_autologin_key::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_mobile_get_config* Utool_mobile_get_config::tool_mobile_get_config(
			const FString ServerURL,
			const FString Token,
			const FString _section)
{
	Utool_mobile_get_config* Node = NewObject<Utool_mobile_get_config>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_mobile_get_config&section=" + _section;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_mobile_get_config::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_mobile_get_config::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_mobile_get_config::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_mobile_get_content* Utool_mobile_get_content::tool_mobile_get_content(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const FString _method,
			const FString _argsname,
			const FString _argsvalue)
{
	Utool_mobile_get_content* Node = NewObject<Utool_mobile_get_content>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_mobile_get_content&component=" + _component + "&method=" + _method + "&args[0][name]=" + _argsname + "&args[0][value]=" + _argsvalue;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_mobile_get_content::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_mobile_get_content::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_mobile_get_content::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_mobile_get_plugins_supporting_mobile* Utool_mobile_get_plugins_supporting_mobile::tool_mobile_get_plugins_supporting_mobile(
			const FString ServerURL,
			const FString Token)
{
	Utool_mobile_get_plugins_supporting_mobile* Node = NewObject<Utool_mobile_get_plugins_supporting_mobile>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_mobile_get_plugins_supporting_mobile";

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_mobile_get_plugins_supporting_mobile::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_mobile_get_plugins_supporting_mobile::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_mobile_get_plugins_supporting_mobile::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_mobile_get_public_config* Utool_mobile_get_public_config::tool_mobile_get_public_config(
			const FString ServerURL,
			const FString Token)
{
	Utool_mobile_get_public_config* Node = NewObject<Utool_mobile_get_public_config>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_mobile_get_public_config";

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_mobile_get_public_config::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_mobile_get_public_config::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_mobile_get_public_config::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_mobile_get_tokens_for_qr_login* Utool_mobile_get_tokens_for_qr_login::tool_mobile_get_tokens_for_qr_login(
			const FString ServerURL,
			const FString Token,
			const FString _qrloginkey,
			const int32 _userid)
{
	Utool_mobile_get_tokens_for_qr_login* Node = NewObject<Utool_mobile_get_tokens_for_qr_login>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_mobile_get_tokens_for_qr_login&qrloginkey=" + _qrloginkey + "&userid=" + FString::FromInt(_userid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_mobile_get_tokens_for_qr_login::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_mobile_get_tokens_for_qr_login::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_mobile_get_tokens_for_qr_login::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_mobile_validate_subscription_key* Utool_mobile_validate_subscription_key::tool_mobile_validate_subscription_key(
			const FString ServerURL,
			const FString Token,
			const FString _key)
{
	Utool_mobile_validate_subscription_key* Node = NewObject<Utool_mobile_validate_subscription_key>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_mobile_validate_subscription_key&key=" + _key;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_mobile_validate_subscription_key::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_mobile_validate_subscription_key::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_mobile_validate_subscription_key::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_moodlenet_search_courses* Utool_moodlenet_search_courses::tool_moodlenet_search_courses(
			const FString ServerURL,
			const FString Token,
			const FString _searchvalue)
{
	Utool_moodlenet_search_courses* Node = NewObject<Utool_moodlenet_search_courses>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_moodlenet_search_courses&searchvalue=" + _searchvalue;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_moodlenet_search_courses::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_moodlenet_search_courses::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_moodlenet_search_courses::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_moodlenet_verify_webfinger* Utool_moodlenet_verify_webfinger::tool_moodlenet_verify_webfinger(
			const FString ServerURL,
			const FString Token,
			const FString _profileurl,
			const int32 _course,
			const int32 _section)
{
	Utool_moodlenet_verify_webfinger* Node = NewObject<Utool_moodlenet_verify_webfinger>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_moodlenet_verify_webfinger&profileurl=" + _profileurl + "&course=" + FString::FromInt(_course) + "&section=" + FString::FromInt(_section);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_moodlenet_verify_webfinger::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_moodlenet_verify_webfinger::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_moodlenet_verify_webfinger::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_policy_get_policy_version* Utool_policy_get_policy_version::tool_policy_get_policy_version(
			const FString ServerURL,
			const FString Token,
			const int32 _versionid,
			const int32 _behalfid)
{
	Utool_policy_get_policy_version* Node = NewObject<Utool_policy_get_policy_version>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_policy_get_policy_version&versionid=" + FString::FromInt(_versionid) + "&behalfid=" + FString::FromInt(_behalfid);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_policy_get_policy_version::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_policy_get_policy_version::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_policy_get_policy_version::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_policy_submit_accept_on_behalf* Utool_policy_submit_accept_on_behalf::tool_policy_submit_accept_on_behalf(
			const FString ServerURL,
			const FString Token,
			const FString _jsonformdata)
{
	Utool_policy_submit_accept_on_behalf* Node = NewObject<Utool_policy_submit_accept_on_behalf>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_policy_submit_accept_on_behalf&jsonformdata=" + _jsonformdata;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_policy_submit_accept_on_behalf::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_policy_submit_accept_on_behalf::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_policy_submit_accept_on_behalf::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_templatelibrary_list_templates* Utool_templatelibrary_list_templates::tool_templatelibrary_list_templates(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const FString _search,
			const FString _themename)
{
	Utool_templatelibrary_list_templates* Node = NewObject<Utool_templatelibrary_list_templates>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_templatelibrary_list_templates&component=" + _component + "&search=" + _search + "&themename=" + _themename;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_templatelibrary_list_templates::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_templatelibrary_list_templates::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_templatelibrary_list_templates::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_templatelibrary_load_canonical_template* Utool_templatelibrary_load_canonical_template::tool_templatelibrary_load_canonical_template(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const FString _template)
{
	Utool_templatelibrary_load_canonical_template* Node = NewObject<Utool_templatelibrary_load_canonical_template>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_templatelibrary_load_canonical_template&component=" + _component + "&template=" + _template;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_templatelibrary_load_canonical_template::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_templatelibrary_load_canonical_template::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_templatelibrary_load_canonical_template::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_usertours_complete_tour* Utool_usertours_complete_tour::tool_usertours_complete_tour(
			const FString ServerURL,
			const FString Token,
			const int32 _tourid,
			const int32 _context,
			const FString _pageurl,
			const int32 _stepid,
			const int32 _stepindex)
{
	Utool_usertours_complete_tour* Node = NewObject<Utool_usertours_complete_tour>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_usertours_complete_tour&tourid=" + FString::FromInt(_tourid) + "&context=" + FString::FromInt(_context) + "&pageurl=" + _pageurl + "&stepid=" + FString::FromInt(_stepid) + "&stepindex=" + FString::FromInt(_stepindex);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_usertours_complete_tour::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_usertours_complete_tour::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_usertours_complete_tour::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_usertours_fetch_and_start_tour* Utool_usertours_fetch_and_start_tour::tool_usertours_fetch_and_start_tour(
			const FString ServerURL,
			const FString Token,
			const int32 _tourid,
			const int32 _context,
			const FString _pageurl)
{
	Utool_usertours_fetch_and_start_tour* Node = NewObject<Utool_usertours_fetch_and_start_tour>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_usertours_fetch_and_start_tour&tourid=" + FString::FromInt(_tourid) + "&context=" + FString::FromInt(_context) + "&pageurl=" + _pageurl;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_usertours_fetch_and_start_tour::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_usertours_fetch_and_start_tour::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_usertours_fetch_and_start_tour::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_usertours_reset_tour* Utool_usertours_reset_tour::tool_usertours_reset_tour(
			const FString ServerURL,
			const FString Token,
			const int32 _tourid,
			const int32 _context,
			const FString _pageurl)
{
	Utool_usertours_reset_tour* Node = NewObject<Utool_usertours_reset_tour>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_usertours_reset_tour&tourid=" + FString::FromInt(_tourid) + "&context=" + FString::FromInt(_context) + "&pageurl=" + _pageurl;

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_usertours_reset_tour::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_usertours_reset_tour::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_usertours_reset_tour::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_usertours_step_shown* Utool_usertours_step_shown::tool_usertours_step_shown(
			const FString ServerURL,
			const FString Token,
			const int32 _tourid,
			const int32 _context,
			const FString _pageurl,
			const int32 _stepid,
			const int32 _stepindex)
{
	Utool_usertours_step_shown* Node = NewObject<Utool_usertours_step_shown>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_usertours_step_shown&tourid=" + FString::FromInt(_tourid) + "&context=" + FString::FromInt(_context) + "&pageurl=" + _pageurl + "&stepid=" + FString::FromInt(_stepid) + "&stepindex=" + FString::FromInt(_stepindex);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_usertours_step_shown::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_usertours_step_shown::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_usertours_step_shown::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

Utool_xmldb_invoke_move_action* Utool_xmldb_invoke_move_action::tool_xmldb_invoke_move_action(
			const FString ServerURL,
			const FString Token,
			const FString _action,
			const FString _dir,
			const FString _table,
			const int32 _position,
			const FString _field,
			const FString _key,
			const FString _index)
{
	Utool_xmldb_invoke_move_action* Node = NewObject<Utool_xmldb_invoke_move_action>();

	FString url = "https://" + ServerURL + "/webservice/rest/server.php?wstoken=" + Token + "&moodlewsrestformat=json&wsfunction=tool_xmldb_invoke_move_action&action=" + _action + "&dir=" + _dir + "&table=" + _table + "&field=" + _field + "&key=" + _key + "&index=" + _index + "&position=" + FString::FromInt(_position);

	Node->APIRequest = FHttpModule::Get().CreateRequest();
	Node->APIRequest->SetURL(url);
	Node->APIRequest->SetVerb(TEXT("POST"));
	return Node;
}

void Utool_xmldb_invoke_move_action::Activate()
{
	APIRequest->OnProcessRequestComplete().BindUObject(this, &Utool_xmldb_invoke_move_action::OnServerAnswer);
	APIRequest->ProcessRequest();
}

void Utool_xmldb_invoke_move_action::OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	Finished.Broadcast(Response->GetContentAsString());
}

