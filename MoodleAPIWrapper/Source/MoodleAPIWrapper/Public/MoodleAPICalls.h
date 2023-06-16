#pragma once

#include "CoreMinimal.h"

#include "HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Kismet/BlueprintAsyncActionBase.h"

#include "MoodleAPICalls.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAPICallOutputPin, FString, Response);

// ---- Moodle API Calls ---- //

UCLASS()
class MOODLEAPIWRAPPER_API UMoodleAPIHelpers : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	public:
		UFUNCTION(BlueprintCallable, Category = "JSON")
		static FString GetValueFromJsonString(const FString& JsonString, const FString& Key);
};

UCLASS()
class MOODLEAPIWRAPPER_API Uquery_token_from_user : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "query_token_from_user"), Category = "Moodle API Calls")
		static Uquery_token_from_user* query_token_from_user(
			const FString ServerURL,
			const FString _username = "",
			const FString _password = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Uauth_email_get_signup_settings : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "auth_email_get_signup_settings"), Category = "Moodle API Calls")
		static Uauth_email_get_signup_settings* auth_email_get_signup_settings(
			const FString ServerURL,
			const FString Token
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Uauth_email_signup_user : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "auth_email_signup_user"), Category = "Moodle API Calls")
		static Uauth_email_signup_user* auth_email_signup_user(
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
			const FString _city = "",
			const FString _country = "",
			const FString _recaptchachallengehash = "",
			const FString _recaptcharesponse = "",
			const FString _redirect = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ublock_accessreview_get_module_data : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "block_accessreview_get_module_data"), Category = "Moodle API Calls")
		static Ublock_accessreview_get_module_data* block_accessreview_get_module_data(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ublock_accessreview_get_section_data : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "block_accessreview_get_section_data"), Category = "Moodle API Calls")
		static Ublock_accessreview_get_section_data* block_accessreview_get_section_data(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ublock_recentlyaccesseditems_get_recent_items : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "block_recentlyaccesseditems_get_recent_items"), Category = "Moodle API Calls")
		static Ublock_recentlyaccesseditems_get_recent_items* block_recentlyaccesseditems_get_recent_items(
			const FString ServerURL,
			const FString Token,
			const int32 _limit = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ublock_starredcourses_get_starred_courses : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "block_starredcourses_get_starred_courses"), Category = "Moodle API Calls")
		static Ublock_starredcourses_get_starred_courses* block_starredcourses_get_starred_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _limit = 0,
			const int32 _offset = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_auth_confirm_user : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_auth_confirm_user"), Category = "Moodle API Calls")
		static Ucore_auth_confirm_user* core_auth_confirm_user(
			const FString ServerURL,
			const FString Token,
			const FString _username,
			const FString _secret
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_auth_is_age_digital_consent_verification_enabled : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_auth_is_age_digital_consent_verification_enabled"), Category = "Moodle API Calls")
		static Ucore_auth_is_age_digital_consent_verification_enabled* core_auth_is_age_digital_consent_verification_enabled(
			const FString ServerURL,
			const FString Token
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_auth_is_minor : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_auth_is_minor"), Category = "Moodle API Calls")
		static Ucore_auth_is_minor* core_auth_is_minor(
			const FString ServerURL,
			const FString Token,
			const int32 _age,
			const FString _country
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_auth_request_password_reset : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_auth_request_password_reset"), Category = "Moodle API Calls")
		static Ucore_auth_request_password_reset* core_auth_request_password_reset(
			const FString ServerURL,
			const FString Token,
			const FString _username = "",
			const FString _email = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_auth_resend_confirmation_email : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_auth_resend_confirmation_email"), Category = "Moodle API Calls")
		static Ucore_auth_resend_confirmation_email* core_auth_resend_confirmation_email(
			const FString ServerURL,
			const FString Token,
			const FString _username,
			const FString _password,
			const FString _redirect = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_backup_get_async_backup_links_backup : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_backup_get_async_backup_links_backup"), Category = "Moodle API Calls")
		static Ucore_backup_get_async_backup_links_backup* core_backup_get_async_backup_links_backup(
			const FString ServerURL,
			const FString Token,
			const FString _filename,
			const int32 _contextid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_backup_get_async_backup_links_restore : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_backup_get_async_backup_links_restore"), Category = "Moodle API Calls")
		static Ucore_backup_get_async_backup_links_restore* core_backup_get_async_backup_links_restore(
			const FString ServerURL,
			const FString Token,
			const FString _backupid,
			const int32 _contextid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_backup_get_async_backup_progress : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_backup_get_async_backup_progress"), Category = "Moodle API Calls")
		static Ucore_backup_get_async_backup_progress* core_backup_get_async_backup_progress(
			const FString ServerURL,
			const FString Token,
			const FString _backupids,
			const int32 _contextid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_backup_get_copy_progress : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_backup_get_copy_progress"), Category = "Moodle API Calls")
		static Ucore_backup_get_copy_progress* core_backup_get_copy_progress(
			const FString ServerURL,
			const FString Token,
			const FString _copiesbackupid,
			const FString _copiesrestoreid,
			const FString _copiesoperation
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_backup_submit_copy_form : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_backup_submit_copy_form"), Category = "Moodle API Calls")
		static Ucore_backup_submit_copy_form* core_backup_submit_copy_form(
			const FString ServerURL,
			const FString Token,
			const FString _jsonformdata
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_badges_get_user_badges : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_badges_get_user_badges"), Category = "Moodle API Calls")
		static Ucore_badges_get_user_badges* core_badges_get_user_badges(
			const FString ServerURL,
			const FString Token,
			const int32 _userid = 0,
			const int32 _courseid = 0,
			const int32 _page = 0,
			const int32 _perpage = 0,
			const FString _search = "",
			const int32 _onlypublic = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_block_fetch_addable_blocks : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_block_fetch_addable_blocks"), Category = "Moodle API Calls")
		static Ucore_block_fetch_addable_blocks* core_block_fetch_addable_blocks(
			const FString ServerURL,
			const FString Token,
			const int32 _pagecontextid,
			const FString _pagetype,
			const FString _pagelayout,
			const FString _subpage = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_block_get_course_blocks : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_block_get_course_blocks"), Category = "Moodle API Calls")
		static Ucore_block_get_course_blocks* core_block_get_course_blocks(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _returncontents = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_block_get_dashboard_blocks : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_block_get_dashboard_blocks"), Category = "Moodle API Calls")
		static Ucore_block_get_dashboard_blocks* core_block_get_dashboard_blocks(
			const FString ServerURL,
			const FString Token,
			const int32 _userid = 0,
			const int32 _returncontents = 0,
			const FString _mypage = "__default"
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_blog_get_entries : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_blog_get_entries"), Category = "Moodle API Calls")
		static Ucore_blog_get_entries* core_blog_get_entries(
			const FString ServerURL,
			const FString Token,
			const FString _filtersname,
			const FString _filtersvalue,
			const int32 _page = 0,
			const int32 _perpage = 10
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_blog_view_entries : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_blog_view_entries"), Category = "Moodle API Calls")
		static Ucore_blog_view_entries* core_blog_view_entries(
			const FString ServerURL,
			const FString Token,
			const FString _filtersname,
			const FString _filtersvalue
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_calendar_create_calendar_events : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_calendar_create_calendar_events"), Category = "Moodle API Calls")
		static Ucore_calendar_create_calendar_events* core_calendar_create_calendar_events(
			const FString ServerURL,
			const FString Token,
			const FString _eventsname,
			const FString _eventsdescription = "null",
			const int32 _eventsformat = 1,
			const int32 _eventscourseid = 0,
			const int32 _eventsgroupid = 0,
			const int32 _eventsrepeats = 0,
			const FString _eventseventtype = "user",
			const int32 _eventstimestart = 1679916993,
			const int32 _eventstimeduration = 0,
			const int32 _eventsvisible = 1,
			const int32 _eventssequence = 1
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_calendar_delete_calendar_events : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_calendar_delete_calendar_events"), Category = "Moodle API Calls")
		static Ucore_calendar_delete_calendar_events* core_calendar_delete_calendar_events(
			const FString ServerURL,
			const FString Token,
			const int32 _eventseventid,
			const int32 _eventsrepeat
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_calendar_delete_subscription : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_calendar_delete_subscription"), Category = "Moodle API Calls")
		static Ucore_calendar_delete_subscription* core_calendar_delete_subscription(
			const FString ServerURL,
			const FString Token,
			const int32 _subscriptionid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_calendar_get_action_events_by_course : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_calendar_get_action_events_by_course"), Category = "Moodle API Calls")
		static Ucore_calendar_get_action_events_by_course* core_calendar_get_action_events_by_course(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _timesortfrom = 0,
			const int32 _timesortto = 0,
			const int32 _aftereventid = 0,
			const int32 _limitnum = 20,
			const FString _searchvalue = "null"
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_calendar_get_action_events_by_courses : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_calendar_get_action_events_by_courses"), Category = "Moodle API Calls")
		static Ucore_calendar_get_action_events_by_courses* core_calendar_get_action_events_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids,
			const int32 _timesortfrom = 0,
			const int32 _timesortto = 0,
			const int32 _limitnum = 10,
			const FString _searchvalue = "null"
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_calendar_get_action_events_by_timesort : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_calendar_get_action_events_by_timesort"), Category = "Moodle API Calls")
		static Ucore_calendar_get_action_events_by_timesort* core_calendar_get_action_events_by_timesort(
			const FString ServerURL,
			const FString Token,
			const int32 _timesortfrom = 0,
			const int32 _timesortto = 0,
			const int32 _aftereventid = 0,
			const int32 _limitnum = 20,
			const int32 _limittononsuspendedevents = 0,
			const int32 _userid = 0,
			const FString _searchvalue = "null"
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_calendar_get_allowed_event_types : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_calendar_get_allowed_event_types"), Category = "Moodle API Calls")
		static Ucore_calendar_get_allowed_event_types* core_calendar_get_allowed_event_types(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_calendar_get_calendar_access_information : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_calendar_get_calendar_access_information"), Category = "Moodle API Calls")
		static Ucore_calendar_get_calendar_access_information* core_calendar_get_calendar_access_information(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_calendar_get_calendar_day_view : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_calendar_get_calendar_day_view"), Category = "Moodle API Calls")
		static Ucore_calendar_get_calendar_day_view* core_calendar_get_calendar_day_view(
			const FString ServerURL,
			const FString Token,
			const int32 _year,
			const int32 _month,
			const int32 _day,
			const int32 _courseid = 1,
			const int32 _categoryid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_calendar_get_calendar_event_by_id : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_calendar_get_calendar_event_by_id"), Category = "Moodle API Calls")
		static Ucore_calendar_get_calendar_event_by_id* core_calendar_get_calendar_event_by_id(
			const FString ServerURL,
			const FString Token,
			const int32 _eventid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_calendar_get_calendar_events : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_calendar_get_calendar_events"), Category = "Moodle API Calls")
		static Ucore_calendar_get_calendar_events* core_calendar_get_calendar_events(
			const FString ServerURL,
			const FString Token,
			const int32 _eventscourseids,
			const int32 _eventsgroupids,
			const int32 _eventscategoryids,
			const int32 _eventseventids = 0,
			const int32 _optionsuserevents = 1,
			const int32 _optionssiteevents = 1,
			const int32 _optionstimestart = 0,
			const int32 _optionstimeend = 0,
			const int32 _optionsignorehidden = 1
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_calendar_get_calendar_export_token : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_calendar_get_calendar_export_token"), Category = "Moodle API Calls")
		static Ucore_calendar_get_calendar_export_token* core_calendar_get_calendar_export_token(
			const FString ServerURL,
			const FString Token
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_calendar_get_calendar_monthly_view : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_calendar_get_calendar_monthly_view"), Category = "Moodle API Calls")
		static Ucore_calendar_get_calendar_monthly_view* core_calendar_get_calendar_monthly_view(
			const FString ServerURL,
			const FString Token,
			const int32 _year,
			const int32 _month,
			const int32 _courseid = 1,
			const int32 _categoryid = 0,
			const int32 _includenavigation = 1,
			const int32 _mini = 0,
			const int32 _day = 1,
			const FString _view = "month"
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_calendar_get_calendar_upcoming_view : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_calendar_get_calendar_upcoming_view"), Category = "Moodle API Calls")
		static Ucore_calendar_get_calendar_upcoming_view* core_calendar_get_calendar_upcoming_view(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid = 1,
			const int32 _categoryid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_calendar_get_timestamps : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_calendar_get_timestamps"), Category = "Moodle API Calls")
		static Ucore_calendar_get_timestamps* core_calendar_get_timestamps(
			const FString ServerURL,
			const FString Token,
			const int32 _datayear,
			const int32 _datamonth,
			const int32 _dataday,
			const FString _datakey = "",
			const int32 _datahour = 0,
			const int32 _dataminute = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_calendar_submit_create_update_form : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_calendar_submit_create_update_form"), Category = "Moodle API Calls")
		static Ucore_calendar_submit_create_update_form* core_calendar_submit_create_update_form(
			const FString ServerURL,
			const FString Token,
			const FString _formdata
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_calendar_update_event_start_day : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_calendar_update_event_start_day"), Category = "Moodle API Calls")
		static Ucore_calendar_update_event_start_day* core_calendar_update_event_start_day(
			const FString ServerURL,
			const FString Token,
			const int32 _eventid,
			const int32 _daytimestamp
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_change_editmode : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_change_editmode"), Category = "Moodle API Calls")
		static Ucore_change_editmode* core_change_editmode(
			const FString ServerURL,
			const FString Token,
			const int32 _setmode,
			const int32 _context
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_cohort_add_cohort_members : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_cohort_add_cohort_members"), Category = "Moodle API Calls")
		static Ucore_cohort_add_cohort_members* core_cohort_add_cohort_members(
			const FString ServerURL,
			const FString Token,
			const FString _memberscohorttypetype,
			const FString _memberscohorttypevalue,
			const FString _membersusertypetype,
			const FString _membersusertypevalue
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_cohort_create_cohorts : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_cohort_create_cohorts"), Category = "Moodle API Calls")
		static Ucore_cohort_create_cohorts* core_cohort_create_cohorts(
			const FString ServerURL,
			const FString Token,
			const FString _cohortscategorytypetype,
			const FString _cohortscategorytypevalue,
			const FString _cohortsname,
			const FString _cohortsidnumber,
			const FString _cohortsdescription = "",
			const int32 _cohortsdescriptionformat = 1,
			const int32 _cohortsvisible = 0,
			const FString _cohortstheme = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_cohort_delete_cohort_members : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_cohort_delete_cohort_members"), Category = "Moodle API Calls")
		static Ucore_cohort_delete_cohort_members* core_cohort_delete_cohort_members(
			const FString ServerURL,
			const FString Token,
			const int32 _memberscohortid,
			const int32 _membersuserid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_cohort_delete_cohorts : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_cohort_delete_cohorts"), Category = "Moodle API Calls")
		static Ucore_cohort_delete_cohorts* core_cohort_delete_cohorts(
			const FString ServerURL,
			const FString Token,
			const int32 _cohortids
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_cohort_get_cohort_members : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_cohort_get_cohort_members"), Category = "Moodle API Calls")
		static Ucore_cohort_get_cohort_members* core_cohort_get_cohort_members(
			const FString ServerURL,
			const FString Token,
			const int32 _cohortids
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_cohort_get_cohorts : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_cohort_get_cohorts"), Category = "Moodle API Calls")
		static Ucore_cohort_get_cohorts* core_cohort_get_cohorts(
			const FString ServerURL,
			const FString Token,
			const int32 _cohortids = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_cohort_search_cohorts : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_cohort_search_cohorts"), Category = "Moodle API Calls")
		static Ucore_cohort_search_cohorts* core_cohort_search_cohorts(
			const FString ServerURL,
			const FString Token,
			const FString _query,
			const int32 _contextcontextid = 0,
			const FString _contextcontextlevel = "",
			const int32 _contextinstanceid = 0,
			const FString _includes = "parents",
			const int32 _limitfrom = 0,
			const int32 _limitnum = 25
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_cohort_update_cohorts : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_cohort_update_cohorts"), Category = "Moodle API Calls")
		static Ucore_cohort_update_cohorts* core_cohort_update_cohorts(
			const FString ServerURL,
			const FString Token,
			const int32 _cohortsid,
			const FString _cohortscategorytypetype,
			const FString _cohortscategorytypevalue,
			const FString _cohortsname,
			const FString _cohortsidnumber,
			const FString _cohortsdescription = "",
			const int32 _cohortsdescriptionformat = 1,
			const int32 _cohortsvisible = 0,
			const FString _cohortstheme = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_comment_add_comments : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_comment_add_comments"), Category = "Moodle API Calls")
		static Ucore_comment_add_comments* core_comment_add_comments(
			const FString ServerURL,
			const FString Token,
			const FString _commentscontextlevel,
			const int32 _commentsinstanceid,
			const FString _commentscomponent,
			const FString _commentscontent,
			const int32 _commentsitemid,
			const FString _commentsarea = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_comment_delete_comments : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_comment_delete_comments"), Category = "Moodle API Calls")
		static Ucore_comment_delete_comments* core_comment_delete_comments(
			const FString ServerURL,
			const FString Token,
			const int32 _comments
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_comment_get_comments : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_comment_get_comments"), Category = "Moodle API Calls")
		static Ucore_comment_get_comments* core_comment_get_comments(
			const FString ServerURL,
			const FString Token,
			const FString _contextlevel,
			const int32 _instanceid,
			const FString _component,
			const int32 _itemid,
			const FString _area = "",
			const int32 _page = 0,
			const FString _sortdirection = "DESC"
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_add_competency_to_course : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_add_competency_to_course"), Category = "Moodle API Calls")
		static Ucore_competency_add_competency_to_course* core_competency_add_competency_to_course(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _competencyid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_add_competency_to_plan : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_add_competency_to_plan"), Category = "Moodle API Calls")
		static Ucore_competency_add_competency_to_plan* core_competency_add_competency_to_plan(
			const FString ServerURL,
			const FString Token,
			const int32 _planid,
			const int32 _competencyid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_add_competency_to_template : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_add_competency_to_template"), Category = "Moodle API Calls")
		static Ucore_competency_add_competency_to_template* core_competency_add_competency_to_template(
			const FString ServerURL,
			const FString Token,
			const int32 _templateid,
			const int32 _competencyid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_add_related_competency : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_add_related_competency"), Category = "Moodle API Calls")
		static Ucore_competency_add_related_competency* core_competency_add_related_competency(
			const FString ServerURL,
			const FString Token,
			const int32 _competencyid,
			const int32 _relatedcompetencyid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_approve_plan : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_approve_plan"), Category = "Moodle API Calls")
		static Ucore_competency_approve_plan* core_competency_approve_plan(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_competency_framework_viewed : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_competency_framework_viewed"), Category = "Moodle API Calls")
		static Ucore_competency_competency_framework_viewed* core_competency_competency_framework_viewed(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_competency_viewed : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_competency_viewed"), Category = "Moodle API Calls")
		static Ucore_competency_competency_viewed* core_competency_competency_viewed(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_complete_plan : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_complete_plan"), Category = "Moodle API Calls")
		static Ucore_competency_complete_plan* core_competency_complete_plan(
			const FString ServerURL,
			const FString Token,
			const int32 _planid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_count_competencies : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_count_competencies"), Category = "Moodle API Calls")
		static Ucore_competency_count_competencies* core_competency_count_competencies(
			const FString ServerURL,
			const FString Token,
			const FString _filterscolumn,
			const FString _filtersvalue
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_count_competencies_in_course : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_count_competencies_in_course"), Category = "Moodle API Calls")
		static Ucore_competency_count_competencies_in_course* core_competency_count_competencies_in_course(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_count_competencies_in_template : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_count_competencies_in_template"), Category = "Moodle API Calls")
		static Ucore_competency_count_competencies_in_template* core_competency_count_competencies_in_template(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_count_competency_frameworks : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_count_competency_frameworks"), Category = "Moodle API Calls")
		static Ucore_competency_count_competency_frameworks* core_competency_count_competency_frameworks(
			const FString ServerURL,
			const FString Token,
			const int32 _contextcontextid = 0,
			const FString _contextcontextlevel = "",
			const int32 _contextinstanceid = 0,
			const FString _includes = "children"
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_count_course_module_competencies : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_count_course_module_competencies"), Category = "Moodle API Calls")
		static Ucore_competency_count_course_module_competencies* core_competency_count_course_module_competencies(
			const FString ServerURL,
			const FString Token,
			const int32 _cmid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_count_courses_using_competency : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_count_courses_using_competency"), Category = "Moodle API Calls")
		static Ucore_competency_count_courses_using_competency* core_competency_count_courses_using_competency(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_count_templates : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_count_templates"), Category = "Moodle API Calls")
		static Ucore_competency_count_templates* core_competency_count_templates(
			const FString ServerURL,
			const FString Token,
			const int32 _contextcontextid = 0,
			const FString _contextcontextlevel = "",
			const int32 _contextinstanceid = 0,
			const FString _includes = "children"
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_count_templates_using_competency : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_count_templates_using_competency"), Category = "Moodle API Calls")
		static Ucore_competency_count_templates_using_competency* core_competency_count_templates_using_competency(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_create_competency : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_create_competency"), Category = "Moodle API Calls")
		static Ucore_competency_create_competency* core_competency_create_competency(
			const FString ServerURL,
			const FString Token,
			const FString _competencyshortname,
			const FString _competencyidnumber,
			const FString _competencydescription = "1",
			const int32 _competencydescriptionformat = 1,
			const int32 _competencysortorder = 0,
			const int32 _competencyparentid = 0,
			const FString _competencypath = "/0/",
			const int32 _competencyruleoutcome = 0,
			const FString _competencyruletype = "null",
			const FString _competencyruleconfig = "null",
			const int32 _competencyscaleid = 0,
			const FString _competencyscaleconfiguration = "null",
			const int32 _competencycompetencyframeworkid = 0,
			const int32 _competencytimecreated = 0,
			const int32 _competencytimemodified = 0,
			const int32 _competencyusermodified = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_create_competency_framework : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_create_competency_framework"), Category = "Moodle API Calls")
		static Ucore_competency_create_competency_framework* core_competency_create_competency_framework(
			const FString ServerURL,
			const FString Token,
			const FString _competencyframeworkshortname,
			const FString _competencyframeworkidnumber,
			const int32 _competencyframeworkscaleid,
			const FString _competencyframeworkscaleconfiguration,
			const FString _competencyframeworkdescription = "1",
			const int32 _competencyframeworkdescriptionformat = 1,
			const int32 _competencyframeworkvisible = 1,
			const int32 _competencyframeworkcontextid = 0,
			const FString _competencyframeworkcontextlevel = "",
			const int32 _competencyframeworkinstanceid = 0,
			const FString _competencyframeworktaxonomies = "",
			const int32 _competencyframeworktimecreated = 0,
			const int32 _competencyframeworktimemodified = 0,
			const int32 _competencyframeworkusermodified = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_create_plan : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_create_plan"), Category = "Moodle API Calls")
		static Ucore_competency_create_plan* core_competency_create_plan(
			const FString ServerURL,
			const FString Token,
			const FString _planname,
			const int32 _planuserid,
			const FString _plandescription = "1",
			const int32 _plandescriptionformat = 1,
			const int32 _plantemplateid = 0,
			const int32 _planorigtemplateid = 0,
			const int32 _planstatus = 0,
			const int32 _planduedate = 0,
			const int32 _planreviewerid = 0,
			const int32 _plantimecreated = 0,
			const int32 _plantimemodified = 0,
			const int32 _planusermodified = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_create_template : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_create_template"), Category = "Moodle API Calls")
		static Ucore_competency_create_template* core_competency_create_template(
			const FString ServerURL,
			const FString Token,
			const FString _templateshortname,
			const FString _templatedescription = "1",
			const int32 _templatedescriptionformat = 1,
			const int32 _templateduedate = 0,
			const int32 _templatevisible = 1,
			const int32 _templatecontextid = 0,
			const FString _templatecontextlevel = "",
			const int32 _templateinstanceid = 0,
			const int32 _templatetimecreated = 0,
			const int32 _templatetimemodified = 0,
			const int32 _templateusermodified = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_create_user_evidence_competency : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_create_user_evidence_competency"), Category = "Moodle API Calls")
		static Ucore_competency_create_user_evidence_competency* core_competency_create_user_evidence_competency(
			const FString ServerURL,
			const FString Token,
			const int32 _userevidenceid,
			const int32 _competencyid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_delete_competency : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_delete_competency"), Category = "Moodle API Calls")
		static Ucore_competency_delete_competency* core_competency_delete_competency(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_delete_competency_framework : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_delete_competency_framework"), Category = "Moodle API Calls")
		static Ucore_competency_delete_competency_framework* core_competency_delete_competency_framework(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_delete_evidence : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_delete_evidence"), Category = "Moodle API Calls")
		static Ucore_competency_delete_evidence* core_competency_delete_evidence(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_delete_plan : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_delete_plan"), Category = "Moodle API Calls")
		static Ucore_competency_delete_plan* core_competency_delete_plan(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_delete_template : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_delete_template"), Category = "Moodle API Calls")
		static Ucore_competency_delete_template* core_competency_delete_template(
			const FString ServerURL,
			const FString Token,
			const int32 _id,
			const int32 _deleteplans
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_delete_user_evidence : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_delete_user_evidence"), Category = "Moodle API Calls")
		static Ucore_competency_delete_user_evidence* core_competency_delete_user_evidence(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_delete_user_evidence_competency : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_delete_user_evidence_competency"), Category = "Moodle API Calls")
		static Ucore_competency_delete_user_evidence_competency* core_competency_delete_user_evidence_competency(
			const FString ServerURL,
			const FString Token,
			const int32 _userevidenceid,
			const int32 _competencyid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_duplicate_competency_framework : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_duplicate_competency_framework"), Category = "Moodle API Calls")
		static Ucore_competency_duplicate_competency_framework* core_competency_duplicate_competency_framework(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_duplicate_template : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_duplicate_template"), Category = "Moodle API Calls")
		static Ucore_competency_duplicate_template* core_competency_duplicate_template(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_get_scale_values : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_get_scale_values"), Category = "Moodle API Calls")
		static Ucore_competency_get_scale_values* core_competency_get_scale_values(
			const FString ServerURL,
			const FString Token,
			const int32 _scaleid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_grade_competency : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_grade_competency"), Category = "Moodle API Calls")
		static Ucore_competency_grade_competency* core_competency_grade_competency(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _competencyid,
			const int32 _grade,
			const FString _note = "null"
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_grade_competency_in_course : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_grade_competency_in_course"), Category = "Moodle API Calls")
		static Ucore_competency_grade_competency_in_course* core_competency_grade_competency_in_course(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _userid,
			const int32 _competencyid,
			const int32 _grade,
			const FString _note = "null"
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_grade_competency_in_plan : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_grade_competency_in_plan"), Category = "Moodle API Calls")
		static Ucore_competency_grade_competency_in_plan* core_competency_grade_competency_in_plan(
			const FString ServerURL,
			const FString Token,
			const int32 _planid,
			const int32 _competencyid,
			const int32 _grade,
			const FString _note = "null"
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_list_competencies : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_list_competencies"), Category = "Moodle API Calls")
		static Ucore_competency_list_competencies* core_competency_list_competencies(
			const FString ServerURL,
			const FString Token,
			const FString _filterscolumn,
			const FString _filtersvalue,
			const FString _sort = "",
			const FString _order = "",
			const int32 _skip = 0,
			const int32 _limit = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_list_competencies_in_template : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_list_competencies_in_template"), Category = "Moodle API Calls")
		static Ucore_competency_list_competencies_in_template* core_competency_list_competencies_in_template(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_list_competency_frameworks : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_list_competency_frameworks"), Category = "Moodle API Calls")
		static Ucore_competency_list_competency_frameworks* core_competency_list_competency_frameworks(
			const FString ServerURL,
			const FString Token,
			const FString _sort = "shortname",
			const FString _order = "",
			const int32 _skip = 0,
			const int32 _limit = 0,
			const int32 _contextcontextid = 0,
			const FString _contextcontextlevel = "",
			const int32 _contextinstanceid = 0,
			const FString _includes = "children",
			const int32 _onlyvisible = 0,
			const FString _query = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_list_course_competencies : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_list_course_competencies"), Category = "Moodle API Calls")
		static Ucore_competency_list_course_competencies* core_competency_list_course_competencies(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_list_course_module_competencies : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_list_course_module_competencies"), Category = "Moodle API Calls")
		static Ucore_competency_list_course_module_competencies* core_competency_list_course_module_competencies(
			const FString ServerURL,
			const FString Token,
			const int32 _cmid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_list_plan_competencies : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_list_plan_competencies"), Category = "Moodle API Calls")
		static Ucore_competency_list_plan_competencies* core_competency_list_plan_competencies(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_list_templates : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_list_templates"), Category = "Moodle API Calls")
		static Ucore_competency_list_templates* core_competency_list_templates(
			const FString ServerURL,
			const FString Token,
			const FString _sort = "",
			const FString _order = "",
			const int32 _skip = 0,
			const int32 _limit = 0,
			const int32 _contextcontextid = 0,
			const FString _contextcontextlevel = "",
			const int32 _contextinstanceid = 0,
			const FString _includes = "children",
			const int32 _onlyvisible = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_list_templates_using_competency : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_list_templates_using_competency"), Category = "Moodle API Calls")
		static Ucore_competency_list_templates_using_competency* core_competency_list_templates_using_competency(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_list_user_plans : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_list_user_plans"), Category = "Moodle API Calls")
		static Ucore_competency_list_user_plans* core_competency_list_user_plans(
			const FString ServerURL,
			const FString Token,
			const int32 _userid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_move_down_competency : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_move_down_competency"), Category = "Moodle API Calls")
		static Ucore_competency_move_down_competency* core_competency_move_down_competency(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_move_up_competency : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_move_up_competency"), Category = "Moodle API Calls")
		static Ucore_competency_move_up_competency* core_competency_move_up_competency(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_plan_cancel_review_request : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_plan_cancel_review_request"), Category = "Moodle API Calls")
		static Ucore_competency_plan_cancel_review_request* core_competency_plan_cancel_review_request(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_plan_request_review : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_plan_request_review"), Category = "Moodle API Calls")
		static Ucore_competency_plan_request_review* core_competency_plan_request_review(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_plan_start_review : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_plan_start_review"), Category = "Moodle API Calls")
		static Ucore_competency_plan_start_review* core_competency_plan_start_review(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_plan_stop_review : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_plan_stop_review"), Category = "Moodle API Calls")
		static Ucore_competency_plan_stop_review* core_competency_plan_stop_review(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_read_competency : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_read_competency"), Category = "Moodle API Calls")
		static Ucore_competency_read_competency* core_competency_read_competency(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_read_competency_framework : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_read_competency_framework"), Category = "Moodle API Calls")
		static Ucore_competency_read_competency_framework* core_competency_read_competency_framework(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_read_plan : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_read_plan"), Category = "Moodle API Calls")
		static Ucore_competency_read_plan* core_competency_read_plan(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_read_template : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_read_template"), Category = "Moodle API Calls")
		static Ucore_competency_read_template* core_competency_read_template(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_read_user_evidence : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_read_user_evidence"), Category = "Moodle API Calls")
		static Ucore_competency_read_user_evidence* core_competency_read_user_evidence(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_remove_competency_from_course : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_remove_competency_from_course"), Category = "Moodle API Calls")
		static Ucore_competency_remove_competency_from_course* core_competency_remove_competency_from_course(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _competencyid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_remove_competency_from_plan : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_remove_competency_from_plan"), Category = "Moodle API Calls")
		static Ucore_competency_remove_competency_from_plan* core_competency_remove_competency_from_plan(
			const FString ServerURL,
			const FString Token,
			const int32 _planid,
			const int32 _competencyid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_remove_competency_from_template : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_remove_competency_from_template"), Category = "Moodle API Calls")
		static Ucore_competency_remove_competency_from_template* core_competency_remove_competency_from_template(
			const FString ServerURL,
			const FString Token,
			const int32 _templateid,
			const int32 _competencyid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_remove_related_competency : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_remove_related_competency"), Category = "Moodle API Calls")
		static Ucore_competency_remove_related_competency* core_competency_remove_related_competency(
			const FString ServerURL,
			const FString Token,
			const int32 _competencyid,
			const int32 _relatedcompetencyid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_reopen_plan : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_reopen_plan"), Category = "Moodle API Calls")
		static Ucore_competency_reopen_plan* core_competency_reopen_plan(
			const FString ServerURL,
			const FString Token,
			const int32 _planid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_reorder_course_competency : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_reorder_course_competency"), Category = "Moodle API Calls")
		static Ucore_competency_reorder_course_competency* core_competency_reorder_course_competency(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _competencyidfrom,
			const int32 _competencyidto
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_reorder_plan_competency : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_reorder_plan_competency"), Category = "Moodle API Calls")
		static Ucore_competency_reorder_plan_competency* core_competency_reorder_plan_competency(
			const FString ServerURL,
			const FString Token,
			const int32 _planid,
			const int32 _competencyidfrom,
			const int32 _competencyidto
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_reorder_template_competency : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_reorder_template_competency"), Category = "Moodle API Calls")
		static Ucore_competency_reorder_template_competency* core_competency_reorder_template_competency(
			const FString ServerURL,
			const FString Token,
			const int32 _templateid,
			const int32 _competencyidfrom,
			const int32 _competencyidto
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_request_review_of_user_evidence_linked_competencies : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_request_review_of_user_evidence_linked_competencies"), Category = "Moodle API Calls")
		static Ucore_competency_request_review_of_user_evidence_linked_competencies* core_competency_request_review_of_user_evidence_linked_competencies(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_search_competencies : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_search_competencies"), Category = "Moodle API Calls")
		static Ucore_competency_search_competencies* core_competency_search_competencies(
			const FString ServerURL,
			const FString Token,
			const FString _searchtext,
			const int32 _competencyframeworkid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_set_course_competency_ruleoutcome : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_set_course_competency_ruleoutcome"), Category = "Moodle API Calls")
		static Ucore_competency_set_course_competency_ruleoutcome* core_competency_set_course_competency_ruleoutcome(
			const FString ServerURL,
			const FString Token,
			const int32 _coursecompetencyid,
			const int32 _ruleoutcome
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_set_parent_competency : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_set_parent_competency"), Category = "Moodle API Calls")
		static Ucore_competency_set_parent_competency* core_competency_set_parent_competency(
			const FString ServerURL,
			const FString Token,
			const int32 _competencyid,
			const int32 _parentid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_template_has_related_data : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_template_has_related_data"), Category = "Moodle API Calls")
		static Ucore_competency_template_has_related_data* core_competency_template_has_related_data(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_template_viewed : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_template_viewed"), Category = "Moodle API Calls")
		static Ucore_competency_template_viewed* core_competency_template_viewed(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_unapprove_plan : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_unapprove_plan"), Category = "Moodle API Calls")
		static Ucore_competency_unapprove_plan* core_competency_unapprove_plan(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_unlink_plan_from_template : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_unlink_plan_from_template"), Category = "Moodle API Calls")
		static Ucore_competency_unlink_plan_from_template* core_competency_unlink_plan_from_template(
			const FString ServerURL,
			const FString Token,
			const int32 _planid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_update_competency : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_update_competency"), Category = "Moodle API Calls")
		static Ucore_competency_update_competency* core_competency_update_competency(
			const FString ServerURL,
			const FString Token,
			const FString _competencyshortname = "",
			const FString _competencyidnumber = "",
			const FString _competencydescription = "",
			const int32 _competencydescriptionformat = 0,
			const int32 _competencysortorder = 0,
			const int32 _competencyparentid = 0,
			const FString _competencypath = "",
			const int32 _competencyruleoutcome = 0,
			const FString _competencyruletype = "",
			const FString _competencyruleconfig = "",
			const int32 _competencyscaleid = 0,
			const FString _competencyscaleconfiguration = "",
			const int32 _competencycompetencyframeworkid = 0,
			const int32 _competencyid = 0,
			const int32 _competencytimecreated = 0,
			const int32 _competencytimemodified = 0,
			const int32 _competencyusermodified = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_update_competency_framework : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_update_competency_framework"), Category = "Moodle API Calls")
		static Ucore_competency_update_competency_framework* core_competency_update_competency_framework(
			const FString ServerURL,
			const FString Token,
			const FString _competencyframeworkshortname = "",
			const FString _competencyframeworkidnumber = "",
			const FString _competencyframeworkdescription = "",
			const int32 _competencyframeworkdescriptionformat = 1,
			const int32 _competencyframeworkvisible = 0,
			const int32 _competencyframeworkscaleid = 0,
			const FString _competencyframeworkscaleconfiguration = "",
			const int32 _competencyframeworkcontextid = 0,
			const FString _competencyframeworkcontextlevel = "",
			const int32 _competencyframeworkinstanceid = 0,
			const FString _competencyframeworktaxonomies = "",
			const int32 _competencyframeworkid = 0,
			const int32 _competencyframeworktimecreated = 0,
			const int32 _competencyframeworktimemodified = 0,
			const int32 _competencyframeworkusermodified = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_update_course_competency_settings : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_update_course_competency_settings"), Category = "Moodle API Calls")
		static Ucore_competency_update_course_competency_settings* core_competency_update_course_competency_settings(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _settingspushratingstouserplans
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_update_plan : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_update_plan"), Category = "Moodle API Calls")
		static Ucore_competency_update_plan* core_competency_update_plan(
			const FString ServerURL,
			const FString Token,
			const FString _planname = "",
			const FString _plandescription = "",
			const int32 _plandescriptionformat = 1,
			const int32 _planuserid = 0,
			const int32 _plantemplateid = 0,
			const int32 _planorigtemplateid = 0,
			const int32 _planstatus = 0,
			const int32 _planduedate = 0,
			const int32 _planreviewerid = 0,
			const int32 _planid = 0,
			const int32 _plantimecreated = 0,
			const int32 _plantimemodified = 0,
			const int32 _planusermodified = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_update_template : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_update_template"), Category = "Moodle API Calls")
		static Ucore_competency_update_template* core_competency_update_template(
			const FString ServerURL,
			const FString Token,
			const FString _templateshortname = "",
			const FString _templatedescription = "",
			const int32 _templatedescriptionformat = 1,
			const int32 _templateduedate = 0,
			const int32 _templatevisible = 0,
			const int32 _templatecontextid = 0,
			const FString _templatecontextlevel = "",
			const int32 _templateinstanceid = 0,
			const int32 _templateid = 0,
			const int32 _templatetimecreated = 0,
			const int32 _templatetimemodified = 0,
			const int32 _templateusermodified = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_user_competency_cancel_review_request : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_user_competency_cancel_review_request"), Category = "Moodle API Calls")
		static Ucore_competency_user_competency_cancel_review_request* core_competency_user_competency_cancel_review_request(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _competencyid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_user_competency_plan_viewed : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_user_competency_plan_viewed"), Category = "Moodle API Calls")
		static Ucore_competency_user_competency_plan_viewed* core_competency_user_competency_plan_viewed(
			const FString ServerURL,
			const FString Token,
			const int32 _competencyid,
			const int32 _userid,
			const int32 _planid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_user_competency_request_review : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_user_competency_request_review"), Category = "Moodle API Calls")
		static Ucore_competency_user_competency_request_review* core_competency_user_competency_request_review(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _competencyid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_user_competency_start_review : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_user_competency_start_review"), Category = "Moodle API Calls")
		static Ucore_competency_user_competency_start_review* core_competency_user_competency_start_review(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _competencyid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_user_competency_stop_review : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_user_competency_stop_review"), Category = "Moodle API Calls")
		static Ucore_competency_user_competency_stop_review* core_competency_user_competency_stop_review(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _competencyid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_user_competency_viewed : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_user_competency_viewed"), Category = "Moodle API Calls")
		static Ucore_competency_user_competency_viewed* core_competency_user_competency_viewed(
			const FString ServerURL,
			const FString Token,
			const int32 _usercompetencyid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_user_competency_viewed_in_course : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_user_competency_viewed_in_course"), Category = "Moodle API Calls")
		static Ucore_competency_user_competency_viewed_in_course* core_competency_user_competency_viewed_in_course(
			const FString ServerURL,
			const FString Token,
			const int32 _competencyid,
			const int32 _userid,
			const int32 _courseid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_competency_user_competency_viewed_in_plan : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_competency_user_competency_viewed_in_plan"), Category = "Moodle API Calls")
		static Ucore_competency_user_competency_viewed_in_plan* core_competency_user_competency_viewed_in_plan(
			const FString ServerURL,
			const FString Token,
			const int32 _competencyid,
			const int32 _userid,
			const int32 _planid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_completion_get_activities_completion_status : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_completion_get_activities_completion_status"), Category = "Moodle API Calls")
		static Ucore_completion_get_activities_completion_status* core_completion_get_activities_completion_status(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _userid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_completion_get_course_completion_status : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_completion_get_course_completion_status"), Category = "Moodle API Calls")
		static Ucore_completion_get_course_completion_status* core_completion_get_course_completion_status(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _userid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_completion_mark_course_self_completed : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_completion_mark_course_self_completed"), Category = "Moodle API Calls")
		static Ucore_completion_mark_course_self_completed* core_completion_mark_course_self_completed(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_completion_override_activity_completion_status : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_completion_override_activity_completion_status"), Category = "Moodle API Calls")
		static Ucore_completion_override_activity_completion_status* core_completion_override_activity_completion_status(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _cmid,
			const int32 _newstate
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_completion_update_activity_completion_status_manually : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_completion_update_activity_completion_status_manually"), Category = "Moodle API Calls")
		static Ucore_completion_update_activity_completion_status_manually* core_completion_update_activity_completion_status_manually(
			const FString ServerURL,
			const FString Token,
			const int32 _cmid,
			const int32 _completed
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_contentbank_delete_content : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_contentbank_delete_content"), Category = "Moodle API Calls")
		static Ucore_contentbank_delete_content* core_contentbank_delete_content(
			const FString ServerURL,
			const FString Token,
			const int32 _contentids
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_contentbank_rename_content : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_contentbank_rename_content"), Category = "Moodle API Calls")
		static Ucore_contentbank_rename_content* core_contentbank_rename_content(
			const FString ServerURL,
			const FString Token,
			const int32 _contentid,
			const FString _name
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_contentbank_set_content_visibility : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_contentbank_set_content_visibility"), Category = "Moodle API Calls")
		static Ucore_contentbank_set_content_visibility* core_contentbank_set_content_visibility(
			const FString ServerURL,
			const FString Token,
			const int32 _contentid,
			const int32 _visibility
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_course_add_content_item_to_user_favourites : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_course_add_content_item_to_user_favourites"), Category = "Moodle API Calls")
		static Ucore_course_add_content_item_to_user_favourites* core_course_add_content_item_to_user_favourites(
			const FString ServerURL,
			const FString Token,
			const FString _componentname,
			const int32 _contentitemid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_course_check_updates : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_course_check_updates"), Category = "Moodle API Calls")
		static Ucore_course_check_updates* core_course_check_updates(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const FString _tocheckcontextlevel,
			const int32 _tocheckid,
			const int32 _tochecksince,
			const FString _filter = "Array ( ) "
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_course_create_categories : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_course_create_categories"), Category = "Moodle API Calls")
		static Ucore_course_create_categories* core_course_create_categories(
			const FString ServerURL,
			const FString Token,
			const FString _categoriesname,
			const int32 _categoriesparent = 0,
			const FString _categoriesidnumber = "",
			const FString _categoriesdescription = "",
			const int32 _categoriesdescriptionformat = 1,
			const FString _categoriestheme = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_course_create_courses : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_course_create_courses"), Category = "Moodle API Calls")
		static Ucore_course_create_courses* core_course_create_courses(
			const FString ServerURL,
			const FString Token,
			const FString _coursesfullname,
			const FString _coursesshortname,
			const int32 _coursescategoryid,
			const FString _coursesidnumber = "",
			const FString _coursessummary = "",
			const int32 _coursessummaryformat = 1,
			const FString _coursesformat = "",
			const int32 _coursesshowgrades = 1,
			const int32 _coursesnewsitems = 5,
			const int32 _coursesstartdate = 0,
			const int32 _coursesenddate = 0,
			const int32 _coursesnumsections = 0,
			const int32 _coursesmaxbytes = 0,
			const int32 _coursesshowreports = 0,
			const int32 _coursesvisible = 0,
			const int32 _courseshiddensections = 0,
			const int32 _coursesgroupmode = 0,
			const int32 _coursesgroupmodeforce = 0,
			const int32 _coursesdefaultgroupingid = 0,
			const int32 _coursesenablecompletion = 0,
			const int32 _coursescompletionnotify = 0,
			const FString _courseslang = "",
			const FString _coursesforcetheme = "",
			const FString _coursescourseformatoptionsname = "",
			const FString _coursescourseformatoptionsvalue = "",
			const FString _coursescustomfieldsshortname = "",
			const FString _coursescustomfieldsvalue = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_course_delete_categories : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_course_delete_categories"), Category = "Moodle API Calls")
		static Ucore_course_delete_categories* core_course_delete_categories(
			const FString ServerURL,
			const FString Token,
			const int32 _categoriesid,
			const int32 _categoriesnewparent = 0,
			const int32 _categoriesrecursive = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_course_delete_courses : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_course_delete_courses"), Category = "Moodle API Calls")
		static Ucore_course_delete_courses* core_course_delete_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_course_delete_modules : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_course_delete_modules"), Category = "Moodle API Calls")
		static Ucore_course_delete_modules* core_course_delete_modules(
			const FString ServerURL,
			const FString Token,
			const int32 _cmids
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_course_duplicate_course : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_course_duplicate_course"), Category = "Moodle API Calls")
		static Ucore_course_duplicate_course* core_course_duplicate_course(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const FString _fullname,
			const FString _shortname,
			const int32 _categoryid,
			const FString _optionsname,
			const FString _optionsvalue,
			const int32 _visible = 1
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_course_edit_module : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_course_edit_module"), Category = "Moodle API Calls")
		static Ucore_course_edit_module* core_course_edit_module(
			const FString ServerURL,
			const FString Token,
			const FString _action,
			const int32 _id,
			const int32 _sectionreturn = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_course_edit_section : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_course_edit_section"), Category = "Moodle API Calls")
		static Ucore_course_edit_section* core_course_edit_section(
			const FString ServerURL,
			const FString Token,
			const FString _action,
			const int32 _id,
			const int32 _sectionreturn = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_course_get_activity_chooser_footer : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_course_get_activity_chooser_footer"), Category = "Moodle API Calls")
		static Ucore_course_get_activity_chooser_footer* core_course_get_activity_chooser_footer(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _sectionid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_course_get_categories : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_course_get_categories"), Category = "Moodle API Calls")
		static Ucore_course_get_categories* core_course_get_categories(
			const FString ServerURL,
			const FString Token,
			const FString _criteriakey,
			const FString _criteriavalue,
			const int32 _addsubcategories = 1
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_course_get_contents : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_course_get_contents"), Category = "Moodle API Calls")
		static Ucore_course_get_contents* core_course_get_contents(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const FString _optionsname,
			const FString _optionsvalue
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_course_get_course_content_items : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_course_get_course_content_items"), Category = "Moodle API Calls")
		static Ucore_course_get_course_content_items* core_course_get_course_content_items(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_course_get_course_module : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_course_get_course_module"), Category = "Moodle API Calls")
		static Ucore_course_get_course_module* core_course_get_course_module(
			const FString ServerURL,
			const FString Token,
			const int32 _cmid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_course_get_course_module_by_instance : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_course_get_course_module_by_instance"), Category = "Moodle API Calls")
		static Ucore_course_get_course_module_by_instance* core_course_get_course_module_by_instance(
			const FString ServerURL,
			const FString Token,
			const FString _module,
			const int32 _instance
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_course_get_courses : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_course_get_courses"), Category = "Moodle API Calls")
		static Ucore_course_get_courses* core_course_get_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _optionsids = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_course_get_courses_by_field : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_course_get_courses_by_field"), Category = "Moodle API Calls")
		static Ucore_course_get_courses_by_field* core_course_get_courses_by_field(
			const FString ServerURL,
			const FString Token,
			const FString _field = "",
			const FString _value = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_course_get_enrolled_courses_by_timeline_classification : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_course_get_enrolled_courses_by_timeline_classification"), Category = "Moodle API Calls")
		static Ucore_course_get_enrolled_courses_by_timeline_classification* core_course_get_enrolled_courses_by_timeline_classification(
			const FString ServerURL,
			const FString Token,
			const FString _classification,
			const int32 _limit = 0,
			const int32 _offset = 0,
			const FString _sort = "null",
			const FString _customfieldname = "null",
			const FString _customfieldvalue = "null",
			const FString _searchvalue = "null"
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_course_get_enrolled_courses_with_action_events_by_timeline_classification : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_course_get_enrolled_courses_with_action_events_by_timeline_classification"), Category = "Moodle API Calls")
		static Ucore_course_get_enrolled_courses_with_action_events_by_timeline_classification* core_course_get_enrolled_courses_with_action_events_by_timeline_classification(
			const FString ServerURL,
			const FString Token,
			const FString _classification,
			const int32 _limit = 0,
			const int32 _offset = 0,
			const FString _sort = "null",
			const FString _customfieldname = "null",
			const FString _customfieldvalue = "null",
			const FString _searchvalue = "null",
			const int32 _eventsfrom = 0,
			const int32 _eventsto = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_course_get_enrolled_users_by_cmid : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_course_get_enrolled_users_by_cmid"), Category = "Moodle API Calls")
		static Ucore_course_get_enrolled_users_by_cmid* core_course_get_enrolled_users_by_cmid(
			const FString ServerURL,
			const FString Token,
			const int32 _cmid,
			const int32 _groupid = 0,
			const int32 _onlyactive = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_course_get_module : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_course_get_module"), Category = "Moodle API Calls")
		static Ucore_course_get_module* core_course_get_module(
			const FString ServerURL,
			const FString Token,
			const int32 _id,
			const int32 _sectionreturn = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_course_get_recent_courses : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_course_get_recent_courses"), Category = "Moodle API Calls")
		static Ucore_course_get_recent_courses* core_course_get_recent_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _userid = 0,
			const int32 _limit = 0,
			const int32 _offset = 0,
			const FString _sort = "null"
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_course_get_updates_since : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_course_get_updates_since"), Category = "Moodle API Calls")
		static Ucore_course_get_updates_since* core_course_get_updates_since(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _since,
			const FString _filter = "Array ( ) "
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_course_get_user_administration_options : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_course_get_user_administration_options"), Category = "Moodle API Calls")
		static Ucore_course_get_user_administration_options* core_course_get_user_administration_options(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_course_get_user_navigation_options : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_course_get_user_navigation_options"), Category = "Moodle API Calls")
		static Ucore_course_get_user_navigation_options* core_course_get_user_navigation_options(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_course_import_course : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_course_import_course"), Category = "Moodle API Calls")
		static Ucore_course_import_course* core_course_import_course(
			const FString ServerURL,
			const FString Token,
			const int32 _importfrom,
			const int32 _importto,
			const FString _optionsname,
			const FString _optionsvalue,
			const int32 _deletecontent = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_course_remove_content_item_from_user_favourites : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_course_remove_content_item_from_user_favourites"), Category = "Moodle API Calls")
		static Ucore_course_remove_content_item_from_user_favourites* core_course_remove_content_item_from_user_favourites(
			const FString ServerURL,
			const FString Token,
			const FString _componentname,
			const int32 _contentitemid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_course_search_courses : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_course_search_courses"), Category = "Moodle API Calls")
		static Ucore_course_search_courses* core_course_search_courses(
			const FString ServerURL,
			const FString Token,
			const FString _criterianame,
			const FString _criteriavalue,
			const int32 _page = 0,
			const int32 _perpage = 0,
			const FString _requiredcapabilities = "Array ( ) ",
			const int32 _limittoenrolled = 0,
			const int32 _onlywithcompletion = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_course_set_favourite_courses : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_course_set_favourite_courses"), Category = "Moodle API Calls")
		static Ucore_course_set_favourite_courses* core_course_set_favourite_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _coursesid,
			const int32 _coursesfavourite
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_course_toggle_activity_recommendation : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_course_toggle_activity_recommendation"), Category = "Moodle API Calls")
		static Ucore_course_toggle_activity_recommendation* core_course_toggle_activity_recommendation(
			const FString ServerURL,
			const FString Token,
			const FString _area,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_course_update_categories : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_course_update_categories"), Category = "Moodle API Calls")
		static Ucore_course_update_categories* core_course_update_categories(
			const FString ServerURL,
			const FString Token,
			const int32 _categoriesid = 0,
			const FString _categoriesname = "",
			const FString _categoriesidnumber = "",
			const int32 _categoriesparent = 0,
			const FString _categoriesdescription = "",
			const int32 _categoriesdescriptionformat = 1,
			const FString _categoriestheme = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_course_update_courses : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_course_update_courses"), Category = "Moodle API Calls")
		static Ucore_course_update_courses* core_course_update_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _coursesid = 0,
			const FString _coursesfullname = "",
			const FString _coursesshortname = "",
			const int32 _coursescategoryid = 0,
			const FString _coursesidnumber = "",
			const FString _coursessummary = "",
			const int32 _coursessummaryformat = 0,
			const FString _coursesformat = "",
			const int32 _coursesshowgrades = 0,
			const int32 _coursesnewsitems = 0,
			const int32 _coursesstartdate = 0,
			const int32 _coursesenddate = 0,
			const int32 _coursesnumsections = 0,
			const int32 _coursesmaxbytes = 0,
			const int32 _coursesshowreports = 0,
			const int32 _coursesvisible = 0,
			const int32 _courseshiddensections = 0,
			const int32 _coursesgroupmode = 0,
			const int32 _coursesgroupmodeforce = 0,
			const int32 _coursesdefaultgroupingid = 0,
			const int32 _coursesenablecompletion = 0,
			const int32 _coursescompletionnotify = 0,
			const FString _courseslang = "",
			const FString _coursesforcetheme = "",
			const FString _coursescourseformatoptionsname = "",
			const FString _coursescourseformatoptionsvalue = "",
			const FString _coursescustomfieldsshortname = "",
			const FString _coursescustomfieldsvalue = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_course_view_course : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_course_view_course"), Category = "Moodle API Calls")
		static Ucore_course_view_course* core_course_view_course(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _sectionnumber = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_courseformat_get_state : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_courseformat_get_state"), Category = "Moodle API Calls")
		static Ucore_courseformat_get_state* core_courseformat_get_state(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_courseformat_update_course : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_courseformat_update_course"), Category = "Moodle API Calls")
		static Ucore_courseformat_update_course* core_courseformat_update_course(
			const FString ServerURL,
			const FString Token,
			const FString _action,
			const int32 _courseid,
			const int32 _ids = 0,
			const int32 _targetsectionid = 0,
			const int32 _targetcmid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_create_userfeedback_action_record : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_create_userfeedback_action_record"), Category = "Moodle API Calls")
		static Ucore_create_userfeedback_action_record* core_create_userfeedback_action_record(
			const FString ServerURL,
			const FString Token,
			const FString _action,
			const int32 _contextid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_customfield_create_category : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_customfield_create_category"), Category = "Moodle API Calls")
		static Ucore_customfield_create_category* core_customfield_create_category(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const FString _area,
			const int32 _itemid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_customfield_delete_category : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_customfield_delete_category"), Category = "Moodle API Calls")
		static Ucore_customfield_delete_category* core_customfield_delete_category(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_customfield_delete_field : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_customfield_delete_field"), Category = "Moodle API Calls")
		static Ucore_customfield_delete_field* core_customfield_delete_field(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_customfield_move_category : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_customfield_move_category"), Category = "Moodle API Calls")
		static Ucore_customfield_move_category* core_customfield_move_category(
			const FString ServerURL,
			const FString Token,
			const int32 _id,
			const int32 _beforeid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_customfield_move_field : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_customfield_move_field"), Category = "Moodle API Calls")
		static Ucore_customfield_move_field* core_customfield_move_field(
			const FString ServerURL,
			const FString Token,
			const int32 _id,
			const int32 _categoryid,
			const int32 _beforeid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_customfield_reload_template : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_customfield_reload_template"), Category = "Moodle API Calls")
		static Ucore_customfield_reload_template* core_customfield_reload_template(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const FString _area,
			const int32 _itemid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_dynamic_tabs_get_content : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_dynamic_tabs_get_content"), Category = "Moodle API Calls")
		static Ucore_dynamic_tabs_get_content* core_dynamic_tabs_get_content(
			const FString ServerURL,
			const FString Token,
			const FString _tab,
			const FString _jsondata
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_enrol_get_course_enrolment_methods : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_enrol_get_course_enrolment_methods"), Category = "Moodle API Calls")
		static Ucore_enrol_get_course_enrolment_methods* core_enrol_get_course_enrolment_methods(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_enrol_get_enrolled_users : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_enrol_get_enrolled_users"), Category = "Moodle API Calls")
		static Ucore_enrol_get_enrolled_users* core_enrol_get_enrolled_users(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const FString _optionsname,
			const FString _optionsvalue
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_enrol_get_enrolled_users_with_capability : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_enrol_get_enrolled_users_with_capability"), Category = "Moodle API Calls")
		static Ucore_enrol_get_enrolled_users_with_capability* core_enrol_get_enrolled_users_with_capability(
			const FString ServerURL,
			const FString Token,
			const int32 _coursecapabilitiescourseid,
			const FString _coursecapabilitiescapabilities,
			const FString _optionsname,
			const FString _optionsvalue
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_enrol_get_potential_users : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_enrol_get_potential_users"), Category = "Moodle API Calls")
		static Ucore_enrol_get_potential_users* core_enrol_get_potential_users(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _enrolid,
			const FString _search,
			const int32 _searchanywhere,
			const int32 _page,
			const int32 _perpage
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_enrol_get_users_courses : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_enrol_get_users_courses"), Category = "Moodle API Calls")
		static Ucore_enrol_get_users_courses* core_enrol_get_users_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _returnusercount = 1
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_enrol_search_users : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_enrol_search_users"), Category = "Moodle API Calls")
		static Ucore_enrol_search_users* core_enrol_search_users(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const FString _search,
			const int32 _searchanywhere,
			const int32 _page,
			const int32 _perpage
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_enrol_submit_user_enrolment_form : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_enrol_submit_user_enrolment_form"), Category = "Moodle API Calls")
		static Ucore_enrol_submit_user_enrolment_form* core_enrol_submit_user_enrolment_form(
			const FString ServerURL,
			const FString Token,
			const FString _formdata
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_enrol_unenrol_user_enrolment : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_enrol_unenrol_user_enrolment"), Category = "Moodle API Calls")
		static Ucore_enrol_unenrol_user_enrolment* core_enrol_unenrol_user_enrolment(
			const FString ServerURL,
			const FString Token,
			const int32 _ueid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_fetch_notifications : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_fetch_notifications"), Category = "Moodle API Calls")
		static Ucore_fetch_notifications* core_fetch_notifications(
			const FString ServerURL,
			const FString Token,
			const int32 _contextid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_files_delete_draft_files : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_files_delete_draft_files"), Category = "Moodle API Calls")
		static Ucore_files_delete_draft_files* core_files_delete_draft_files(
			const FString ServerURL,
			const FString Token,
			const int32 _draftitemid,
			const FString _filesfilepath,
			const FString _filesfilename
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_files_get_files : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_files_get_files"), Category = "Moodle API Calls")
		static Ucore_files_get_files* core_files_get_files(
			const FString ServerURL,
			const FString Token,
			const int32 _contextid,
			const FString _component,
			const FString _filearea,
			const int32 _itemid,
			const FString _filepath,
			const FString _filename,
			const int32 _modified = 0,
			const FString _contextlevel = "null",
			const int32 _instanceid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_files_get_unused_draft_itemid : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_files_get_unused_draft_itemid"), Category = "Moodle API Calls")
		static Ucore_files_get_unused_draft_itemid* core_files_get_unused_draft_itemid(
			const FString ServerURL,
			const FString Token
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_files_upload : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_files_upload"), Category = "Moodle API Calls")
		static Ucore_files_upload* core_files_upload(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const FString _filearea,
			const int32 _itemid,
			const FString _filepath,
			const FString _filename,
			const FString _filecontent,
			const int32 _contextid = 0,
			const FString _contextlevel = "null",
			const int32 _instanceid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_filters_get_available_in_context : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_filters_get_available_in_context"), Category = "Moodle API Calls")
		static Ucore_filters_get_available_in_context* core_filters_get_available_in_context(
			const FString ServerURL,
			const FString Token,
			const FString _contextscontextlevel,
			const int32 _contextsinstanceid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_form_dynamic_form : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_form_dynamic_form"), Category = "Moodle API Calls")
		static Ucore_form_dynamic_form* core_form_dynamic_form(
			const FString ServerURL,
			const FString Token,
			const FString _form,
			const FString _formdata
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_form_get_filetypes_browser_data : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_form_get_filetypes_browser_data"), Category = "Moodle API Calls")
		static Ucore_form_get_filetypes_browser_data* core_form_get_filetypes_browser_data(
			const FString ServerURL,
			const FString Token,
			const FString _onlytypes = "",
			const int32 _allowall = 1,
			const FString _current = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_get_component_strings : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_get_component_strings"), Category = "Moodle API Calls")
		static Ucore_get_component_strings* core_get_component_strings(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const FString _lang = "null"
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_get_fragment : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_get_fragment"), Category = "Moodle API Calls")
		static Ucore_get_fragment* core_get_fragment(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const int32 _contextid,
			const FString _callback = "",
			const FString _argsname = "",
			const FString _argsvalue = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_get_string : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_get_string"), Category = "Moodle API Calls")
		static Ucore_get_string* core_get_string(
			const FString ServerURL,
			const FString Token,
			const FString _stringid,
			const FString _stringparamsvalue,
			const FString _component = "moodle",
			const FString _lang = "null",
			const FString _stringparamsname = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_get_strings : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_get_strings"), Category = "Moodle API Calls")
		static Ucore_get_strings* core_get_strings(
			const FString ServerURL,
			const FString Token,
			const FString _stringsstringid,
			const FString _stringsstringparamsvalue,
			const FString _stringscomponent = "moodle",
			const FString _stringslang = "null",
			const FString _stringsstringparamsname = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_get_user_dates : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_get_user_dates"), Category = "Moodle API Calls")
		static Ucore_get_user_dates* core_get_user_dates(
			const FString ServerURL,
			const FString Token,
			const int32 _timestampstimestamp,
			const FString _timestampsformat,
			const int32 _contextid = 0,
			const FString _contextlevel = "",
			const int32 _instanceid = 0,
			const FString _timestampstype = "null",
			const int32 _timestampsfixday = 1,
			const int32 _timestampsfixhour = 1
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_grades_create_gradecategories : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_grades_create_gradecategories"), Category = "Moodle API Calls")
		static Ucore_grades_create_gradecategories* core_grades_create_gradecategories(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const FString _categoriesfullname,
			const int32 _categoriesoptionsaggregation = 0,
			const int32 _categoriesoptionsaggregateonlygraded = 0,
			const int32 _categoriesoptionsaggregateoutcomes = 0,
			const int32 _categoriesoptionsdroplow = 0,
			const FString _categoriesoptionsitemname = "",
			const FString _categoriesoptionsiteminfo = "",
			const FString _categoriesoptionsidnumber = "",
			const int32 _categoriesoptionsgradetype = 0,
			const int32 _categoriesoptionsgrademax = 0,
			const int32 _categoriesoptionsgrademin = 0,
			const int32 _categoriesoptionsgradepass = 0,
			const int32 _categoriesoptionsdisplay = 0,
			const int32 _categoriesoptionsdecimals = 0,
			const int32 _categoriesoptionshiddenuntil = 0,
			const int32 _categoriesoptionslocktime = 0,
			const int32 _categoriesoptionsweightoverride = 0,
			const FString _categoriesoptionsaggregationcoef2 = "",
			const int32 _categoriesoptionsparentcategoryid = 0,
			const FString _categoriesoptionsparentcategoryidnumber = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_grades_get_enrolled_users_for_search_widget : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_grades_get_enrolled_users_for_search_widget"), Category = "Moodle API Calls")
		static Ucore_grades_get_enrolled_users_for_search_widget* core_grades_get_enrolled_users_for_search_widget(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const FString _actionbaseurl,
			const int32 _groupid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_grades_get_groups_for_search_widget : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_grades_get_groups_for_search_widget"), Category = "Moodle API Calls")
		static Ucore_grades_get_groups_for_search_widget* core_grades_get_groups_for_search_widget(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const FString _actionbaseurl
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_grades_grader_gradingpanel_point_fetch : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_grades_grader_gradingpanel_point_fetch"), Category = "Moodle API Calls")
		static Ucore_grades_grader_gradingpanel_point_fetch* core_grades_grader_gradingpanel_point_fetch(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const int32 _contextid,
			const FString _itemname,
			const int32 _gradeduserid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_grades_grader_gradingpanel_point_store : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_grades_grader_gradingpanel_point_store"), Category = "Moodle API Calls")
		static Ucore_grades_grader_gradingpanel_point_store* core_grades_grader_gradingpanel_point_store(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const int32 _contextid,
			const FString _itemname,
			const int32 _gradeduserid,
			const FString _formdata,
			const int32 _notifyuser = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_grades_grader_gradingpanel_scale_fetch : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_grades_grader_gradingpanel_scale_fetch"), Category = "Moodle API Calls")
		static Ucore_grades_grader_gradingpanel_scale_fetch* core_grades_grader_gradingpanel_scale_fetch(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const int32 _contextid,
			const FString _itemname,
			const int32 _gradeduserid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_grades_grader_gradingpanel_scale_store : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_grades_grader_gradingpanel_scale_store"), Category = "Moodle API Calls")
		static Ucore_grades_grader_gradingpanel_scale_store* core_grades_grader_gradingpanel_scale_store(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const int32 _contextid,
			const FString _itemname,
			const int32 _gradeduserid,
			const FString _formdata,
			const int32 _notifyuser = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_grades_update_grades : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_grades_update_grades"), Category = "Moodle API Calls")
		static Ucore_grades_update_grades* core_grades_update_grades(
			const FString ServerURL,
			const FString Token,
			const FString _source,
			const int32 _courseid,
			const FString _component,
			const int32 _activityid,
			const int32 _itemnumber,
			const int32 _gradesstudentid = 0,
			const float _gradesgrade = 0,
			const FString _gradesstr_feedback = "",
			const FString _itemdetailsitemname = "",
			const int32 _itemdetailsidnumber = 0,
			const int32 _itemdetailsgradetype = 0,
			const float _itemdetailsgrademax = 0,
			const float _itemdetailsgrademin = 0,
			const int32 _itemdetailsscaleid = 0,
			const float _itemdetailsmultfactor = 0,
			const float _itemdetailsplusfactor = 0,
			const int32 _itemdetailsdeleted = 0,
			const int32 _itemdetailshidden = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_grading_get_definitions : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_grading_get_definitions"), Category = "Moodle API Calls")
		static Ucore_grading_get_definitions* core_grading_get_definitions(
			const FString ServerURL,
			const FString Token,
			const int32 _cmids,
			const FString _areaname,
			const int32 _activeonly = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_grading_get_gradingform_instances : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_grading_get_gradingform_instances"), Category = "Moodle API Calls")
		static Ucore_grading_get_gradingform_instances* core_grading_get_gradingform_instances(
			const FString ServerURL,
			const FString Token,
			const int32 _definitionid,
			const int32 _since = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_grading_save_definitions : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_grading_save_definitions"), Category = "Moodle API Calls")
		static Ucore_grading_save_definitions* core_grading_save_definitions(
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
			const FString _areasactivemethod = "",
			const int32 _areasdefinitionsid = 0,
			const FString _areasdefinitionsmethod = "",
			const FString _areasdefinitionsdescription = "",
			const int32 _areasdefinitionsdescriptionformat = 0,
			const int32 _areasdefinitionscopiedfromid = 0,
			const int32 _areasdefinitionstimecopied = 0,
			const int32 _areasdefinitionsguideguide_criteriaid = 0,
			const int32 _areasdefinitionsguideguide_criteriasortorder = 0,
			const FString _areasdefinitionsguideguide_criteriadescription = "",
			const int32 _areasdefinitionsguideguide_criteriadescriptionformat = 0,
			const FString _areasdefinitionsguideguide_criteriashortname = "",
			const FString _areasdefinitionsguideguide_criteriadescriptionmarkers = "",
			const int32 _areasdefinitionsguideguide_criteriadescriptionmarkersformat = 0,
			const float _areasdefinitionsguideguide_criteriamaxscore = 0,
			const int32 _areasdefinitionsguideguide_commentsid = 0,
			const int32 _areasdefinitionsguideguide_commentssortorder = 0,
			const FString _areasdefinitionsguideguide_commentsdescription = "",
			const int32 _areasdefinitionsguideguide_commentsdescriptionformat = 0,
			const int32 _areasdefinitionsrubricrubric_criteriaid = 0,
			const int32 _areasdefinitionsrubricrubric_criteriasortorder = 0,
			const FString _areasdefinitionsrubricrubric_criteriadescription = "",
			const int32 _areasdefinitionsrubricrubric_criteriadescriptionformat = 0,
			const int32 _areasdefinitionsrubricrubric_criterialevelsid = 0,
			const float _areasdefinitionsrubricrubric_criterialevelsscore = 0,
			const FString _areasdefinitionsrubricrubric_criterialevelsdefinition = "",
			const int32 _areasdefinitionsrubricrubric_criterialevelsdefinitionformat = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_group_add_group_members : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_group_add_group_members"), Category = "Moodle API Calls")
		static Ucore_group_add_group_members* core_group_add_group_members(
			const FString ServerURL,
			const FString Token,
			const int32 _membersgroupid,
			const int32 _membersuserid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_group_assign_grouping : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_group_assign_grouping"), Category = "Moodle API Calls")
		static Ucore_group_assign_grouping* core_group_assign_grouping(
			const FString ServerURL,
			const FString Token,
			const int32 _assignmentsgroupingid,
			const int32 _assignmentsgroupid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_group_create_groupings : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_group_create_groupings"), Category = "Moodle API Calls")
		static Ucore_group_create_groupings* core_group_create_groupings(
			const FString ServerURL,
			const FString Token,
			const int32 _groupingscourseid,
			const FString _groupingsname,
			const FString _groupingsdescription = "1",
			const int32 _groupingsdescriptionformat = 1,
			const FString _groupingsidnumber = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_group_create_groups : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_group_create_groups"), Category = "Moodle API Calls")
		static Ucore_group_create_groups* core_group_create_groups(
			const FString ServerURL,
			const FString Token,
			const int32 _groupscourseid,
			const FString _groupsname,
			const FString _groupsdescription = "1",
			const int32 _groupsdescriptionformat = 1,
			const FString _groupsenrolmentkey = "",
			const FString _groupsidnumber = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_group_delete_group_members : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_group_delete_group_members"), Category = "Moodle API Calls")
		static Ucore_group_delete_group_members* core_group_delete_group_members(
			const FString ServerURL,
			const FString Token,
			const int32 _membersgroupid,
			const int32 _membersuserid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_group_delete_groupings : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_group_delete_groupings"), Category = "Moodle API Calls")
		static Ucore_group_delete_groupings* core_group_delete_groupings(
			const FString ServerURL,
			const FString Token,
			const int32 _groupingids
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_group_delete_groups : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_group_delete_groups"), Category = "Moodle API Calls")
		static Ucore_group_delete_groups* core_group_delete_groups(
			const FString ServerURL,
			const FString Token,
			const int32 _groupids
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_group_get_activity_allowed_groups : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_group_get_activity_allowed_groups"), Category = "Moodle API Calls")
		static Ucore_group_get_activity_allowed_groups* core_group_get_activity_allowed_groups(
			const FString ServerURL,
			const FString Token,
			const int32 _cmid,
			const int32 _userid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_group_get_activity_groupmode : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_group_get_activity_groupmode"), Category = "Moodle API Calls")
		static Ucore_group_get_activity_groupmode* core_group_get_activity_groupmode(
			const FString ServerURL,
			const FString Token,
			const int32 _cmid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_group_get_course_groupings : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_group_get_course_groupings"), Category = "Moodle API Calls")
		static Ucore_group_get_course_groupings* core_group_get_course_groupings(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_group_get_course_groups : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_group_get_course_groups"), Category = "Moodle API Calls")
		static Ucore_group_get_course_groups* core_group_get_course_groups(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_group_get_course_user_groups : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_group_get_course_user_groups"), Category = "Moodle API Calls")
		static Ucore_group_get_course_user_groups* core_group_get_course_user_groups(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid = 0,
			const int32 _userid = 0,
			const int32 _groupingid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_group_get_group_members : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_group_get_group_members"), Category = "Moodle API Calls")
		static Ucore_group_get_group_members* core_group_get_group_members(
			const FString ServerURL,
			const FString Token,
			const int32 _groupids
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_group_get_groupings : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_group_get_groupings"), Category = "Moodle API Calls")
		static Ucore_group_get_groupings* core_group_get_groupings(
			const FString ServerURL,
			const FString Token,
			const int32 _groupingids,
			const int32 _returngroups = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_group_get_groups : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_group_get_groups"), Category = "Moodle API Calls")
		static Ucore_group_get_groups* core_group_get_groups(
			const FString ServerURL,
			const FString Token,
			const int32 _groupids
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_group_unassign_grouping : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_group_unassign_grouping"), Category = "Moodle API Calls")
		static Ucore_group_unassign_grouping* core_group_unassign_grouping(
			const FString ServerURL,
			const FString Token,
			const int32 _unassignmentsgroupingid,
			const int32 _unassignmentsgroupid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_group_update_groupings : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_group_update_groupings"), Category = "Moodle API Calls")
		static Ucore_group_update_groupings* core_group_update_groupings(
			const FString ServerURL,
			const FString Token,
			const FString _groupingsname,
			const int32 _groupingsid = 0,
			const FString _groupingsdescription = "1",
			const int32 _groupingsdescriptionformat = 1,
			const FString _groupingsidnumber = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_group_update_groups : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_group_update_groups"), Category = "Moodle API Calls")
		static Ucore_group_update_groups* core_group_update_groups(
			const FString ServerURL,
			const FString Token,
			const FString _groupsname,
			const int32 _groupsid = 0,
			const FString _groupsdescription = "",
			const int32 _groupsdescriptionformat = 1,
			const FString _groupsenrolmentkey = "",
			const FString _groupsidnumber = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_h5p_get_trusted_h5p_file : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_h5p_get_trusted_h5p_file"), Category = "Moodle API Calls")
		static Ucore_h5p_get_trusted_h5p_file* core_h5p_get_trusted_h5p_file(
			const FString ServerURL,
			const FString Token,
			const FString _url,
			const int32 _frame = 0,
			const int32 _export = 0,
			const int32 _embed = 0,
			const int32 _copyright = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_block_user : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_block_user"), Category = "Moodle API Calls")
		static Ucore_message_block_user* core_message_block_user(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _blockeduserid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_confirm_contact_request : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_confirm_contact_request"), Category = "Moodle API Calls")
		static Ucore_message_confirm_contact_request* core_message_confirm_contact_request(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _requesteduserid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_create_contact_request : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_create_contact_request"), Category = "Moodle API Calls")
		static Ucore_message_create_contact_request* core_message_create_contact_request(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _requesteduserid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_data_for_messagearea_search_messages : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_data_for_messagearea_search_messages"), Category = "Moodle API Calls")
		static Ucore_message_data_for_messagearea_search_messages* core_message_data_for_messagearea_search_messages(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const FString _search,
			const int32 _limitfrom = 0,
			const int32 _limitnum = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_decline_contact_request : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_decline_contact_request"), Category = "Moodle API Calls")
		static Ucore_message_decline_contact_request* core_message_decline_contact_request(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _requesteduserid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_delete_contacts : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_delete_contacts"), Category = "Moodle API Calls")
		static Ucore_message_delete_contacts* core_message_delete_contacts(
			const FString ServerURL,
			const FString Token,
			const int32 _userids,
			const int32 _userid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_delete_conversations_by_id : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_delete_conversations_by_id"), Category = "Moodle API Calls")
		static Ucore_message_delete_conversations_by_id* core_message_delete_conversations_by_id(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _conversationids
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_delete_message : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_delete_message"), Category = "Moodle API Calls")
		static Ucore_message_delete_message* core_message_delete_message(
			const FString ServerURL,
			const FString Token,
			const int32 _messageid,
			const int32 _userid,
			const int32 _read = 1
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_delete_message_for_all_users : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_delete_message_for_all_users"), Category = "Moodle API Calls")
		static Ucore_message_delete_message_for_all_users* core_message_delete_message_for_all_users(
			const FString ServerURL,
			const FString Token,
			const int32 _messageid,
			const int32 _userid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_get_blocked_users : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_get_blocked_users"), Category = "Moodle API Calls")
		static Ucore_message_get_blocked_users* core_message_get_blocked_users(
			const FString ServerURL,
			const FString Token,
			const int32 _userid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_get_contact_requests : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_get_contact_requests"), Category = "Moodle API Calls")
		static Ucore_message_get_contact_requests* core_message_get_contact_requests(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _limitfrom = 0,
			const int32 _limitnum = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_get_conversation : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_get_conversation"), Category = "Moodle API Calls")
		static Ucore_message_get_conversation* core_message_get_conversation(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _conversationid,
			const int32 _includecontactrequests,
			const int32 _includeprivacyinfo,
			const int32 _memberlimit = 0,
			const int32 _memberoffset = 0,
			const int32 _messagelimit = 100,
			const int32 _messageoffset = 0,
			const int32 _newestmessagesfirst = 1
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_get_conversation_between_users : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_get_conversation_between_users"), Category = "Moodle API Calls")
		static Ucore_message_get_conversation_between_users* core_message_get_conversation_between_users(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _otheruserid,
			const int32 _includecontactrequests,
			const int32 _includeprivacyinfo,
			const int32 _memberlimit = 0,
			const int32 _memberoffset = 0,
			const int32 _messagelimit = 100,
			const int32 _messageoffset = 0,
			const int32 _newestmessagesfirst = 1
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_get_conversation_counts : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_get_conversation_counts"), Category = "Moodle API Calls")
		static Ucore_message_get_conversation_counts* core_message_get_conversation_counts(
			const FString ServerURL,
			const FString Token,
			const int32 _userid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_get_conversation_members : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_get_conversation_members"), Category = "Moodle API Calls")
		static Ucore_message_get_conversation_members* core_message_get_conversation_members(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _conversationid,
			const int32 _includecontactrequests = 0,
			const int32 _includeprivacyinfo = 0,
			const int32 _limitfrom = 0,
			const int32 _limitnum = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_get_conversation_messages : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_get_conversation_messages"), Category = "Moodle API Calls")
		static Ucore_message_get_conversation_messages* core_message_get_conversation_messages(
			const FString ServerURL,
			const FString Token,
			const int32 _currentuserid,
			const int32 _convid,
			const int32 _limitfrom = 0,
			const int32 _limitnum = 0,
			const int32 _newest = 0,
			const int32 _timefrom = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_get_conversations : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_get_conversations"), Category = "Moodle API Calls")
		static Ucore_message_get_conversations* core_message_get_conversations(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _limitfrom = 0,
			const int32 _limitnum = 0,
			const int32 _type = 0,
			const int32 _favourites = 0,
			const int32 _mergeself = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_get_member_info : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_get_member_info"), Category = "Moodle API Calls")
		static Ucore_message_get_member_info* core_message_get_member_info(
			const FString ServerURL,
			const FString Token,
			const int32 _referenceuserid,
			const int32 _userids,
			const int32 _includecontactrequests = 0,
			const int32 _includeprivacyinfo = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_get_message_processor : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_get_message_processor"), Category = "Moodle API Calls")
		static Ucore_message_get_message_processor* core_message_get_message_processor(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const FString _name
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_get_messages : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_get_messages"), Category = "Moodle API Calls")
		static Ucore_message_get_messages* core_message_get_messages(
			const FString ServerURL,
			const FString Token,
			const int32 _useridto,
			const int32 _useridfrom = 0,
			const FString _type = "both",
			const int32 _read = 1,
			const int32 _newestfirst = 1,
			const int32 _limitfrom = 0,
			const int32 _limitnum = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_get_received_contact_requests_count : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_get_received_contact_requests_count"), Category = "Moodle API Calls")
		static Ucore_message_get_received_contact_requests_count* core_message_get_received_contact_requests_count(
			const FString ServerURL,
			const FString Token,
			const int32 _userid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_get_self_conversation : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_get_self_conversation"), Category = "Moodle API Calls")
		static Ucore_message_get_self_conversation* core_message_get_self_conversation(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _messagelimit = 100,
			const int32 _messageoffset = 0,
			const int32 _newestmessagesfirst = 1
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_get_unread_conversation_counts : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_get_unread_conversation_counts"), Category = "Moodle API Calls")
		static Ucore_message_get_unread_conversation_counts* core_message_get_unread_conversation_counts(
			const FString ServerURL,
			const FString Token,
			const int32 _userid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_get_unread_conversations_count : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_get_unread_conversations_count"), Category = "Moodle API Calls")
		static Ucore_message_get_unread_conversations_count* core_message_get_unread_conversations_count(
			const FString ServerURL,
			const FString Token,
			const int32 _useridto
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_get_unread_notification_count : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_get_unread_notification_count"), Category = "Moodle API Calls")
		static Ucore_message_get_unread_notification_count* core_message_get_unread_notification_count(
			const FString ServerURL,
			const FString Token,
			const int32 _useridto
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_get_user_contacts : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_get_user_contacts"), Category = "Moodle API Calls")
		static Ucore_message_get_user_contacts* core_message_get_user_contacts(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _limitfrom = 0,
			const int32 _limitnum = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_get_user_message_preferences : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_get_user_message_preferences"), Category = "Moodle API Calls")
		static Ucore_message_get_user_message_preferences* core_message_get_user_message_preferences(
			const FString ServerURL,
			const FString Token,
			const int32 _userid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_get_user_notification_preferences : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_get_user_notification_preferences"), Category = "Moodle API Calls")
		static Ucore_message_get_user_notification_preferences* core_message_get_user_notification_preferences(
			const FString ServerURL,
			const FString Token,
			const int32 _userid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_mark_all_conversation_messages_as_read : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_mark_all_conversation_messages_as_read"), Category = "Moodle API Calls")
		static Ucore_message_mark_all_conversation_messages_as_read* core_message_mark_all_conversation_messages_as_read(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _conversationid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_mark_all_notifications_as_read : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_mark_all_notifications_as_read"), Category = "Moodle API Calls")
		static Ucore_message_mark_all_notifications_as_read* core_message_mark_all_notifications_as_read(
			const FString ServerURL,
			const FString Token,
			const int32 _useridto,
			const int32 _useridfrom = 0,
			const int32 _timecreatedto = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_mark_message_read : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_mark_message_read"), Category = "Moodle API Calls")
		static Ucore_message_mark_message_read* core_message_mark_message_read(
			const FString ServerURL,
			const FString Token,
			const int32 _messageid,
			const int32 _timeread = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_mark_notification_read : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_mark_notification_read"), Category = "Moodle API Calls")
		static Ucore_message_mark_notification_read* core_message_mark_notification_read(
			const FString ServerURL,
			const FString Token,
			const int32 _notificationid,
			const int32 _timeread = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_message_processor_config_form : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_message_processor_config_form"), Category = "Moodle API Calls")
		static Ucore_message_message_processor_config_form* core_message_message_processor_config_form(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const FString _name,
			const FString _formvaluesname,
			const FString _formvaluesvalue
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_message_search_users : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_message_search_users"), Category = "Moodle API Calls")
		static Ucore_message_message_search_users* core_message_message_search_users(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const FString _search,
			const int32 _limitfrom = 0,
			const int32 _limitnum = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_mute_conversations : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_mute_conversations"), Category = "Moodle API Calls")
		static Ucore_message_mute_conversations* core_message_mute_conversations(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _conversationids
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_search_contacts : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_search_contacts"), Category = "Moodle API Calls")
		static Ucore_message_search_contacts* core_message_search_contacts(
			const FString ServerURL,
			const FString Token,
			const FString _searchtext,
			const int32 _onlymycourses = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_send_instant_messages : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_send_instant_messages"), Category = "Moodle API Calls")
		static Ucore_message_send_instant_messages* core_message_send_instant_messages(
			const FString ServerURL,
			const FString Token,
			const int32 _messagestouserid,
			const FString _messagestext = "0",
			const int32 _messagestextformat = 0,
			const FString _messagesclientmsgid = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_send_messages_to_conversation : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_send_messages_to_conversation"), Category = "Moodle API Calls")
		static Ucore_message_send_messages_to_conversation* core_message_send_messages_to_conversation(
			const FString ServerURL,
			const FString Token,
			const int32 _conversationid,
			const FString _messagestext = "0",
			const int32 _messagestextformat = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_set_favourite_conversations : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_set_favourite_conversations"), Category = "Moodle API Calls")
		static Ucore_message_set_favourite_conversations* core_message_set_favourite_conversations(
			const FString ServerURL,
			const FString Token,
			const int32 _conversations,
			const int32 _userid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_unblock_user : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_unblock_user"), Category = "Moodle API Calls")
		static Ucore_message_unblock_user* core_message_unblock_user(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _unblockeduserid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_unmute_conversations : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_unmute_conversations"), Category = "Moodle API Calls")
		static Ucore_message_unmute_conversations* core_message_unmute_conversations(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _conversationids
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_message_unset_favourite_conversations : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_message_unset_favourite_conversations"), Category = "Moodle API Calls")
		static Ucore_message_unset_favourite_conversations* core_message_unset_favourite_conversations(
			const FString ServerURL,
			const FString Token,
			const int32 _conversations,
			const int32 _userid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_notes_create_notes : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_notes_create_notes"), Category = "Moodle API Calls")
		static Ucore_notes_create_notes* core_notes_create_notes(
			const FString ServerURL,
			const FString Token,
			const int32 _notesuserid,
			const FString _notespublishstate,
			const int32 _notescourseid,
			const FString _notestext,
			const int32 _notesformat = 1,
			const FString _notesclientnoteid = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_notes_delete_notes : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_notes_delete_notes"), Category = "Moodle API Calls")
		static Ucore_notes_delete_notes* core_notes_delete_notes(
			const FString ServerURL,
			const FString Token,
			const int32 _notes
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_notes_get_course_notes : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_notes_get_course_notes"), Category = "Moodle API Calls")
		static Ucore_notes_get_course_notes* core_notes_get_course_notes(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _userid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_notes_get_notes : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_notes_get_notes"), Category = "Moodle API Calls")
		static Ucore_notes_get_notes* core_notes_get_notes(
			const FString ServerURL,
			const FString Token,
			const int32 _notes
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_notes_update_notes : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_notes_update_notes"), Category = "Moodle API Calls")
		static Ucore_notes_update_notes* core_notes_update_notes(
			const FString ServerURL,
			const FString Token,
			const int32 _notesid,
			const FString _notespublishstate,
			const FString _notestext,
			const int32 _notesformat = 1
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_notes_view_notes : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_notes_view_notes"), Category = "Moodle API Calls")
		static Ucore_notes_view_notes* core_notes_view_notes(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _userid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_output_load_fontawesome_icon_system_map : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_output_load_fontawesome_icon_system_map"), Category = "Moodle API Calls")
		static Ucore_output_load_fontawesome_icon_system_map* core_output_load_fontawesome_icon_system_map(
			const FString ServerURL,
			const FString Token,
			const FString _themename
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_output_load_template : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_output_load_template"), Category = "Moodle API Calls")
		static Ucore_output_load_template* core_output_load_template(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const FString _template,
			const FString _themename,
			const int32 _includecomments = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_output_load_template_with_dependencies : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_output_load_template_with_dependencies"), Category = "Moodle API Calls")
		static Ucore_output_load_template_with_dependencies* core_output_load_template_with_dependencies(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const FString _template,
			const FString _themename,
			const int32 _includecomments = 0,
			const FString _lang = "null"
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_payment_get_available_gateways : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_payment_get_available_gateways"), Category = "Moodle API Calls")
		static Ucore_payment_get_available_gateways* core_payment_get_available_gateways(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const FString _paymentarea,
			const int32 _itemid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_question_get_random_question_summaries : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_question_get_random_question_summaries"), Category = "Moodle API Calls")
		static Ucore_question_get_random_question_summaries* core_question_get_random_question_summaries(
			const FString ServerURL,
			const FString Token,
			const int32 _categoryid,
			const int32 _includesubcategories,
			const int32 _tagids,
			const int32 _contextid,
			const int32 _limit = 0,
			const int32 _offset = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_question_update_flag : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_question_update_flag"), Category = "Moodle API Calls")
		static Ucore_question_update_flag* core_question_update_flag(
			const FString ServerURL,
			const FString Token,
			const int32 _qubaid,
			const int32 _questionid,
			const int32 _qaid,
			const int32 _slot,
			const FString _checksum,
			const int32 _newstate
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_rating_add_rating : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_rating_add_rating"), Category = "Moodle API Calls")
		static Ucore_rating_add_rating* core_rating_add_rating(
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
			const int32 _aggregation = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_rating_get_item_ratings : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_rating_get_item_ratings"), Category = "Moodle API Calls")
		static Ucore_rating_get_item_ratings* core_rating_get_item_ratings(
			const FString ServerURL,
			const FString Token,
			const FString _contextlevel,
			const int32 _instanceid,
			const FString _component,
			const FString _ratingarea,
			const int32 _itemid,
			const int32 _scaleid,
			const FString _sort
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_reportbuilder_audiences_delete : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_reportbuilder_audiences_delete"), Category = "Moodle API Calls")
		static Ucore_reportbuilder_audiences_delete* core_reportbuilder_audiences_delete(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid,
			const int32 _instanceid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_reportbuilder_columns_add : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_reportbuilder_columns_add"), Category = "Moodle API Calls")
		static Ucore_reportbuilder_columns_add* core_reportbuilder_columns_add(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid,
			const FString _uniqueidentifier
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_reportbuilder_columns_delete : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_reportbuilder_columns_delete"), Category = "Moodle API Calls")
		static Ucore_reportbuilder_columns_delete* core_reportbuilder_columns_delete(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid,
			const int32 _columnid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_reportbuilder_columns_reorder : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_reportbuilder_columns_reorder"), Category = "Moodle API Calls")
		static Ucore_reportbuilder_columns_reorder* core_reportbuilder_columns_reorder(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid,
			const int32 _columnid,
			const int32 _position
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_reportbuilder_columns_sort_get : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_reportbuilder_columns_sort_get"), Category = "Moodle API Calls")
		static Ucore_reportbuilder_columns_sort_get* core_reportbuilder_columns_sort_get(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_reportbuilder_columns_sort_reorder : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_reportbuilder_columns_sort_reorder"), Category = "Moodle API Calls")
		static Ucore_reportbuilder_columns_sort_reorder* core_reportbuilder_columns_sort_reorder(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid,
			const int32 _columnid,
			const int32 _position
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_reportbuilder_columns_sort_toggle : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_reportbuilder_columns_sort_toggle"), Category = "Moodle API Calls")
		static Ucore_reportbuilder_columns_sort_toggle* core_reportbuilder_columns_sort_toggle(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid,
			const int32 _columnid,
			const int32 _enabled,
			const int32 _direction = 4
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_reportbuilder_conditions_add : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_reportbuilder_conditions_add"), Category = "Moodle API Calls")
		static Ucore_reportbuilder_conditions_add* core_reportbuilder_conditions_add(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid,
			const FString _uniqueidentifier
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_reportbuilder_conditions_delete : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_reportbuilder_conditions_delete"), Category = "Moodle API Calls")
		static Ucore_reportbuilder_conditions_delete* core_reportbuilder_conditions_delete(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid,
			const int32 _conditionid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_reportbuilder_conditions_reorder : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_reportbuilder_conditions_reorder"), Category = "Moodle API Calls")
		static Ucore_reportbuilder_conditions_reorder* core_reportbuilder_conditions_reorder(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid,
			const int32 _conditionid,
			const int32 _position
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_reportbuilder_conditions_reset : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_reportbuilder_conditions_reset"), Category = "Moodle API Calls")
		static Ucore_reportbuilder_conditions_reset* core_reportbuilder_conditions_reset(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_reportbuilder_filters_add : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_reportbuilder_filters_add"), Category = "Moodle API Calls")
		static Ucore_reportbuilder_filters_add* core_reportbuilder_filters_add(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid,
			const FString _uniqueidentifier
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_reportbuilder_filters_delete : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_reportbuilder_filters_delete"), Category = "Moodle API Calls")
		static Ucore_reportbuilder_filters_delete* core_reportbuilder_filters_delete(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid,
			const int32 _filterid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_reportbuilder_filters_reorder : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_reportbuilder_filters_reorder"), Category = "Moodle API Calls")
		static Ucore_reportbuilder_filters_reorder* core_reportbuilder_filters_reorder(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid,
			const int32 _filterid,
			const int32 _position
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_reportbuilder_filters_reset : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_reportbuilder_filters_reset"), Category = "Moodle API Calls")
		static Ucore_reportbuilder_filters_reset* core_reportbuilder_filters_reset(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid,
			const FString _parameters = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_reportbuilder_list_reports : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_reportbuilder_list_reports"), Category = "Moodle API Calls")
		static Ucore_reportbuilder_list_reports* core_reportbuilder_list_reports(
			const FString ServerURL,
			const FString Token,
			const int32 _page = 0,
			const int32 _perpage = 10
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_reportbuilder_reports_delete : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_reportbuilder_reports_delete"), Category = "Moodle API Calls")
		static Ucore_reportbuilder_reports_delete* core_reportbuilder_reports_delete(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_reportbuilder_reports_get : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_reportbuilder_reports_get"), Category = "Moodle API Calls")
		static Ucore_reportbuilder_reports_get* core_reportbuilder_reports_get(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid,
			const int32 _editmode = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_reportbuilder_retrieve_report : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_reportbuilder_retrieve_report"), Category = "Moodle API Calls")
		static Ucore_reportbuilder_retrieve_report* core_reportbuilder_retrieve_report(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid,
			const int32 _page = 0,
			const int32 _perpage = 10
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_reportbuilder_schedules_delete : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_reportbuilder_schedules_delete"), Category = "Moodle API Calls")
		static Ucore_reportbuilder_schedules_delete* core_reportbuilder_schedules_delete(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid,
			const int32 _scheduleid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_reportbuilder_schedules_send : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_reportbuilder_schedules_send"), Category = "Moodle API Calls")
		static Ucore_reportbuilder_schedules_send* core_reportbuilder_schedules_send(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid,
			const int32 _scheduleid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_reportbuilder_schedules_toggle : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_reportbuilder_schedules_toggle"), Category = "Moodle API Calls")
		static Ucore_reportbuilder_schedules_toggle* core_reportbuilder_schedules_toggle(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid,
			const int32 _scheduleid,
			const int32 _enabled
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_reportbuilder_set_filters : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_reportbuilder_set_filters"), Category = "Moodle API Calls")
		static Ucore_reportbuilder_set_filters* core_reportbuilder_set_filters(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid,
			const FString _values,
			const FString _parameters = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_reportbuilder_view_report : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_reportbuilder_view_report"), Category = "Moodle API Calls")
		static Ucore_reportbuilder_view_report* core_reportbuilder_view_report(
			const FString ServerURL,
			const FString Token,
			const int32 _reportid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_role_assign_roles : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_role_assign_roles"), Category = "Moodle API Calls")
		static Ucore_role_assign_roles* core_role_assign_roles(
			const FString ServerURL,
			const FString Token,
			const int32 _assignmentsroleid,
			const int32 _assignmentsuserid,
			const int32 _assignmentscontextid = 0,
			const FString _assignmentscontextlevel = "",
			const int32 _assignmentsinstanceid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_role_unassign_roles : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_role_unassign_roles"), Category = "Moodle API Calls")
		static Ucore_role_unassign_roles* core_role_unassign_roles(
			const FString ServerURL,
			const FString Token,
			const int32 _unassignmentsroleid,
			const int32 _unassignmentsuserid,
			const int32 _unassignmentscontextid = 0,
			const FString _unassignmentscontextlevel = "",
			const int32 _unassignmentsinstanceid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_search_get_relevant_users : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_search_get_relevant_users"), Category = "Moodle API Calls")
		static Ucore_search_get_relevant_users* core_search_get_relevant_users(
			const FString ServerURL,
			const FString Token,
			const FString _query,
			const int32 _courseid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_session_time_remaining : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_session_time_remaining"), Category = "Moodle API Calls")
		static Ucore_session_time_remaining* core_session_time_remaining(
			const FString ServerURL,
			const FString Token
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_session_touch : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_session_touch"), Category = "Moodle API Calls")
		static Ucore_session_touch* core_session_touch(
			const FString ServerURL,
			const FString Token
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_table_get_dynamic_table_content : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_table_get_dynamic_table_content"), Category = "Moodle API Calls")
		static Ucore_table_get_dynamic_table_content* core_table_get_dynamic_table_content(
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
			const FString _sortdatasortby = "",
			const FString _sortdatasortorder = "",
			const FString _filtersname = "",
			const int32 _filtersjointype = 0,
			const FString _filtersvalues = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_tag_get_tag_areas : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_tag_get_tag_areas"), Category = "Moodle API Calls")
		static Ucore_tag_get_tag_areas* core_tag_get_tag_areas(
			const FString ServerURL,
			const FString Token
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_tag_get_tag_cloud : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_tag_get_tag_cloud"), Category = "Moodle API Calls")
		static Ucore_tag_get_tag_cloud* core_tag_get_tag_cloud(
			const FString ServerURL,
			const FString Token,
			const int32 _tagcollid = 0,
			const int32 _isstandard = 0,
			const int32 _limit = 150,
			const FString _sort = "name",
			const FString _search = "",
			const int32 _fromctx = 0,
			const int32 _ctx = 0,
			const int32 _rec = 1
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_tag_get_tag_collections : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_tag_get_tag_collections"), Category = "Moodle API Calls")
		static Ucore_tag_get_tag_collections* core_tag_get_tag_collections(
			const FString ServerURL,
			const FString Token
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_tag_get_tagindex : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_tag_get_tagindex"), Category = "Moodle API Calls")
		static Ucore_tag_get_tagindex* core_tag_get_tagindex(
			const FString ServerURL,
			const FString Token,
			const int32 _tagindextc,
			const FString _tagindextag = "",
			const int32 _tagindexta = 0,
			const int32 _tagindexexcl = 0,
			const int32 _tagindexfrom = 0,
			const int32 _tagindexctx = 0,
			const int32 _tagindexrec = 0,
			const int32 _tagindexpage = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_tag_get_tagindex_per_area : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_tag_get_tagindex_per_area"), Category = "Moodle API Calls")
		static Ucore_tag_get_tagindex_per_area* core_tag_get_tagindex_per_area(
			const FString ServerURL,
			const FString Token,
			const int32 _tagindexid = 0,
			const FString _tagindextag = "",
			const int32 _tagindextc = 0,
			const int32 _tagindexta = 0,
			const int32 _tagindexexcl = 0,
			const int32 _tagindexfrom = 0,
			const int32 _tagindexctx = 0,
			const int32 _tagindexrec = 0,
			const int32 _tagindexpage = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_tag_get_tags : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_tag_get_tags"), Category = "Moodle API Calls")
		static Ucore_tag_get_tags* core_tag_get_tags(
			const FString ServerURL,
			const FString Token,
			const int32 _tagsid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_tag_update_tags : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_tag_update_tags"), Category = "Moodle API Calls")
		static Ucore_tag_update_tags* core_tag_update_tags(
			const FString ServerURL,
			const FString Token,
			const int32 _tagsid,
			const FString _tagsrawname = "",
			const FString _tagsdescription = "",
			const int32 _tagsdescriptionformat = 0,
			const int32 _tagsflag = 0,
			const int32 _tagsofficial = 0,
			const int32 _tagsisstandard = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_update_inplace_editable : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_update_inplace_editable"), Category = "Moodle API Calls")
		static Ucore_update_inplace_editable* core_update_inplace_editable(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const FString _itemtype,
			const FString _itemid,
			const FString _value
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_user_add_user_device : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_user_add_user_device"), Category = "Moodle API Calls")
		static Ucore_user_add_user_device* core_user_add_user_device(
			const FString ServerURL,
			const FString Token,
			const FString _appid,
			const FString _name,
			const FString _model,
			const FString _platform,
			const FString _version,
			const FString _pushid,
			const FString _uuid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_user_add_user_private_files : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_user_add_user_private_files"), Category = "Moodle API Calls")
		static Ucore_user_add_user_private_files* core_user_add_user_private_files(
			const FString ServerURL,
			const FString Token,
			const int32 _draftid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_user_agree_site_policy : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_user_agree_site_policy"), Category = "Moodle API Calls")
		static Ucore_user_agree_site_policy* core_user_agree_site_policy(
			const FString ServerURL,
			const FString Token
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_user_create_users : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_user_create_users"), Category = "Moodle API Calls")
		static Ucore_user_create_users* core_user_create_users(
			const FString ServerURL,
			const FString Token,
			const FString _usersusername,
			const FString _usersemail,
			const int32 _userscreatepassword = 0,
			const FString _usersauth = "manual",
			const FString _userspassword = "",
			const FString _usersfirstname = "",
			const FString _userslastname = "",
			const int32 _usersmaildisplay = 0,
			const FString _userscity = "",
			const FString _userscountry = "",
			const FString _userstimezone = "",
			const FString _usersdescription = "",
			const FString _usersfirstnamephonetic = "",
			const FString _userslastnamephonetic = "",
			const FString _usersmiddlename = "",
			const FString _usersalternatename = "",
			const FString _usersinterests = "",
			const FString _usersidnumber = "",
			const FString _usersinstitution = "",
			const FString _usersdepartment = "",
			const FString _usersphone1 = "",
			const FString _usersphone2 = "",
			const FString _usersaddress = "",
			const FString _userslang = "fr",
			const FString _userscalendartype = "gregorian",
			const FString _userstheme = "",
			const int32 _usersmailformat = 0,
			const FString _userscustomfieldstype = "",
			const FString _userscustomfieldsvalue = "",
			const FString _userspreferencestype = "",
			const FString _userspreferencesvalue = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_user_delete_users : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_user_delete_users"), Category = "Moodle API Calls")
		static Ucore_user_delete_users* core_user_delete_users(
			const FString ServerURL,
			const FString Token,
			const int32 _userids
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_user_get_course_user_profiles : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_user_get_course_user_profiles"), Category = "Moodle API Calls")
		static Ucore_user_get_course_user_profiles* core_user_get_course_user_profiles(
			const FString ServerURL,
			const FString Token,
			const int32 _userlistuserid,
			const int32 _userlistcourseid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_user_get_private_files_info : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_user_get_private_files_info"), Category = "Moodle API Calls")
		static Ucore_user_get_private_files_info* core_user_get_private_files_info(
			const FString ServerURL,
			const FString Token,
			const int32 _userid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_user_get_user_preferences : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_user_get_user_preferences"), Category = "Moodle API Calls")
		static Ucore_user_get_user_preferences* core_user_get_user_preferences(
			const FString ServerURL,
			const FString Token,
			const FString _name = "",
			const int32 _userid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_user_get_users : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_user_get_users"), Category = "Moodle API Calls")
		static Ucore_user_get_users* core_user_get_users(
			const FString ServerURL,
			const FString Token,
			const FString _criteriakey,
			const FString _criteriavalue
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_user_get_users_by_field : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_user_get_users_by_field"), Category = "Moodle API Calls")
		static Ucore_user_get_users_by_field* core_user_get_users_by_field(
			const FString ServerURL,
			const FString Token,
			const FString _field,
			const FString _values
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_user_remove_user_device : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_user_remove_user_device"), Category = "Moodle API Calls")
		static Ucore_user_remove_user_device* core_user_remove_user_device(
			const FString ServerURL,
			const FString Token,
			const FString _uuid,
			const FString _appid = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_user_search_identity : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_user_search_identity"), Category = "Moodle API Calls")
		static Ucore_user_search_identity* core_user_search_identity(
			const FString ServerURL,
			const FString Token,
			const FString _field,
			const FString _values
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_user_set_user_preferences : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_user_set_user_preferences"), Category = "Moodle API Calls")
		static Ucore_user_set_user_preferences* core_user_set_user_preferences(
			const FString ServerURL,
			const FString Token,
			const FString _preferencesname,
			const FString _preferencesvalue,
			const int32 _preferencesuserid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_user_update_picture : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_user_update_picture"), Category = "Moodle API Calls")
		static Ucore_user_update_picture* core_user_update_picture(
			const FString ServerURL,
			const FString Token,
			const int32 _draftitemid,
			const int32 _delete = 0,
			const int32 _userid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_user_update_user_preferences : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_user_update_user_preferences"), Category = "Moodle API Calls")
		static Ucore_user_update_user_preferences* core_user_update_user_preferences(
			const FString ServerURL,
			const FString Token,
			const FString _preferencestype,
			const int32 _userid = 0,
			const int32 _emailstop = 0,
			const FString _preferencesvalue = "null"
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_user_update_users : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_user_update_users"), Category = "Moodle API Calls")
		static Ucore_user_update_users* core_user_update_users(
			const FString ServerURL,
			const FString Token,
			const int32 _usersid = 0,
			const FString _usersusername = "",
			const FString _usersauth = "",
			const int32 _userssuspended = 0,
			const FString _userspassword = "",
			const FString _usersfirstname = "",
			const FString _userslastname = "",
			const FString _usersemail = "",
			const int32 _usersmaildisplay = 0,
			const FString _userscity = "",
			const FString _userscountry = "",
			const FString _userstimezone = "",
			const FString _usersdescription = "",
			const int32 _usersuserpicture = 0,
			const FString _usersfirstnamephonetic = "",
			const FString _userslastnamephonetic = "",
			const FString _usersmiddlename = "",
			const FString _usersalternatename = "",
			const FString _usersinterests = "",
			const FString _usersidnumber = "",
			const FString _usersinstitution = "",
			const FString _usersdepartment = "",
			const FString _usersphone1 = "",
			const FString _usersphone2 = "",
			const FString _usersaddress = "",
			const FString _userslang = "",
			const FString _userscalendartype = "",
			const FString _userstheme = "",
			const int32 _usersmailformat = 0,
			const FString _userscustomfieldstype = "",
			const FString _userscustomfieldsvalue = "",
			const FString _userspreferencestype = "",
			const FString _userspreferencesvalue = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_user_view_user_list : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_user_view_user_list"), Category = "Moodle API Calls")
		static Ucore_user_view_user_list* core_user_view_user_list(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_user_view_user_profile : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_user_view_user_profile"), Category = "Moodle API Calls")
		static Ucore_user_view_user_profile* core_user_view_user_profile(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _courseid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_webservice_get_site_info : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_webservice_get_site_info"), Category = "Moodle API Calls")
		static Ucore_webservice_get_site_info* core_webservice_get_site_info(
			const FString ServerURL,
			const FString Token,
			const FString _serviceshortnames = "Array ( ) "
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ucore_xapi_statement_post : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "core_xapi_statement_post"), Category = "Moodle API Calls")
		static Ucore_xapi_statement_post* core_xapi_statement_post(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const FString _requestjson
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Uenrol_guest_get_instance_info : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "enrol_guest_get_instance_info"), Category = "Moodle API Calls")
		static Uenrol_guest_get_instance_info* enrol_guest_get_instance_info(
			const FString ServerURL,
			const FString Token,
			const int32 _instanceid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Uenrol_manual_enrol_users : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "enrol_manual_enrol_users"), Category = "Moodle API Calls")
		static Uenrol_manual_enrol_users* enrol_manual_enrol_users(
			const FString ServerURL,
			const FString Token,
			const int32 _enrolmentsroleid,
			const int32 _enrolmentsuserid,
			const int32 _enrolmentscourseid,
			const int32 _enrolmentstimestart = 0,
			const int32 _enrolmentstimeend = 0,
			const int32 _enrolmentssuspend = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Uenrol_manual_unenrol_users : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "enrol_manual_unenrol_users"), Category = "Moodle API Calls")
		static Uenrol_manual_unenrol_users* enrol_manual_unenrol_users(
			const FString ServerURL,
			const FString Token,
			const int32 _enrolmentsuserid,
			const int32 _enrolmentscourseid,
			const int32 _enrolmentsroleid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Uenrol_meta_add_instances : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "enrol_meta_add_instances"), Category = "Moodle API Calls")
		static Uenrol_meta_add_instances* enrol_meta_add_instances(
			const FString ServerURL,
			const FString Token,
			const int32 _instancesmetacourseid,
			const FString _instancescourseid,
			const int32 _instancescreategroup = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Uenrol_meta_delete_instances : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "enrol_meta_delete_instances"), Category = "Moodle API Calls")
		static Uenrol_meta_delete_instances* enrol_meta_delete_instances(
			const FString ServerURL,
			const FString Token,
			const int32 _instancesmetacourseid,
			const FString _instancescourseid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Uenrol_self_enrol_user : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "enrol_self_enrol_user"), Category = "Moodle API Calls")
		static Uenrol_self_enrol_user* enrol_self_enrol_user(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const FString _password = "",
			const int32 _instanceid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Uenrol_self_get_instance_info : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "enrol_self_get_instance_info"), Category = "Moodle API Calls")
		static Uenrol_self_get_instance_info* enrol_self_get_instance_info(
			const FString ServerURL,
			const FString Token,
			const int32 _instanceid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ugradereport_overview_get_course_grades : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "gradereport_overview_get_course_grades"), Category = "Moodle API Calls")
		static Ugradereport_overview_get_course_grades* gradereport_overview_get_course_grades(
			const FString ServerURL,
			const FString Token,
			const int32 _userid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ugradereport_overview_view_grade_report : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "gradereport_overview_view_grade_report"), Category = "Moodle API Calls")
		static Ugradereport_overview_view_grade_report* gradereport_overview_view_grade_report(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _userid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ugradereport_singleview_get_grade_items_for_search_widget : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "gradereport_singleview_get_grade_items_for_search_widget"), Category = "Moodle API Calls")
		static Ugradereport_singleview_get_grade_items_for_search_widget* gradereport_singleview_get_grade_items_for_search_widget(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ugradereport_user_get_grade_items : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "gradereport_user_get_grade_items"), Category = "Moodle API Calls")
		static Ugradereport_user_get_grade_items* gradereport_user_get_grade_items(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _userid = 0,
			const int32 _groupid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ugradereport_user_get_grades_table : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "gradereport_user_get_grades_table"), Category = "Moodle API Calls")
		static Ugradereport_user_get_grades_table* gradereport_user_get_grades_table(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _userid = 0,
			const int32 _groupid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ugradereport_user_view_grade_report : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "gradereport_user_view_grade_report"), Category = "Moodle API Calls")
		static Ugradereport_user_view_grade_report* gradereport_user_view_grade_report(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _userid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ugradingform_guide_grader_gradingpanel_fetch : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "gradingform_guide_grader_gradingpanel_fetch"), Category = "Moodle API Calls")
		static Ugradingform_guide_grader_gradingpanel_fetch* gradingform_guide_grader_gradingpanel_fetch(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const int32 _contextid,
			const FString _itemname,
			const int32 _gradeduserid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ugradingform_guide_grader_gradingpanel_store : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "gradingform_guide_grader_gradingpanel_store"), Category = "Moodle API Calls")
		static Ugradingform_guide_grader_gradingpanel_store* gradingform_guide_grader_gradingpanel_store(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const int32 _contextid,
			const FString _itemname,
			const int32 _gradeduserid,
			const FString _formdata,
			const int32 _notifyuser = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ugradingform_rubric_grader_gradingpanel_fetch : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "gradingform_rubric_grader_gradingpanel_fetch"), Category = "Moodle API Calls")
		static Ugradingform_rubric_grader_gradingpanel_fetch* gradingform_rubric_grader_gradingpanel_fetch(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const int32 _contextid,
			const FString _itemname,
			const int32 _gradeduserid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ugradingform_rubric_grader_gradingpanel_store : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "gradingform_rubric_grader_gradingpanel_store"), Category = "Moodle API Calls")
		static Ugradingform_rubric_grader_gradingpanel_store* gradingform_rubric_grader_gradingpanel_store(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const int32 _contextid,
			const FString _itemname,
			const int32 _gradeduserid,
			const FString _formdata,
			const int32 _notifyuser = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umedia_videojs_get_language : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "media_videojs_get_language"), Category = "Moodle API Calls")
		static Umedia_videojs_get_language* media_videojs_get_language(
			const FString ServerURL,
			const FString Token,
			const FString _lang
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umessage_airnotifier_are_notification_preferences_configured : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "message_airnotifier_are_notification_preferences_configured"), Category = "Moodle API Calls")
		static Umessage_airnotifier_are_notification_preferences_configured* message_airnotifier_are_notification_preferences_configured(
			const FString ServerURL,
			const FString Token,
			const int32 _userids
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umessage_airnotifier_enable_device : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "message_airnotifier_enable_device"), Category = "Moodle API Calls")
		static Umessage_airnotifier_enable_device* message_airnotifier_enable_device(
			const FString ServerURL,
			const FString Token,
			const int32 _deviceid,
			const int32 _enable
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umessage_airnotifier_get_user_devices : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "message_airnotifier_get_user_devices"), Category = "Moodle API Calls")
		static Umessage_airnotifier_get_user_devices* message_airnotifier_get_user_devices(
			const FString ServerURL,
			const FString Token,
			const FString _appid,
			const int32 _userid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umessage_airnotifier_is_system_configured : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "message_airnotifier_is_system_configured"), Category = "Moodle API Calls")
		static Umessage_airnotifier_is_system_configured* message_airnotifier_is_system_configured(
			const FString ServerURL,
			const FString Token
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umessage_popup_get_popup_notifications : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "message_popup_get_popup_notifications"), Category = "Moodle API Calls")
		static Umessage_popup_get_popup_notifications* message_popup_get_popup_notifications(
			const FString ServerURL,
			const FString Token,
			const int32 _useridto,
			const int32 _newestfirst = 1,
			const int32 _limit = 0,
			const int32 _offset = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umessage_popup_get_unread_popup_notification_count : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "message_popup_get_unread_popup_notification_count"), Category = "Moodle API Calls")
		static Umessage_popup_get_unread_popup_notification_count* message_popup_get_unread_popup_notification_count(
			const FString ServerURL,
			const FString Token,
			const int32 _useridto
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_assign_copy_previous_attempt : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_assign_copy_previous_attempt"), Category = "Moodle API Calls")
		static Umod_assign_copy_previous_attempt* mod_assign_copy_previous_attempt(
			const FString ServerURL,
			const FString Token,
			const int32 _assignmentid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_assign_get_assignments : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_assign_get_assignments"), Category = "Moodle API Calls")
		static Umod_assign_get_assignments* mod_assign_get_assignments(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids = 0,
			const FString _capabilities = "Array ( ) ",
			const int32 _includenotenrolledcourses = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_assign_get_grades : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_assign_get_grades"), Category = "Moodle API Calls")
		static Umod_assign_get_grades* mod_assign_get_grades(
			const FString ServerURL,
			const FString Token,
			const int32 _assignmentids,
			const int32 _since = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_assign_get_participant : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_assign_get_participant"), Category = "Moodle API Calls")
		static Umod_assign_get_participant* mod_assign_get_participant(
			const FString ServerURL,
			const FString Token,
			const int32 _assignid,
			const int32 _userid,
			const int32 _embeduser = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_assign_get_submission_status : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_assign_get_submission_status"), Category = "Moodle API Calls")
		static Umod_assign_get_submission_status* mod_assign_get_submission_status(
			const FString ServerURL,
			const FString Token,
			const int32 _assignid,
			const int32 _userid = 0,
			const int32 _groupid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_assign_get_submissions : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_assign_get_submissions"), Category = "Moodle API Calls")
		static Umod_assign_get_submissions* mod_assign_get_submissions(
			const FString ServerURL,
			const FString Token,
			const int32 _assignmentids,
			const FString _status = "",
			const int32 _since = 0,
			const int32 _before = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_assign_get_user_flags : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_assign_get_user_flags"), Category = "Moodle API Calls")
		static Umod_assign_get_user_flags* mod_assign_get_user_flags(
			const FString ServerURL,
			const FString Token,
			const int32 _assignmentids
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_assign_get_user_mappings : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_assign_get_user_mappings"), Category = "Moodle API Calls")
		static Umod_assign_get_user_mappings* mod_assign_get_user_mappings(
			const FString ServerURL,
			const FString Token,
			const int32 _assignmentids
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_assign_list_participants : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_assign_list_participants"), Category = "Moodle API Calls")
		static Umod_assign_list_participants* mod_assign_list_participants(
			const FString ServerURL,
			const FString Token,
			const int32 _assignid,
			const int32 _groupid,
			const FString _filter,
			const int32 _skip = 0,
			const int32 _limit = 0,
			const int32 _onlyids = 0,
			const int32 _includeenrolments = 1,
			const int32 _tablesort = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_assign_lock_submissions : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_assign_lock_submissions"), Category = "Moodle API Calls")
		static Umod_assign_lock_submissions* mod_assign_lock_submissions(
			const FString ServerURL,
			const FString Token,
			const int32 _assignmentid,
			const int32 _userids
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_assign_reveal_identities : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_assign_reveal_identities"), Category = "Moodle API Calls")
		static Umod_assign_reveal_identities* mod_assign_reveal_identities(
			const FString ServerURL,
			const FString Token,
			const int32 _assignmentid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_assign_revert_submissions_to_draft : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_assign_revert_submissions_to_draft"), Category = "Moodle API Calls")
		static Umod_assign_revert_submissions_to_draft* mod_assign_revert_submissions_to_draft(
			const FString ServerURL,
			const FString Token,
			const int32 _assignmentid,
			const int32 _userids
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_assign_save_grade : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_assign_save_grade"), Category = "Moodle API Calls")
		static Umod_assign_save_grade* mod_assign_save_grade(
			const FString ServerURL,
			const FString Token,
			const int32 _assignmentid,
			const int32 _userid,
			const float _grade,
			const int32 _attemptnumber,
			const int32 _addattempt,
			const FString _workflowstate,
			const int32 _applytoall,
			const FString _plugindataassignfeedbackcomments_editortext = "",
			const int32 _plugindataassignfeedbackcomments_editorformat = 0,
			const int32 _plugindatafiles_filemanager = 0,
			const int32 _advancedgradingdataguidecriteriacriterionid = 0,
			const int32 _advancedgradingdataguidecriteriafillingscriterionid = 0,
			const int32 _advancedgradingdataguidecriteriafillingslevelid = 0,
			const FString _advancedgradingdataguidecriteriafillingsremark = "",
			const int32 _advancedgradingdataguidecriteriafillingsremarkformat = 0,
			const float _advancedgradingdataguidecriteriafillingsscore = 0,
			const int32 _advancedgradingdatarubriccriteriacriterionid = 0,
			const int32 _advancedgradingdatarubriccriteriafillingscriterionid = 0,
			const int32 _advancedgradingdatarubriccriteriafillingslevelid = 0,
			const FString _advancedgradingdatarubriccriteriafillingsremark = "",
			const int32 _advancedgradingdatarubriccriteriafillingsremarkformat = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_assign_save_grades : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_assign_save_grades"), Category = "Moodle API Calls")
		static Umod_assign_save_grades* mod_assign_save_grades(
			const FString ServerURL,
			const FString Token,
			const int32 _assignmentid,
			const int32 _applytoall,
			const int32 _gradesuserid,
			const float _gradesgrade,
			const int32 _gradesattemptnumber,
			const int32 _gradesaddattempt,
			const FString _gradesworkflowstate,
			const FString _gradesplugindataassignfeedbackcomments_editortext = "",
			const int32 _gradesplugindataassignfeedbackcomments_editorformat = 0,
			const int32 _gradesplugindatafiles_filemanager = 0,
			const int32 _gradesadvancedgradingdataguidecriteriacriterionid = 0,
			const int32 _gradesadvancedgradingdataguidecriteriafillingscriterionid = 0,
			const int32 _gradesadvancedgradingdataguidecriteriafillingslevelid = 0,
			const FString _gradesadvancedgradingdataguidecriteriafillingsremark = "",
			const int32 _gradesadvancedgradingdataguidecriteriafillingsremarkformat = 0,
			const float _gradesadvancedgradingdataguidecriteriafillingsscore = 0,
			const int32 _gradesadvancedgradingdatarubriccriteriacriterionid = 0,
			const int32 _gradesadvancedgradingdatarubriccriteriafillingscriterionid = 0,
			const int32 _gradesadvancedgradingdatarubriccriteriafillingslevelid = 0,
			const FString _gradesadvancedgradingdatarubriccriteriafillingsremark = "",
			const int32 _gradesadvancedgradingdatarubriccriteriafillingsremarkformat = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_assign_save_submission : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_assign_save_submission"), Category = "Moodle API Calls")
		static Umod_assign_save_submission* mod_assign_save_submission(
			const FString ServerURL,
			const FString Token,
			const int32 _assignmentid,
			const FString _plugindataonlinetext_editortext = "",
			const int32 _plugindataonlinetext_editorformat = 0,
			const int32 _plugindataonlinetext_editoritemid = 0,
			const int32 _plugindatafiles_filemanager = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_assign_save_user_extensions : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_assign_save_user_extensions"), Category = "Moodle API Calls")
		static Umod_assign_save_user_extensions* mod_assign_save_user_extensions(
			const FString ServerURL,
			const FString Token,
			const int32 _assignmentid,
			const int32 _userids,
			const int32 _dates
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_assign_set_user_flags : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_assign_set_user_flags"), Category = "Moodle API Calls")
		static Umod_assign_set_user_flags* mod_assign_set_user_flags(
			const FString ServerURL,
			const FString Token,
			const int32 _assignmentid,
			const int32 _userflagsuserid,
			const int32 _userflagslocked = 0,
			const int32 _userflagsmailed = 0,
			const int32 _userflagsextensionduedate = 0,
			const FString _userflagsworkflowstate = "",
			const int32 _userflagsallocatedmarker = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_assign_start_submission : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_assign_start_submission"), Category = "Moodle API Calls")
		static Umod_assign_start_submission* mod_assign_start_submission(
			const FString ServerURL,
			const FString Token,
			const int32 _assignid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_assign_submit_for_grading : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_assign_submit_for_grading"), Category = "Moodle API Calls")
		static Umod_assign_submit_for_grading* mod_assign_submit_for_grading(
			const FString ServerURL,
			const FString Token,
			const int32 _assignmentid,
			const int32 _acceptsubmissionstatement
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_assign_submit_grading_form : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_assign_submit_grading_form"), Category = "Moodle API Calls")
		static Umod_assign_submit_grading_form* mod_assign_submit_grading_form(
			const FString ServerURL,
			const FString Token,
			const int32 _assignmentid,
			const int32 _userid,
			const FString _jsonformdata
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_assign_unlock_submissions : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_assign_unlock_submissions"), Category = "Moodle API Calls")
		static Umod_assign_unlock_submissions* mod_assign_unlock_submissions(
			const FString ServerURL,
			const FString Token,
			const int32 _assignmentid,
			const int32 _userids
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_assign_view_assign : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_assign_view_assign"), Category = "Moodle API Calls")
		static Umod_assign_view_assign* mod_assign_view_assign(
			const FString ServerURL,
			const FString Token,
			const int32 _assignid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_assign_view_grading_table : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_assign_view_grading_table"), Category = "Moodle API Calls")
		static Umod_assign_view_grading_table* mod_assign_view_grading_table(
			const FString ServerURL,
			const FString Token,
			const int32 _assignid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_assign_view_submission_status : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_assign_view_submission_status"), Category = "Moodle API Calls")
		static Umod_assign_view_submission_status* mod_assign_view_submission_status(
			const FString ServerURL,
			const FString Token,
			const int32 _assignid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_bigbluebuttonbn_can_join : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_bigbluebuttonbn_can_join"), Category = "Moodle API Calls")
		static Umod_bigbluebuttonbn_can_join* mod_bigbluebuttonbn_can_join(
			const FString ServerURL,
			const FString Token,
			const int32 _cmid,
			const int32 _groupid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_bigbluebuttonbn_completion_validate : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_bigbluebuttonbn_completion_validate"), Category = "Moodle API Calls")
		static Umod_bigbluebuttonbn_completion_validate* mod_bigbluebuttonbn_completion_validate(
			const FString ServerURL,
			const FString Token,
			const int32 _bigbluebuttonbnid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_bigbluebuttonbn_end_meeting : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_bigbluebuttonbn_end_meeting"), Category = "Moodle API Calls")
		static Umod_bigbluebuttonbn_end_meeting* mod_bigbluebuttonbn_end_meeting(
			const FString ServerURL,
			const FString Token,
			const int32 _bigbluebuttonbnid,
			const int32 _groupid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_bigbluebuttonbn_get_bigbluebuttonbns_by_courses : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_bigbluebuttonbn_get_bigbluebuttonbns_by_courses"), Category = "Moodle API Calls")
		static Umod_bigbluebuttonbn_get_bigbluebuttonbns_by_courses* mod_bigbluebuttonbn_get_bigbluebuttonbns_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_bigbluebuttonbn_get_join_url : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_bigbluebuttonbn_get_join_url"), Category = "Moodle API Calls")
		static Umod_bigbluebuttonbn_get_join_url* mod_bigbluebuttonbn_get_join_url(
			const FString ServerURL,
			const FString Token,
			const int32 _cmid,
			const int32 _groupid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_bigbluebuttonbn_get_recordings : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_bigbluebuttonbn_get_recordings"), Category = "Moodle API Calls")
		static Umod_bigbluebuttonbn_get_recordings* mod_bigbluebuttonbn_get_recordings(
			const FString ServerURL,
			const FString Token,
			const int32 _bigbluebuttonbnid,
			const FString _tools = "protect,unprotect,publish,unpublish,delete",
			const int32 _groupid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_bigbluebuttonbn_get_recordings_to_import : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_bigbluebuttonbn_get_recordings_to_import"), Category = "Moodle API Calls")
		static Umod_bigbluebuttonbn_get_recordings_to_import* mod_bigbluebuttonbn_get_recordings_to_import(
			const FString ServerURL,
			const FString Token,
			const int32 _destinationinstanceid,
			const int32 _sourcebigbluebuttonbnid = 0,
			const int32 _sourcecourseid = 0,
			const FString _tools = "protect,unprotect,publish,unpublish,delete",
			const int32 _groupid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_bigbluebuttonbn_meeting_info : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_bigbluebuttonbn_meeting_info"), Category = "Moodle API Calls")
		static Umod_bigbluebuttonbn_meeting_info* mod_bigbluebuttonbn_meeting_info(
			const FString ServerURL,
			const FString Token,
			const int32 _bigbluebuttonbnid,
			const int32 _groupid = 0,
			const int32 _updatecache = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_bigbluebuttonbn_update_recording : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_bigbluebuttonbn_update_recording"), Category = "Moodle API Calls")
		static Umod_bigbluebuttonbn_update_recording* mod_bigbluebuttonbn_update_recording(
			const FString ServerURL,
			const FString Token,
			const int32 _bigbluebuttonbnid,
			const int32 _recordingid,
			const FString _action,
			const FString _additionaloptions
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_bigbluebuttonbn_view_bigbluebuttonbn : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_bigbluebuttonbn_view_bigbluebuttonbn"), Category = "Moodle API Calls")
		static Umod_bigbluebuttonbn_view_bigbluebuttonbn* mod_bigbluebuttonbn_view_bigbluebuttonbn(
			const FString ServerURL,
			const FString Token,
			const int32 _bigbluebuttonbnid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_book_get_books_by_courses : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_book_get_books_by_courses"), Category = "Moodle API Calls")
		static Umod_book_get_books_by_courses* mod_book_get_books_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_book_view_book : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_book_view_book"), Category = "Moodle API Calls")
		static Umod_book_view_book* mod_book_view_book(
			const FString ServerURL,
			const FString Token,
			const int32 _bookid,
			const int32 _chapterid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_chat_get_chat_latest_messages : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_chat_get_chat_latest_messages"), Category = "Moodle API Calls")
		static Umod_chat_get_chat_latest_messages* mod_chat_get_chat_latest_messages(
			const FString ServerURL,
			const FString Token,
			const FString _chatsid,
			const int32 _chatlasttime = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_chat_get_chat_users : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_chat_get_chat_users"), Category = "Moodle API Calls")
		static Umod_chat_get_chat_users* mod_chat_get_chat_users(
			const FString ServerURL,
			const FString Token,
			const FString _chatsid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_chat_get_chats_by_courses : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_chat_get_chats_by_courses"), Category = "Moodle API Calls")
		static Umod_chat_get_chats_by_courses* mod_chat_get_chats_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_chat_get_session_messages : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_chat_get_session_messages"), Category = "Moodle API Calls")
		static Umod_chat_get_session_messages* mod_chat_get_session_messages(
			const FString ServerURL,
			const FString Token,
			const int32 _chatid,
			const int32 _sessionstart,
			const int32 _sessionend,
			const int32 _groupid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_chat_get_sessions : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_chat_get_sessions"), Category = "Moodle API Calls")
		static Umod_chat_get_sessions* mod_chat_get_sessions(
			const FString ServerURL,
			const FString Token,
			const int32 _chatid,
			const int32 _groupid = 0,
			const int32 _showall = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_chat_login_user : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_chat_login_user"), Category = "Moodle API Calls")
		static Umod_chat_login_user* mod_chat_login_user(
			const FString ServerURL,
			const FString Token,
			const FString _chatsid,
			const int32 _chatlasttime = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_chat_send_chat_message : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_chat_send_chat_message"), Category = "Moodle API Calls")
		static Umod_chat_send_chat_message* mod_chat_send_chat_message(
			const FString ServerURL,
			const FString Token,
			const FString _chatsid,
			const FString _messagetext,
			const FString _beepid = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_chat_view_chat : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_chat_view_chat"), Category = "Moodle API Calls")
		static Umod_chat_view_chat* mod_chat_view_chat(
			const FString ServerURL,
			const FString Token,
			const int32 _chatid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_choice_delete_choice_responses : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_choice_delete_choice_responses"), Category = "Moodle API Calls")
		static Umod_choice_delete_choice_responses* mod_choice_delete_choice_responses(
			const FString ServerURL,
			const FString Token,
			const int32 _choiceid,
			const int32 _responses = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_choice_get_choice_options : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_choice_get_choice_options"), Category = "Moodle API Calls")
		static Umod_choice_get_choice_options* mod_choice_get_choice_options(
			const FString ServerURL,
			const FString Token,
			const int32 _choiceid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_choice_get_choice_results : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_choice_get_choice_results"), Category = "Moodle API Calls")
		static Umod_choice_get_choice_results* mod_choice_get_choice_results(
			const FString ServerURL,
			const FString Token,
			const int32 _choiceid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_choice_get_choices_by_courses : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_choice_get_choices_by_courses"), Category = "Moodle API Calls")
		static Umod_choice_get_choices_by_courses* mod_choice_get_choices_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_choice_submit_choice_response : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_choice_submit_choice_response"), Category = "Moodle API Calls")
		static Umod_choice_submit_choice_response* mod_choice_submit_choice_response(
			const FString ServerURL,
			const FString Token,
			const int32 _choiceid,
			const int32 _responses
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_choice_view_choice : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_choice_view_choice"), Category = "Moodle API Calls")
		static Umod_choice_view_choice* mod_choice_view_choice(
			const FString ServerURL,
			const FString Token,
			const int32 _choiceid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_data_add_entry : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_data_add_entry"), Category = "Moodle API Calls")
		static Umod_data_add_entry* mod_data_add_entry(
			const FString ServerURL,
			const FString Token,
			const int32 _databaseid,
			const int32 _datafieldid,
			const FString _datavalue,
			const int32 _groupid = 0,
			const FString _datasubfield = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_data_approve_entry : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_data_approve_entry"), Category = "Moodle API Calls")
		static Umod_data_approve_entry* mod_data_approve_entry(
			const FString ServerURL,
			const FString Token,
			const int32 _entryid,
			const int32 _approve = 1
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_data_delete_entry : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_data_delete_entry"), Category = "Moodle API Calls")
		static Umod_data_delete_entry* mod_data_delete_entry(
			const FString ServerURL,
			const FString Token,
			const int32 _entryid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_data_delete_saved_preset : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_data_delete_saved_preset"), Category = "Moodle API Calls")
		static Umod_data_delete_saved_preset* mod_data_delete_saved_preset(
			const FString ServerURL,
			const FString Token,
			const int32 _dataid,
			const FString _presetnames
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_data_get_data_access_information : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_data_get_data_access_information"), Category = "Moodle API Calls")
		static Umod_data_get_data_access_information* mod_data_get_data_access_information(
			const FString ServerURL,
			const FString Token,
			const int32 _databaseid,
			const int32 _groupid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_data_get_databases_by_courses : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_data_get_databases_by_courses"), Category = "Moodle API Calls")
		static Umod_data_get_databases_by_courses* mod_data_get_databases_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_data_get_entries : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_data_get_entries"), Category = "Moodle API Calls")
		static Umod_data_get_entries* mod_data_get_entries(
			const FString ServerURL,
			const FString Token,
			const int32 _databaseid,
			const int32 _groupid = 0,
			const int32 _returncontents = 0,
			const int32 _sort = 0,
			const FString _order = "null",
			const int32 _page = 0,
			const int32 _perpage = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_data_get_entry : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_data_get_entry"), Category = "Moodle API Calls")
		static Umod_data_get_entry* mod_data_get_entry(
			const FString ServerURL,
			const FString Token,
			const int32 _entryid,
			const int32 _returncontents = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_data_get_fields : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_data_get_fields"), Category = "Moodle API Calls")
		static Umod_data_get_fields* mod_data_get_fields(
			const FString ServerURL,
			const FString Token,
			const int32 _databaseid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_data_get_mapping_information : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_data_get_mapping_information"), Category = "Moodle API Calls")
		static Umod_data_get_mapping_information* mod_data_get_mapping_information(
			const FString ServerURL,
			const FString Token,
			const int32 _cmid,
			const FString _importedpreset
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_data_search_entries : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_data_search_entries"), Category = "Moodle API Calls")
		static Umod_data_search_entries* mod_data_search_entries(
			const FString ServerURL,
			const FString Token,
			const int32 _databaseid,
			const FString _advsearchname,
			const FString _advsearchvalue,
			const int32 _groupid = 0,
			const int32 _returncontents = 0,
			const FString _search = "",
			const int32 _sort = 0,
			const FString _order = "null",
			const int32 _page = 0,
			const int32 _perpage = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_data_update_entry : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_data_update_entry"), Category = "Moodle API Calls")
		static Umod_data_update_entry* mod_data_update_entry(
			const FString ServerURL,
			const FString Token,
			const int32 _entryid,
			const int32 _datafieldid,
			const FString _datavalue,
			const FString _datasubfield = "null"
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_data_view_database : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_data_view_database"), Category = "Moodle API Calls")
		static Umod_data_view_database* mod_data_view_database(
			const FString ServerURL,
			const FString Token,
			const int32 _databaseid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_feedback_get_analysis : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_feedback_get_analysis"), Category = "Moodle API Calls")
		static Umod_feedback_get_analysis* mod_feedback_get_analysis(
			const FString ServerURL,
			const FString Token,
			const int32 _feedbackid,
			const int32 _groupid = 0,
			const int32 _courseid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_feedback_get_current_completed_tmp : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_feedback_get_current_completed_tmp"), Category = "Moodle API Calls")
		static Umod_feedback_get_current_completed_tmp* mod_feedback_get_current_completed_tmp(
			const FString ServerURL,
			const FString Token,
			const int32 _feedbackid,
			const int32 _courseid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_feedback_get_feedback_access_information : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_feedback_get_feedback_access_information"), Category = "Moodle API Calls")
		static Umod_feedback_get_feedback_access_information* mod_feedback_get_feedback_access_information(
			const FString ServerURL,
			const FString Token,
			const int32 _feedbackid,
			const int32 _courseid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_feedback_get_feedbacks_by_courses : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_feedback_get_feedbacks_by_courses"), Category = "Moodle API Calls")
		static Umod_feedback_get_feedbacks_by_courses* mod_feedback_get_feedbacks_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_feedback_get_finished_responses : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_feedback_get_finished_responses"), Category = "Moodle API Calls")
		static Umod_feedback_get_finished_responses* mod_feedback_get_finished_responses(
			const FString ServerURL,
			const FString Token,
			const int32 _feedbackid,
			const int32 _courseid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_feedback_get_items : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_feedback_get_items"), Category = "Moodle API Calls")
		static Umod_feedback_get_items* mod_feedback_get_items(
			const FString ServerURL,
			const FString Token,
			const int32 _feedbackid,
			const int32 _courseid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_feedback_get_last_completed : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_feedback_get_last_completed"), Category = "Moodle API Calls")
		static Umod_feedback_get_last_completed* mod_feedback_get_last_completed(
			const FString ServerURL,
			const FString Token,
			const int32 _feedbackid,
			const int32 _courseid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_feedback_get_non_respondents : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_feedback_get_non_respondents"), Category = "Moodle API Calls")
		static Umod_feedback_get_non_respondents* mod_feedback_get_non_respondents(
			const FString ServerURL,
			const FString Token,
			const int32 _feedbackid,
			const int32 _groupid = 0,
			const FString _sort = "lastaccess",
			const int32 _page = 0,
			const int32 _perpage = 0,
			const int32 _courseid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_feedback_get_page_items : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_feedback_get_page_items"), Category = "Moodle API Calls")
		static Umod_feedback_get_page_items* mod_feedback_get_page_items(
			const FString ServerURL,
			const FString Token,
			const int32 _feedbackid,
			const int32 _page,
			const int32 _courseid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_feedback_get_responses_analysis : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_feedback_get_responses_analysis"), Category = "Moodle API Calls")
		static Umod_feedback_get_responses_analysis* mod_feedback_get_responses_analysis(
			const FString ServerURL,
			const FString Token,
			const int32 _feedbackid,
			const int32 _groupid = 0,
			const int32 _page = 0,
			const int32 _perpage = 0,
			const int32 _courseid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_feedback_get_unfinished_responses : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_feedback_get_unfinished_responses"), Category = "Moodle API Calls")
		static Umod_feedback_get_unfinished_responses* mod_feedback_get_unfinished_responses(
			const FString ServerURL,
			const FString Token,
			const int32 _feedbackid,
			const int32 _courseid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_feedback_launch_feedback : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_feedback_launch_feedback"), Category = "Moodle API Calls")
		static Umod_feedback_launch_feedback* mod_feedback_launch_feedback(
			const FString ServerURL,
			const FString Token,
			const int32 _feedbackid,
			const int32 _courseid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_feedback_process_page : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_feedback_process_page"), Category = "Moodle API Calls")
		static Umod_feedback_process_page* mod_feedback_process_page(
			const FString ServerURL,
			const FString Token,
			const int32 _feedbackid,
			const int32 _page,
			const FString _responsesname,
			const FString _responsesvalue,
			const int32 _goprevious = 0,
			const int32 _courseid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_feedback_view_feedback : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_feedback_view_feedback"), Category = "Moodle API Calls")
		static Umod_feedback_view_feedback* mod_feedback_view_feedback(
			const FString ServerURL,
			const FString Token,
			const int32 _feedbackid,
			const int32 _moduleviewed = 0,
			const int32 _courseid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_folder_get_folders_by_courses : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_folder_get_folders_by_courses"), Category = "Moodle API Calls")
		static Umod_folder_get_folders_by_courses* mod_folder_get_folders_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_folder_view_folder : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_folder_view_folder"), Category = "Moodle API Calls")
		static Umod_folder_view_folder* mod_folder_view_folder(
			const FString ServerURL,
			const FString Token,
			const int32 _folderid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_forum_add_discussion : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_forum_add_discussion"), Category = "Moodle API Calls")
		static Umod_forum_add_discussion* mod_forum_add_discussion(
			const FString ServerURL,
			const FString Token,
			const int32 _forumid,
			const FString _subject,
			const FString _message,
			const FString _optionsname,
			const FString _optionsvalue,
			const int32 _groupid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_forum_add_discussion_post : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_forum_add_discussion_post"), Category = "Moodle API Calls")
		static Umod_forum_add_discussion_post* mod_forum_add_discussion_post(
			const FString ServerURL,
			const FString Token,
			const int32 _postid,
			const FString _subject,
			const FString _optionsname,
			const FString _optionsvalue,
			const FString _message = "1",
			const int32 _messageformat = 1
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_forum_can_add_discussion : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_forum_can_add_discussion"), Category = "Moodle API Calls")
		static Umod_forum_can_add_discussion* mod_forum_can_add_discussion(
			const FString ServerURL,
			const FString Token,
			const int32 _forumid,
			const int32 _groupid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_forum_delete_post : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_forum_delete_post"), Category = "Moodle API Calls")
		static Umod_forum_delete_post* mod_forum_delete_post(
			const FString ServerURL,
			const FString Token,
			const int32 _postid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_forum_get_discussion_post : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_forum_get_discussion_post"), Category = "Moodle API Calls")
		static Umod_forum_get_discussion_post* mod_forum_get_discussion_post(
			const FString ServerURL,
			const FString Token,
			const int32 _postid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_forum_get_discussion_posts : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_forum_get_discussion_posts"), Category = "Moodle API Calls")
		static Umod_forum_get_discussion_posts* mod_forum_get_discussion_posts(
			const FString ServerURL,
			const FString Token,
			const int32 _discussionid,
			const FString _sortby = "created",
			const FString _sortdirection = "DESC",
			const int32 _includeinlineattachments = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_forum_get_discussion_posts_by_userid : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_forum_get_discussion_posts_by_userid"), Category = "Moodle API Calls")
		static Umod_forum_get_discussion_posts_by_userid* mod_forum_get_discussion_posts_by_userid(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _cmid,
			const FString _sortby = "created",
			const FString _sortdirection = "DESC"
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_forum_get_forum_access_information : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_forum_get_forum_access_information"), Category = "Moodle API Calls")
		static Umod_forum_get_forum_access_information* mod_forum_get_forum_access_information(
			const FString ServerURL,
			const FString Token,
			const int32 _forumid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_forum_get_forum_discussions : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_forum_get_forum_discussions"), Category = "Moodle API Calls")
		static Umod_forum_get_forum_discussions* mod_forum_get_forum_discussions(
			const FString ServerURL,
			const FString Token,
			const int32 _forumid,
			const int32 _sortorder = -1,
			const int32 _page = -1,
			const int32 _perpage = 0,
			const int32 _groupid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_forum_get_forums_by_courses : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_forum_get_forums_by_courses"), Category = "Moodle API Calls")
		static Umod_forum_get_forums_by_courses* mod_forum_get_forums_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_forum_prepare_draft_area_for_post : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_forum_prepare_draft_area_for_post"), Category = "Moodle API Calls")
		static Umod_forum_prepare_draft_area_for_post* mod_forum_prepare_draft_area_for_post(
			const FString ServerURL,
			const FString Token,
			const int32 _postid,
			const FString _area,
			const FString _filestokeepfilename,
			const FString _filestokeepfilepath,
			const int32 _draftitemid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_forum_set_lock_state : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_forum_set_lock_state"), Category = "Moodle API Calls")
		static Umod_forum_set_lock_state* mod_forum_set_lock_state(
			const FString ServerURL,
			const FString Token,
			const int32 _forumid,
			const int32 _discussionid,
			const int32 _targetstate
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_forum_set_pin_state : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_forum_set_pin_state"), Category = "Moodle API Calls")
		static Umod_forum_set_pin_state* mod_forum_set_pin_state(
			const FString ServerURL,
			const FString Token,
			const int32 _discussionid,
			const int32 _targetstate
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_forum_set_subscription_state : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_forum_set_subscription_state"), Category = "Moodle API Calls")
		static Umod_forum_set_subscription_state* mod_forum_set_subscription_state(
			const FString ServerURL,
			const FString Token,
			const int32 _forumid,
			const int32 _discussionid,
			const int32 _targetstate
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_forum_toggle_favourite_state : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_forum_toggle_favourite_state"), Category = "Moodle API Calls")
		static Umod_forum_toggle_favourite_state* mod_forum_toggle_favourite_state(
			const FString ServerURL,
			const FString Token,
			const int32 _discussionid,
			const int32 _targetstate
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_forum_update_discussion_post : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_forum_update_discussion_post"), Category = "Moodle API Calls")
		static Umod_forum_update_discussion_post* mod_forum_update_discussion_post(
			const FString ServerURL,
			const FString Token,
			const int32 _postid,
			const FString _optionsname,
			const FString _optionsvalue,
			const FString _subject = "",
			const FString _message = "1",
			const int32 _messageformat = 1
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_forum_view_forum : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_forum_view_forum"), Category = "Moodle API Calls")
		static Umod_forum_view_forum* mod_forum_view_forum(
			const FString ServerURL,
			const FString Token,
			const int32 _forumid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_forum_view_forum_discussion : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_forum_view_forum_discussion"), Category = "Moodle API Calls")
		static Umod_forum_view_forum_discussion* mod_forum_view_forum_discussion(
			const FString ServerURL,
			const FString Token,
			const int32 _discussionid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_glossary_add_entry : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_glossary_add_entry"), Category = "Moodle API Calls")
		static Umod_glossary_add_entry* mod_glossary_add_entry(
			const FString ServerURL,
			const FString Token,
			const int32 _glossaryid,
			const FString _concept,
			const FString _definition,
			const int32 _definitionformat,
			const FString _optionsname,
			const FString _optionsvalue
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_glossary_delete_entry : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_glossary_delete_entry"), Category = "Moodle API Calls")
		static Umod_glossary_delete_entry* mod_glossary_delete_entry(
			const FString ServerURL,
			const FString Token,
			const int32 _entryid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_glossary_get_authors : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_glossary_get_authors"), Category = "Moodle API Calls")
		static Umod_glossary_get_authors* mod_glossary_get_authors(
			const FString ServerURL,
			const FString Token,
			const int32 _id,
			const int32 _from = 0,
			const int32 _limit = 20,
			const int32 _optionsincludenotapproved = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_glossary_get_categories : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_glossary_get_categories"), Category = "Moodle API Calls")
		static Umod_glossary_get_categories* mod_glossary_get_categories(
			const FString ServerURL,
			const FString Token,
			const int32 _id,
			const int32 _from = 0,
			const int32 _limit = 20
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_glossary_get_entries_by_author : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_glossary_get_entries_by_author"), Category = "Moodle API Calls")
		static Umod_glossary_get_entries_by_author* mod_glossary_get_entries_by_author(
			const FString ServerURL,
			const FString Token,
			const int32 _id,
			const FString _letter,
			const FString _field = "LASTNAME",
			const FString _sort = "ASC",
			const int32 _from = 0,
			const int32 _limit = 20,
			const int32 _optionsincludenotapproved = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_glossary_get_entries_by_author_id : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_glossary_get_entries_by_author_id"), Category = "Moodle API Calls")
		static Umod_glossary_get_entries_by_author_id* mod_glossary_get_entries_by_author_id(
			const FString ServerURL,
			const FString Token,
			const int32 _id,
			const int32 _authorid,
			const FString _order = "CONCEPT",
			const FString _sort = "ASC",
			const int32 _from = 0,
			const int32 _limit = 20,
			const int32 _optionsincludenotapproved = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_glossary_get_entries_by_category : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_glossary_get_entries_by_category"), Category = "Moodle API Calls")
		static Umod_glossary_get_entries_by_category* mod_glossary_get_entries_by_category(
			const FString ServerURL,
			const FString Token,
			const int32 _id,
			const int32 _categoryid,
			const int32 _from = 0,
			const int32 _limit = 20,
			const int32 _optionsincludenotapproved = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_glossary_get_entries_by_date : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_glossary_get_entries_by_date"), Category = "Moodle API Calls")
		static Umod_glossary_get_entries_by_date* mod_glossary_get_entries_by_date(
			const FString ServerURL,
			const FString Token,
			const int32 _id,
			const FString _order = "UPDATE",
			const FString _sort = "DESC",
			const int32 _from = 0,
			const int32 _limit = 20,
			const int32 _optionsincludenotapproved = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_glossary_get_entries_by_letter : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_glossary_get_entries_by_letter"), Category = "Moodle API Calls")
		static Umod_glossary_get_entries_by_letter* mod_glossary_get_entries_by_letter(
			const FString ServerURL,
			const FString Token,
			const int32 _id,
			const FString _letter,
			const int32 _from = 0,
			const int32 _limit = 20,
			const int32 _optionsincludenotapproved = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_glossary_get_entries_by_search : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_glossary_get_entries_by_search"), Category = "Moodle API Calls")
		static Umod_glossary_get_entries_by_search* mod_glossary_get_entries_by_search(
			const FString ServerURL,
			const FString Token,
			const int32 _id,
			const FString _query,
			const int32 _fullsearch = 1,
			const FString _order = "CONCEPT",
			const FString _sort = "ASC",
			const int32 _from = 0,
			const int32 _limit = 20,
			const int32 _optionsincludenotapproved = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_glossary_get_entries_by_term : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_glossary_get_entries_by_term"), Category = "Moodle API Calls")
		static Umod_glossary_get_entries_by_term* mod_glossary_get_entries_by_term(
			const FString ServerURL,
			const FString Token,
			const int32 _id,
			const FString _term,
			const int32 _from = 0,
			const int32 _limit = 20,
			const int32 _optionsincludenotapproved = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_glossary_get_entries_to_approve : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_glossary_get_entries_to_approve"), Category = "Moodle API Calls")
		static Umod_glossary_get_entries_to_approve* mod_glossary_get_entries_to_approve(
			const FString ServerURL,
			const FString Token,
			const int32 _id,
			const FString _letter,
			const FString _order = "CONCEPT",
			const FString _sort = "ASC",
			const int32 _from = 0,
			const int32 _limit = 20
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_glossary_get_entry_by_id : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_glossary_get_entry_by_id"), Category = "Moodle API Calls")
		static Umod_glossary_get_entry_by_id* mod_glossary_get_entry_by_id(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_glossary_get_glossaries_by_courses : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_glossary_get_glossaries_by_courses"), Category = "Moodle API Calls")
		static Umod_glossary_get_glossaries_by_courses* mod_glossary_get_glossaries_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_glossary_prepare_entry_for_edition : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_glossary_prepare_entry_for_edition"), Category = "Moodle API Calls")
		static Umod_glossary_prepare_entry_for_edition* mod_glossary_prepare_entry_for_edition(
			const FString ServerURL,
			const FString Token,
			const int32 _entryid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_glossary_update_entry : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_glossary_update_entry"), Category = "Moodle API Calls")
		static Umod_glossary_update_entry* mod_glossary_update_entry(
			const FString ServerURL,
			const FString Token,
			const int32 _entryid,
			const FString _concept,
			const FString _definition,
			const int32 _definitionformat,
			const FString _optionsname,
			const FString _optionsvalue
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_glossary_view_entry : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_glossary_view_entry"), Category = "Moodle API Calls")
		static Umod_glossary_view_entry* mod_glossary_view_entry(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_glossary_view_glossary : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_glossary_view_glossary"), Category = "Moodle API Calls")
		static Umod_glossary_view_glossary* mod_glossary_view_glossary(
			const FString ServerURL,
			const FString Token,
			const int32 _id,
			const FString _mode
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_h5pactivity_get_attempts : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_h5pactivity_get_attempts"), Category = "Moodle API Calls")
		static Umod_h5pactivity_get_attempts* mod_h5pactivity_get_attempts(
			const FString ServerURL,
			const FString Token,
			const int32 _h5pactivityid,
			const int32 _userids = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_h5pactivity_get_h5pactivities_by_courses : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_h5pactivity_get_h5pactivities_by_courses"), Category = "Moodle API Calls")
		static Umod_h5pactivity_get_h5pactivities_by_courses* mod_h5pactivity_get_h5pactivities_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_h5pactivity_get_h5pactivity_access_information : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_h5pactivity_get_h5pactivity_access_information"), Category = "Moodle API Calls")
		static Umod_h5pactivity_get_h5pactivity_access_information* mod_h5pactivity_get_h5pactivity_access_information(
			const FString ServerURL,
			const FString Token,
			const int32 _h5pactivityid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_h5pactivity_get_results : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_h5pactivity_get_results"), Category = "Moodle API Calls")
		static Umod_h5pactivity_get_results* mod_h5pactivity_get_results(
			const FString ServerURL,
			const FString Token,
			const int32 _h5pactivityid,
			const int32 _attemptids = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_h5pactivity_get_user_attempts : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_h5pactivity_get_user_attempts"), Category = "Moodle API Calls")
		static Umod_h5pactivity_get_user_attempts* mod_h5pactivity_get_user_attempts(
			const FString ServerURL,
			const FString Token,
			const int32 _h5pactivityid,
			const FString _sortorder = "id ASC",
			const int32 _page = -1,
			const int32 _perpage = 0,
			const FString _firstinitial = "",
			const FString _lastinitial = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_h5pactivity_log_report_viewed : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_h5pactivity_log_report_viewed"), Category = "Moodle API Calls")
		static Umod_h5pactivity_log_report_viewed* mod_h5pactivity_log_report_viewed(
			const FString ServerURL,
			const FString Token,
			const int32 _h5pactivityid,
			const int32 _userid = 0,
			const int32 _attemptid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_h5pactivity_view_h5pactivity : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_h5pactivity_view_h5pactivity"), Category = "Moodle API Calls")
		static Umod_h5pactivity_view_h5pactivity* mod_h5pactivity_view_h5pactivity(
			const FString ServerURL,
			const FString Token,
			const int32 _h5pactivityid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_imscp_get_imscps_by_courses : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_imscp_get_imscps_by_courses"), Category = "Moodle API Calls")
		static Umod_imscp_get_imscps_by_courses* mod_imscp_get_imscps_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_imscp_view_imscp : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_imscp_view_imscp"), Category = "Moodle API Calls")
		static Umod_imscp_view_imscp* mod_imscp_view_imscp(
			const FString ServerURL,
			const FString Token,
			const int32 _imscpid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_label_get_labels_by_courses : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_label_get_labels_by_courses"), Category = "Moodle API Calls")
		static Umod_label_get_labels_by_courses* mod_label_get_labels_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_lesson_finish_attempt : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_lesson_finish_attempt"), Category = "Moodle API Calls")
		static Umod_lesson_finish_attempt* mod_lesson_finish_attempt(
			const FString ServerURL,
			const FString Token,
			const int32 _lessonid,
			const FString _password = "",
			const int32 _outoftime = 0,
			const int32 _review = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_lesson_get_attempts_overview : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_lesson_get_attempts_overview"), Category = "Moodle API Calls")
		static Umod_lesson_get_attempts_overview* mod_lesson_get_attempts_overview(
			const FString ServerURL,
			const FString Token,
			const int32 _lessonid,
			const int32 _groupid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_lesson_get_content_pages_viewed : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_lesson_get_content_pages_viewed"), Category = "Moodle API Calls")
		static Umod_lesson_get_content_pages_viewed* mod_lesson_get_content_pages_viewed(
			const FString ServerURL,
			const FString Token,
			const int32 _lessonid,
			const int32 _lessonattempt,
			const int32 _userid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_lesson_get_lesson : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_lesson_get_lesson"), Category = "Moodle API Calls")
		static Umod_lesson_get_lesson* mod_lesson_get_lesson(
			const FString ServerURL,
			const FString Token,
			const int32 _lessonid,
			const FString _password = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_lesson_get_lesson_access_information : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_lesson_get_lesson_access_information"), Category = "Moodle API Calls")
		static Umod_lesson_get_lesson_access_information* mod_lesson_get_lesson_access_information(
			const FString ServerURL,
			const FString Token,
			const int32 _lessonid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_lesson_get_lessons_by_courses : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_lesson_get_lessons_by_courses"), Category = "Moodle API Calls")
		static Umod_lesson_get_lessons_by_courses* mod_lesson_get_lessons_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_lesson_get_page_data : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_lesson_get_page_data"), Category = "Moodle API Calls")
		static Umod_lesson_get_page_data* mod_lesson_get_page_data(
			const FString ServerURL,
			const FString Token,
			const int32 _lessonid,
			const int32 _pageid,
			const FString _password = "",
			const int32 _review = 0,
			const int32 _returncontents = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_lesson_get_pages : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_lesson_get_pages"), Category = "Moodle API Calls")
		static Umod_lesson_get_pages* mod_lesson_get_pages(
			const FString ServerURL,
			const FString Token,
			const int32 _lessonid,
			const FString _password = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_lesson_get_pages_possible_jumps : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_lesson_get_pages_possible_jumps"), Category = "Moodle API Calls")
		static Umod_lesson_get_pages_possible_jumps* mod_lesson_get_pages_possible_jumps(
			const FString ServerURL,
			const FString Token,
			const int32 _lessonid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_lesson_get_questions_attempts : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_lesson_get_questions_attempts"), Category = "Moodle API Calls")
		static Umod_lesson_get_questions_attempts* mod_lesson_get_questions_attempts(
			const FString ServerURL,
			const FString Token,
			const int32 _lessonid,
			const int32 _attempt,
			const int32 _correct = 0,
			const int32 _pageid = 0,
			const int32 _userid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_lesson_get_user_attempt : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_lesson_get_user_attempt"), Category = "Moodle API Calls")
		static Umod_lesson_get_user_attempt* mod_lesson_get_user_attempt(
			const FString ServerURL,
			const FString Token,
			const int32 _lessonid,
			const int32 _userid,
			const int32 _lessonattempt
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_lesson_get_user_attempt_grade : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_lesson_get_user_attempt_grade"), Category = "Moodle API Calls")
		static Umod_lesson_get_user_attempt_grade* mod_lesson_get_user_attempt_grade(
			const FString ServerURL,
			const FString Token,
			const int32 _lessonid,
			const int32 _lessonattempt,
			const int32 _userid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_lesson_get_user_grade : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_lesson_get_user_grade"), Category = "Moodle API Calls")
		static Umod_lesson_get_user_grade* mod_lesson_get_user_grade(
			const FString ServerURL,
			const FString Token,
			const int32 _lessonid,
			const int32 _userid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_lesson_get_user_timers : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_lesson_get_user_timers"), Category = "Moodle API Calls")
		static Umod_lesson_get_user_timers* mod_lesson_get_user_timers(
			const FString ServerURL,
			const FString Token,
			const int32 _lessonid,
			const int32 _userid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_lesson_launch_attempt : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_lesson_launch_attempt"), Category = "Moodle API Calls")
		static Umod_lesson_launch_attempt* mod_lesson_launch_attempt(
			const FString ServerURL,
			const FString Token,
			const int32 _lessonid,
			const FString _password = "",
			const int32 _pageid = 0,
			const int32 _review = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_lesson_process_page : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_lesson_process_page"), Category = "Moodle API Calls")
		static Umod_lesson_process_page* mod_lesson_process_page(
			const FString ServerURL,
			const FString Token,
			const int32 _lessonid,
			const int32 _pageid,
			const FString _dataname,
			const FString _datavalue,
			const FString _password = "",
			const int32 _review = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_lesson_view_lesson : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_lesson_view_lesson"), Category = "Moodle API Calls")
		static Umod_lesson_view_lesson* mod_lesson_view_lesson(
			const FString ServerURL,
			const FString Token,
			const int32 _lessonid,
			const FString _password = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_lti_create_tool_proxy : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_lti_create_tool_proxy"), Category = "Moodle API Calls")
		static Umod_lti_create_tool_proxy* mod_lti_create_tool_proxy(
			const FString ServerURL,
			const FString Token,
			const FString _regurl,
			const FString _name = "",
			const FString _capabilityoffered = "Array ( ) ",
			const FString _serviceoffered = "Array ( ) "
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_lti_create_tool_type : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_lti_create_tool_type"), Category = "Moodle API Calls")
		static Umod_lti_create_tool_type* mod_lti_create_tool_type(
			const FString ServerURL,
			const FString Token,
			const FString _cartridgeurl = "",
			const FString _key = "",
			const FString _secret = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_lti_delete_tool_proxy : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_lti_delete_tool_proxy"), Category = "Moodle API Calls")
		static Umod_lti_delete_tool_proxy* mod_lti_delete_tool_proxy(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_lti_delete_tool_type : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_lti_delete_tool_type"), Category = "Moodle API Calls")
		static Umod_lti_delete_tool_type* mod_lti_delete_tool_type(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_lti_get_ltis_by_courses : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_lti_get_ltis_by_courses"), Category = "Moodle API Calls")
		static Umod_lti_get_ltis_by_courses* mod_lti_get_ltis_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_lti_get_tool_launch_data : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_lti_get_tool_launch_data"), Category = "Moodle API Calls")
		static Umod_lti_get_tool_launch_data* mod_lti_get_tool_launch_data(
			const FString ServerURL,
			const FString Token,
			const int32 _toolid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_lti_get_tool_proxies : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_lti_get_tool_proxies"), Category = "Moodle API Calls")
		static Umod_lti_get_tool_proxies* mod_lti_get_tool_proxies(
			const FString ServerURL,
			const FString Token,
			const int32 _orphanedonly = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_lti_get_tool_proxy_registration_request : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_lti_get_tool_proxy_registration_request"), Category = "Moodle API Calls")
		static Umod_lti_get_tool_proxy_registration_request* mod_lti_get_tool_proxy_registration_request(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_lti_get_tool_types : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_lti_get_tool_types"), Category = "Moodle API Calls")
		static Umod_lti_get_tool_types* mod_lti_get_tool_types(
			const FString ServerURL,
			const FString Token,
			const int32 _toolproxyid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_lti_get_tool_types_and_proxies : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_lti_get_tool_types_and_proxies"), Category = "Moodle API Calls")
		static Umod_lti_get_tool_types_and_proxies* mod_lti_get_tool_types_and_proxies(
			const FString ServerURL,
			const FString Token,
			const int32 _toolproxyid = 0,
			const int32 _orphanedonly = 0,
			const int32 _limit = 60,
			const int32 _offset = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_lti_get_tool_types_and_proxies_count : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_lti_get_tool_types_and_proxies_count"), Category = "Moodle API Calls")
		static Umod_lti_get_tool_types_and_proxies_count* mod_lti_get_tool_types_and_proxies_count(
			const FString ServerURL,
			const FString Token,
			const int32 _toolproxyid = 0,
			const int32 _orphanedonly = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_lti_is_cartridge : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_lti_is_cartridge"), Category = "Moodle API Calls")
		static Umod_lti_is_cartridge* mod_lti_is_cartridge(
			const FString ServerURL,
			const FString Token,
			const FString _url
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_lti_update_tool_type : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_lti_update_tool_type"), Category = "Moodle API Calls")
		static Umod_lti_update_tool_type* mod_lti_update_tool_type(
			const FString ServerURL,
			const FString Token,
			const int32 _id,
			const FString _name = "null",
			const FString _description = "null",
			const int32 _state = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_lti_view_lti : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_lti_view_lti"), Category = "Moodle API Calls")
		static Umod_lti_view_lti* mod_lti_view_lti(
			const FString ServerURL,
			const FString Token,
			const int32 _ltiid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_page_get_pages_by_courses : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_page_get_pages_by_courses"), Category = "Moodle API Calls")
		static Umod_page_get_pages_by_courses* mod_page_get_pages_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_page_view_page : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_page_view_page"), Category = "Moodle API Calls")
		static Umod_page_view_page* mod_page_view_page(
			const FString ServerURL,
			const FString Token,
			const int32 _pageid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_quiz_get_attempt_access_information : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_quiz_get_attempt_access_information"), Category = "Moodle API Calls")
		static Umod_quiz_get_attempt_access_information* mod_quiz_get_attempt_access_information(
			const FString ServerURL,
			const FString Token,
			const int32 _quizid,
			const int32 _attemptid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_quiz_get_attempt_data : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_quiz_get_attempt_data"), Category = "Moodle API Calls")
		static Umod_quiz_get_attempt_data* mod_quiz_get_attempt_data(
			const FString ServerURL,
			const FString Token,
			const int32 _attemptid,
			const int32 _page,
			const FString _preflightdataname,
			const FString _preflightdatavalue
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_quiz_get_attempt_review : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_quiz_get_attempt_review"), Category = "Moodle API Calls")
		static Umod_quiz_get_attempt_review* mod_quiz_get_attempt_review(
			const FString ServerURL,
			const FString Token,
			const int32 _attemptid,
			const int32 _page = -1
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_quiz_get_attempt_summary : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_quiz_get_attempt_summary"), Category = "Moodle API Calls")
		static Umod_quiz_get_attempt_summary* mod_quiz_get_attempt_summary(
			const FString ServerURL,
			const FString Token,
			const int32 _attemptid,
			const FString _preflightdataname,
			const FString _preflightdatavalue
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_quiz_get_combined_review_options : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_quiz_get_combined_review_options"), Category = "Moodle API Calls")
		static Umod_quiz_get_combined_review_options* mod_quiz_get_combined_review_options(
			const FString ServerURL,
			const FString Token,
			const int32 _quizid,
			const int32 _userid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_quiz_get_quiz_access_information : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_quiz_get_quiz_access_information"), Category = "Moodle API Calls")
		static Umod_quiz_get_quiz_access_information* mod_quiz_get_quiz_access_information(
			const FString ServerURL,
			const FString Token,
			const int32 _quizid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_quiz_get_quiz_feedback_for_grade : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_quiz_get_quiz_feedback_for_grade"), Category = "Moodle API Calls")
		static Umod_quiz_get_quiz_feedback_for_grade* mod_quiz_get_quiz_feedback_for_grade(
			const FString ServerURL,
			const FString Token,
			const int32 _quizid,
			const float _grade
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_quiz_get_quiz_required_qtypes : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_quiz_get_quiz_required_qtypes"), Category = "Moodle API Calls")
		static Umod_quiz_get_quiz_required_qtypes* mod_quiz_get_quiz_required_qtypes(
			const FString ServerURL,
			const FString Token,
			const int32 _quizid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_quiz_get_quizzes_by_courses : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_quiz_get_quizzes_by_courses"), Category = "Moodle API Calls")
		static Umod_quiz_get_quizzes_by_courses* mod_quiz_get_quizzes_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_quiz_get_user_attempts : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_quiz_get_user_attempts"), Category = "Moodle API Calls")
		static Umod_quiz_get_user_attempts* mod_quiz_get_user_attempts(
			const FString ServerURL,
			const FString Token,
			const int32 _quizid,
			const int32 _userid = 0,
			const FString _status = "finished",
			const int32 _includepreviews = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_quiz_get_user_best_grade : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_quiz_get_user_best_grade"), Category = "Moodle API Calls")
		static Umod_quiz_get_user_best_grade* mod_quiz_get_user_best_grade(
			const FString ServerURL,
			const FString Token,
			const int32 _quizid,
			const int32 _userid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_quiz_process_attempt : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_quiz_process_attempt"), Category = "Moodle API Calls")
		static Umod_quiz_process_attempt* mod_quiz_process_attempt(
			const FString ServerURL,
			const FString Token,
			const int32 _attemptid,
			const FString _dataname,
			const FString _datavalue,
			const FString _preflightdataname,
			const FString _preflightdatavalue,
			const int32 _finishattempt = 0,
			const int32 _timeup = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_quiz_save_attempt : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_quiz_save_attempt"), Category = "Moodle API Calls")
		static Umod_quiz_save_attempt* mod_quiz_save_attempt(
			const FString ServerURL,
			const FString Token,
			const int32 _attemptid,
			const FString _dataname,
			const FString _datavalue,
			const FString _preflightdataname,
			const FString _preflightdatavalue
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_quiz_set_question_version : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_quiz_set_question_version"), Category = "Moodle API Calls")
		static Umod_quiz_set_question_version* mod_quiz_set_question_version(
			const FString ServerURL,
			const FString Token,
			const int32 _slotid,
			const int32 _newversion
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_quiz_start_attempt : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_quiz_start_attempt"), Category = "Moodle API Calls")
		static Umod_quiz_start_attempt* mod_quiz_start_attempt(
			const FString ServerURL,
			const FString Token,
			const int32 _quizid,
			const FString _preflightdataname,
			const FString _preflightdatavalue,
			const int32 _forcenew = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_quiz_view_attempt : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_quiz_view_attempt"), Category = "Moodle API Calls")
		static Umod_quiz_view_attempt* mod_quiz_view_attempt(
			const FString ServerURL,
			const FString Token,
			const int32 _attemptid,
			const int32 _page,
			const FString _preflightdataname,
			const FString _preflightdatavalue
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_quiz_view_attempt_review : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_quiz_view_attempt_review"), Category = "Moodle API Calls")
		static Umod_quiz_view_attempt_review* mod_quiz_view_attempt_review(
			const FString ServerURL,
			const FString Token,
			const int32 _attemptid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_quiz_view_attempt_summary : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_quiz_view_attempt_summary"), Category = "Moodle API Calls")
		static Umod_quiz_view_attempt_summary* mod_quiz_view_attempt_summary(
			const FString ServerURL,
			const FString Token,
			const int32 _attemptid,
			const FString _preflightdataname,
			const FString _preflightdatavalue
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_quiz_view_quiz : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_quiz_view_quiz"), Category = "Moodle API Calls")
		static Umod_quiz_view_quiz* mod_quiz_view_quiz(
			const FString ServerURL,
			const FString Token,
			const int32 _quizid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_resource_get_resources_by_courses : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_resource_get_resources_by_courses"), Category = "Moodle API Calls")
		static Umod_resource_get_resources_by_courses* mod_resource_get_resources_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_resource_view_resource : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_resource_view_resource"), Category = "Moodle API Calls")
		static Umod_resource_view_resource* mod_resource_view_resource(
			const FString ServerURL,
			const FString Token,
			const int32 _resourceid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_scorm_get_scorm_access_information : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_scorm_get_scorm_access_information"), Category = "Moodle API Calls")
		static Umod_scorm_get_scorm_access_information* mod_scorm_get_scorm_access_information(
			const FString ServerURL,
			const FString Token,
			const int32 _scormid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_scorm_get_scorm_attempt_count : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_scorm_get_scorm_attempt_count"), Category = "Moodle API Calls")
		static Umod_scorm_get_scorm_attempt_count* mod_scorm_get_scorm_attempt_count(
			const FString ServerURL,
			const FString Token,
			const int32 _scormid,
			const int32 _userid,
			const int32 _ignoremissingcompletion = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_scorm_get_scorm_sco_tracks : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_scorm_get_scorm_sco_tracks"), Category = "Moodle API Calls")
		static Umod_scorm_get_scorm_sco_tracks* mod_scorm_get_scorm_sco_tracks(
			const FString ServerURL,
			const FString Token,
			const int32 _scoid,
			const int32 _userid,
			const int32 _attempt = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_scorm_get_scorm_scoes : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_scorm_get_scorm_scoes"), Category = "Moodle API Calls")
		static Umod_scorm_get_scorm_scoes* mod_scorm_get_scorm_scoes(
			const FString ServerURL,
			const FString Token,
			const int32 _scormid,
			const FString _organization = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_scorm_get_scorm_user_data : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_scorm_get_scorm_user_data"), Category = "Moodle API Calls")
		static Umod_scorm_get_scorm_user_data* mod_scorm_get_scorm_user_data(
			const FString ServerURL,
			const FString Token,
			const int32 _scormid,
			const int32 _attempt
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_scorm_get_scorms_by_courses : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_scorm_get_scorms_by_courses"), Category = "Moodle API Calls")
		static Umod_scorm_get_scorms_by_courses* mod_scorm_get_scorms_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_scorm_insert_scorm_tracks : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_scorm_insert_scorm_tracks"), Category = "Moodle API Calls")
		static Umod_scorm_insert_scorm_tracks* mod_scorm_insert_scorm_tracks(
			const FString ServerURL,
			const FString Token,
			const int32 _scoid,
			const int32 _attempt,
			const FString _trackselement,
			const FString _tracksvalue
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_scorm_launch_sco : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_scorm_launch_sco"), Category = "Moodle API Calls")
		static Umod_scorm_launch_sco* mod_scorm_launch_sco(
			const FString ServerURL,
			const FString Token,
			const int32 _scormid,
			const int32 _scoid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_scorm_view_scorm : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_scorm_view_scorm"), Category = "Moodle API Calls")
		static Umod_scorm_view_scorm* mod_scorm_view_scorm(
			const FString ServerURL,
			const FString Token,
			const int32 _scormid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_survey_get_questions : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_survey_get_questions"), Category = "Moodle API Calls")
		static Umod_survey_get_questions* mod_survey_get_questions(
			const FString ServerURL,
			const FString Token,
			const int32 _surveyid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_survey_get_surveys_by_courses : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_survey_get_surveys_by_courses"), Category = "Moodle API Calls")
		static Umod_survey_get_surveys_by_courses* mod_survey_get_surveys_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_survey_submit_answers : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_survey_submit_answers"), Category = "Moodle API Calls")
		static Umod_survey_submit_answers* mod_survey_submit_answers(
			const FString ServerURL,
			const FString Token,
			const int32 _surveyid,
			const FString _answerskey,
			const FString _answersvalue
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_survey_view_survey : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_survey_view_survey"), Category = "Moodle API Calls")
		static Umod_survey_view_survey* mod_survey_view_survey(
			const FString ServerURL,
			const FString Token,
			const int32 _surveyid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_url_get_urls_by_courses : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_url_get_urls_by_courses"), Category = "Moodle API Calls")
		static Umod_url_get_urls_by_courses* mod_url_get_urls_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_url_view_url : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_url_view_url"), Category = "Moodle API Calls")
		static Umod_url_view_url* mod_url_view_url(
			const FString ServerURL,
			const FString Token,
			const int32 _urlid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_wiki_edit_page : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_wiki_edit_page"), Category = "Moodle API Calls")
		static Umod_wiki_edit_page* mod_wiki_edit_page(
			const FString ServerURL,
			const FString Token,
			const int32 _pageid,
			const FString _content,
			const FString _section = "null"
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_wiki_get_page_contents : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_wiki_get_page_contents"), Category = "Moodle API Calls")
		static Umod_wiki_get_page_contents* mod_wiki_get_page_contents(
			const FString ServerURL,
			const FString Token,
			const int32 _pageid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_wiki_get_page_for_editing : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_wiki_get_page_for_editing"), Category = "Moodle API Calls")
		static Umod_wiki_get_page_for_editing* mod_wiki_get_page_for_editing(
			const FString ServerURL,
			const FString Token,
			const int32 _pageid,
			const FString _section = "null",
			const int32 _lockonly = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_wiki_get_subwiki_files : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_wiki_get_subwiki_files"), Category = "Moodle API Calls")
		static Umod_wiki_get_subwiki_files* mod_wiki_get_subwiki_files(
			const FString ServerURL,
			const FString Token,
			const int32 _wikiid,
			const int32 _groupid = -1,
			const int32 _userid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_wiki_get_subwiki_pages : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_wiki_get_subwiki_pages"), Category = "Moodle API Calls")
		static Umod_wiki_get_subwiki_pages* mod_wiki_get_subwiki_pages(
			const FString ServerURL,
			const FString Token,
			const int32 _wikiid,
			const int32 _groupid = -1,
			const int32 _userid = 0,
			const FString _optionssortby = "title",
			const FString _optionssortdirection = "ASC",
			const int32 _optionsincludecontent = 1
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_wiki_get_subwikis : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_wiki_get_subwikis"), Category = "Moodle API Calls")
		static Umod_wiki_get_subwikis* mod_wiki_get_subwikis(
			const FString ServerURL,
			const FString Token,
			const int32 _wikiid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_wiki_get_wikis_by_courses : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_wiki_get_wikis_by_courses"), Category = "Moodle API Calls")
		static Umod_wiki_get_wikis_by_courses* mod_wiki_get_wikis_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_wiki_new_page : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_wiki_new_page"), Category = "Moodle API Calls")
		static Umod_wiki_new_page* mod_wiki_new_page(
			const FString ServerURL,
			const FString Token,
			const FString _title,
			const FString _content = "null",
			const FString _contentformat = "null",
			const int32 _subwikiid = 0,
			const int32 _wikiid = 0,
			const int32 _userid = 0,
			const int32 _groupid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_wiki_view_page : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_wiki_view_page"), Category = "Moodle API Calls")
		static Umod_wiki_view_page* mod_wiki_view_page(
			const FString ServerURL,
			const FString Token,
			const int32 _pageid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_wiki_view_wiki : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_wiki_view_wiki"), Category = "Moodle API Calls")
		static Umod_wiki_view_wiki* mod_wiki_view_wiki(
			const FString ServerURL,
			const FString Token,
			const int32 _wikiid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_workshop_add_submission : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_workshop_add_submission"), Category = "Moodle API Calls")
		static Umod_workshop_add_submission* mod_workshop_add_submission(
			const FString ServerURL,
			const FString Token,
			const int32 _workshopid,
			const FString _title,
			const FString _content = "0",
			const int32 _contentformat = 0,
			const int32 _inlineattachmentsid = 0,
			const int32 _attachmentsid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_workshop_delete_submission : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_workshop_delete_submission"), Category = "Moodle API Calls")
		static Umod_workshop_delete_submission* mod_workshop_delete_submission(
			const FString ServerURL,
			const FString Token,
			const int32 _submissionid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_workshop_evaluate_assessment : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_workshop_evaluate_assessment"), Category = "Moodle API Calls")
		static Umod_workshop_evaluate_assessment* mod_workshop_evaluate_assessment(
			const FString ServerURL,
			const FString Token,
			const int32 _assessmentid,
			const FString _feedbacktext = "",
			const int32 _feedbackformat = 0,
			const int32 _weight = 1,
			const FString _gradinggradeover = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_workshop_evaluate_submission : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_workshop_evaluate_submission"), Category = "Moodle API Calls")
		static Umod_workshop_evaluate_submission* mod_workshop_evaluate_submission(
			const FString ServerURL,
			const FString Token,
			const int32 _submissionid,
			const FString _feedbacktext = "",
			const int32 _feedbackformat = 0,
			const int32 _published = 0,
			const FString _gradeover = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_workshop_get_assessment : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_workshop_get_assessment"), Category = "Moodle API Calls")
		static Umod_workshop_get_assessment* mod_workshop_get_assessment(
			const FString ServerURL,
			const FString Token,
			const int32 _assessmentid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_workshop_get_assessment_form_definition : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_workshop_get_assessment_form_definition"), Category = "Moodle API Calls")
		static Umod_workshop_get_assessment_form_definition* mod_workshop_get_assessment_form_definition(
			const FString ServerURL,
			const FString Token,
			const int32 _assessmentid,
			const FString _mode = "assessment"
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_workshop_get_grades : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_workshop_get_grades"), Category = "Moodle API Calls")
		static Umod_workshop_get_grades* mod_workshop_get_grades(
			const FString ServerURL,
			const FString Token,
			const int32 _workshopid,
			const int32 _userid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_workshop_get_grades_report : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_workshop_get_grades_report"), Category = "Moodle API Calls")
		static Umod_workshop_get_grades_report* mod_workshop_get_grades_report(
			const FString ServerURL,
			const FString Token,
			const int32 _workshopid,
			const int32 _groupid = 0,
			const FString _sortby = "lastname",
			const FString _sortdirection = "ASC",
			const int32 _page = 0,
			const int32 _perpage = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_workshop_get_reviewer_assessments : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_workshop_get_reviewer_assessments"), Category = "Moodle API Calls")
		static Umod_workshop_get_reviewer_assessments* mod_workshop_get_reviewer_assessments(
			const FString ServerURL,
			const FString Token,
			const int32 _workshopid,
			const int32 _userid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_workshop_get_submission : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_workshop_get_submission"), Category = "Moodle API Calls")
		static Umod_workshop_get_submission* mod_workshop_get_submission(
			const FString ServerURL,
			const FString Token,
			const int32 _submissionid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_workshop_get_submission_assessments : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_workshop_get_submission_assessments"), Category = "Moodle API Calls")
		static Umod_workshop_get_submission_assessments* mod_workshop_get_submission_assessments(
			const FString ServerURL,
			const FString Token,
			const int32 _submissionid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_workshop_get_submissions : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_workshop_get_submissions"), Category = "Moodle API Calls")
		static Umod_workshop_get_submissions* mod_workshop_get_submissions(
			const FString ServerURL,
			const FString Token,
			const int32 _workshopid,
			const int32 _userid = 0,
			const int32 _groupid = 0,
			const int32 _page = 0,
			const int32 _perpage = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_workshop_get_user_plan : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_workshop_get_user_plan"), Category = "Moodle API Calls")
		static Umod_workshop_get_user_plan* mod_workshop_get_user_plan(
			const FString ServerURL,
			const FString Token,
			const int32 _workshopid,
			const int32 _userid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_workshop_get_workshop_access_information : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_workshop_get_workshop_access_information"), Category = "Moodle API Calls")
		static Umod_workshop_get_workshop_access_information* mod_workshop_get_workshop_access_information(
			const FString ServerURL,
			const FString Token,
			const int32 _workshopid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_workshop_get_workshops_by_courses : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_workshop_get_workshops_by_courses"), Category = "Moodle API Calls")
		static Umod_workshop_get_workshops_by_courses* mod_workshop_get_workshops_by_courses(
			const FString ServerURL,
			const FString Token,
			const int32 _courseids = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_workshop_update_assessment : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_workshop_update_assessment"), Category = "Moodle API Calls")
		static Umod_workshop_update_assessment* mod_workshop_update_assessment(
			const FString ServerURL,
			const FString Token,
			const int32 _assessmentid,
			const FString _dataname,
			const FString _datavalue
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_workshop_update_submission : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_workshop_update_submission"), Category = "Moodle API Calls")
		static Umod_workshop_update_submission* mod_workshop_update_submission(
			const FString ServerURL,
			const FString Token,
			const int32 _submissionid,
			const FString _title,
			const FString _content = "0",
			const int32 _contentformat = 0,
			const int32 _inlineattachmentsid = 0,
			const int32 _attachmentsid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_workshop_view_submission : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_workshop_view_submission"), Category = "Moodle API Calls")
		static Umod_workshop_view_submission* mod_workshop_view_submission(
			const FString ServerURL,
			const FString Token,
			const int32 _submissionid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Umod_workshop_view_workshop : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "mod_workshop_view_workshop"), Category = "Moodle API Calls")
		static Umod_workshop_view_workshop* mod_workshop_view_workshop(
			const FString ServerURL,
			const FString Token,
			const int32 _workshopid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Upaygw_paypal_create_transaction_complete : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "paygw_paypal_create_transaction_complete"), Category = "Moodle API Calls")
		static Upaygw_paypal_create_transaction_complete* paygw_paypal_create_transaction_complete(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const FString _paymentarea,
			const int32 _itemid,
			const FString _orderid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Upaygw_paypal_get_config_for_js : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "paygw_paypal_get_config_for_js"), Category = "Moodle API Calls")
		static Upaygw_paypal_get_config_for_js* paygw_paypal_get_config_for_js(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const FString _paymentarea,
			const int32 _itemid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Uqbank_columnsortorder_set_columnbank_order : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "qbank_columnsortorder_set_columnbank_order"), Category = "Moodle API Calls")
		static Uqbank_columnsortorder_set_columnbank_order* qbank_columnsortorder_set_columnbank_order(
			const FString ServerURL,
			const FString Token,
			const FString _columns
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Uqbank_editquestion_set_status : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "qbank_editquestion_set_status"), Category = "Moodle API Calls")
		static Uqbank_editquestion_set_status* qbank_editquestion_set_status(
			const FString ServerURL,
			const FString Token,
			const int32 _questionid,
			const FString _status
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Uqbank_tagquestion_submit_tags_form : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "qbank_tagquestion_submit_tags_form"), Category = "Moodle API Calls")
		static Uqbank_tagquestion_submit_tags_form* qbank_tagquestion_submit_tags_form(
			const FString ServerURL,
			const FString Token,
			const int32 _questionid,
			const int32 _contextid,
			const FString _formdata
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Uquizaccess_seb_validate_quiz_keys : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "quizaccess_seb_validate_quiz_keys"), Category = "Moodle API Calls")
		static Uquizaccess_seb_validate_quiz_keys* quizaccess_seb_validate_quiz_keys(
			const FString ServerURL,
			const FString Token,
			const int32 _cmid,
			const FString _url,
			const FString _configkey = "null",
			const FString _browserexamkey = "null"
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ureport_competency_data_for_report : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "report_competency_data_for_report"), Category = "Moodle API Calls")
		static Ureport_competency_data_for_report* report_competency_data_for_report(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _userid,
			const int32 _moduleid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Ureport_insights_action_executed : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "report_insights_action_executed"), Category = "Moodle API Calls")
		static Ureport_insights_action_executed* report_insights_action_executed(
			const FString ServerURL,
			const FString Token,
			const FString _actionname,
			const int32 _predictionids
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utiny_autosave_reset_session : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tiny_autosave_reset_session"), Category = "Moodle API Calls")
		static Utiny_autosave_reset_session* tiny_autosave_reset_session(
			const FString ServerURL,
			const FString Token,
			const int32 _contextid,
			const FString _pagehash,
			const FString _pageinstance,
			const FString _elementid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utiny_autosave_resume_session : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tiny_autosave_resume_session"), Category = "Moodle API Calls")
		static Utiny_autosave_resume_session* tiny_autosave_resume_session(
			const FString ServerURL,
			const FString Token,
			const int32 _contextid,
			const FString _pagehash,
			const FString _pageinstance,
			const FString _elementid,
			const int32 _draftid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utiny_autosave_update_session : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tiny_autosave_update_session"), Category = "Moodle API Calls")
		static Utiny_autosave_update_session* tiny_autosave_update_session(
			const FString ServerURL,
			const FString Token,
			const int32 _contextid,
			const FString _pagehash,
			const FString _pageinstance,
			const FString _elementid,
			const FString _drafttext
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utiny_equation_filter : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tiny_equation_filter"), Category = "Moodle API Calls")
		static Utiny_equation_filter* tiny_equation_filter(
			const FString ServerURL,
			const FString Token,
			const int32 _contextid,
			const FString _content
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_analytics_potential_contexts : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_analytics_potential_contexts"), Category = "Moodle API Calls")
		static Utool_analytics_potential_contexts* tool_analytics_potential_contexts(
			const FString ServerURL,
			const FString Token,
			const FString _query = "null",
			const int32 _modelid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_behat_get_entity_generator : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_behat_get_entity_generator"), Category = "Moodle API Calls")
		static Utool_behat_get_entity_generator* tool_behat_get_entity_generator(
			const FString ServerURL,
			const FString Token,
			const FString _entitytype
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_dataprivacy_approve_data_request : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_dataprivacy_approve_data_request"), Category = "Moodle API Calls")
		static Utool_dataprivacy_approve_data_request* tool_dataprivacy_approve_data_request(
			const FString ServerURL,
			const FString Token,
			const int32 _requestid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_dataprivacy_bulk_approve_data_requests : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_dataprivacy_bulk_approve_data_requests"), Category = "Moodle API Calls")
		static Utool_dataprivacy_bulk_approve_data_requests* tool_dataprivacy_bulk_approve_data_requests(
			const FString ServerURL,
			const FString Token,
			const int32 _requestids
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_dataprivacy_bulk_deny_data_requests : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_dataprivacy_bulk_deny_data_requests"), Category = "Moodle API Calls")
		static Utool_dataprivacy_bulk_deny_data_requests* tool_dataprivacy_bulk_deny_data_requests(
			const FString ServerURL,
			const FString Token,
			const int32 _requestids
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_dataprivacy_cancel_data_request : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_dataprivacy_cancel_data_request"), Category = "Moodle API Calls")
		static Utool_dataprivacy_cancel_data_request* tool_dataprivacy_cancel_data_request(
			const FString ServerURL,
			const FString Token,
			const int32 _requestid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_dataprivacy_confirm_contexts_for_deletion : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_dataprivacy_confirm_contexts_for_deletion"), Category = "Moodle API Calls")
		static Utool_dataprivacy_confirm_contexts_for_deletion* tool_dataprivacy_confirm_contexts_for_deletion(
			const FString ServerURL,
			const FString Token,
			const int32 _ids = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_dataprivacy_contact_dpo : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_dataprivacy_contact_dpo"), Category = "Moodle API Calls")
		static Utool_dataprivacy_contact_dpo* tool_dataprivacy_contact_dpo(
			const FString ServerURL,
			const FString Token,
			const FString _message
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_dataprivacy_create_category_form : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_dataprivacy_create_category_form"), Category = "Moodle API Calls")
		static Utool_dataprivacy_create_category_form* tool_dataprivacy_create_category_form(
			const FString ServerURL,
			const FString Token,
			const FString _jsonformdata
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_dataprivacy_create_purpose_form : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_dataprivacy_create_purpose_form"), Category = "Moodle API Calls")
		static Utool_dataprivacy_create_purpose_form* tool_dataprivacy_create_purpose_form(
			const FString ServerURL,
			const FString Token,
			const FString _jsonformdata
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_dataprivacy_delete_category : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_dataprivacy_delete_category"), Category = "Moodle API Calls")
		static Utool_dataprivacy_delete_category* tool_dataprivacy_delete_category(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_dataprivacy_delete_purpose : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_dataprivacy_delete_purpose"), Category = "Moodle API Calls")
		static Utool_dataprivacy_delete_purpose* tool_dataprivacy_delete_purpose(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_dataprivacy_deny_data_request : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_dataprivacy_deny_data_request"), Category = "Moodle API Calls")
		static Utool_dataprivacy_deny_data_request* tool_dataprivacy_deny_data_request(
			const FString ServerURL,
			const FString Token,
			const int32 _requestid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_dataprivacy_get_activity_options : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_dataprivacy_get_activity_options"), Category = "Moodle API Calls")
		static Utool_dataprivacy_get_activity_options* tool_dataprivacy_get_activity_options(
			const FString ServerURL,
			const FString Token,
			const int32 _nodefaults = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_dataprivacy_get_category_options : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_dataprivacy_get_category_options"), Category = "Moodle API Calls")
		static Utool_dataprivacy_get_category_options* tool_dataprivacy_get_category_options(
			const FString ServerURL,
			const FString Token,
			const int32 _includeinherit = 1,
			const int32 _includenotset = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_dataprivacy_get_data_request : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_dataprivacy_get_data_request"), Category = "Moodle API Calls")
		static Utool_dataprivacy_get_data_request* tool_dataprivacy_get_data_request(
			const FString ServerURL,
			const FString Token,
			const int32 _requestid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_dataprivacy_get_purpose_options : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_dataprivacy_get_purpose_options"), Category = "Moodle API Calls")
		static Utool_dataprivacy_get_purpose_options* tool_dataprivacy_get_purpose_options(
			const FString ServerURL,
			const FString Token,
			const int32 _includeinherit = 1,
			const int32 _includenotset = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_dataprivacy_get_users : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_dataprivacy_get_users"), Category = "Moodle API Calls")
		static Utool_dataprivacy_get_users* tool_dataprivacy_get_users(
			const FString ServerURL,
			const FString Token,
			const FString _query
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_dataprivacy_mark_complete : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_dataprivacy_mark_complete"), Category = "Moodle API Calls")
		static Utool_dataprivacy_mark_complete* tool_dataprivacy_mark_complete(
			const FString ServerURL,
			const FString Token,
			const int32 _requestid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_dataprivacy_set_context_defaults : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_dataprivacy_set_context_defaults"), Category = "Moodle API Calls")
		static Utool_dataprivacy_set_context_defaults* tool_dataprivacy_set_context_defaults(
			const FString ServerURL,
			const FString Token,
			const int32 _contextlevel,
			const int32 _category,
			const int32 _purpose,
			const FString _activity = "null",
			const int32 _override = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_dataprivacy_set_context_form : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_dataprivacy_set_context_form"), Category = "Moodle API Calls")
		static Utool_dataprivacy_set_context_form* tool_dataprivacy_set_context_form(
			const FString ServerURL,
			const FString Token,
			const FString _jsonformdata
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_dataprivacy_set_contextlevel_form : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_dataprivacy_set_contextlevel_form"), Category = "Moodle API Calls")
		static Utool_dataprivacy_set_contextlevel_form* tool_dataprivacy_set_contextlevel_form(
			const FString ServerURL,
			const FString Token,
			const FString _jsonformdata
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_dataprivacy_tree_extra_branches : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_dataprivacy_tree_extra_branches"), Category = "Moodle API Calls")
		static Utool_dataprivacy_tree_extra_branches* tool_dataprivacy_tree_extra_branches(
			const FString ServerURL,
			const FString Token,
			const int32 _contextid,
			const FString _element
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_lp_data_for_competencies_manage_page : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_lp_data_for_competencies_manage_page"), Category = "Moodle API Calls")
		static Utool_lp_data_for_competencies_manage_page* tool_lp_data_for_competencies_manage_page(
			const FString ServerURL,
			const FString Token,
			const int32 _competencyframeworkid,
			const FString _search = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_lp_data_for_competency_frameworks_manage_page : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_lp_data_for_competency_frameworks_manage_page"), Category = "Moodle API Calls")
		static Utool_lp_data_for_competency_frameworks_manage_page* tool_lp_data_for_competency_frameworks_manage_page(
			const FString ServerURL,
			const FString Token,
			const int32 _pagecontextcontextid = 0,
			const FString _pagecontextcontextlevel = "",
			const int32 _pagecontextinstanceid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_lp_data_for_competency_summary : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_lp_data_for_competency_summary"), Category = "Moodle API Calls")
		static Utool_lp_data_for_competency_summary* tool_lp_data_for_competency_summary(
			const FString ServerURL,
			const FString Token,
			const int32 _competencyid,
			const int32 _includerelated = 0,
			const int32 _includecourses = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_lp_data_for_course_competencies_page : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_lp_data_for_course_competencies_page"), Category = "Moodle API Calls")
		static Utool_lp_data_for_course_competencies_page* tool_lp_data_for_course_competencies_page(
			const FString ServerURL,
			const FString Token,
			const int32 _courseid,
			const int32 _moduleid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_lp_data_for_plan_page : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_lp_data_for_plan_page"), Category = "Moodle API Calls")
		static Utool_lp_data_for_plan_page* tool_lp_data_for_plan_page(
			const FString ServerURL,
			const FString Token,
			const int32 _planid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_lp_data_for_plans_page : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_lp_data_for_plans_page"), Category = "Moodle API Calls")
		static Utool_lp_data_for_plans_page* tool_lp_data_for_plans_page(
			const FString ServerURL,
			const FString Token,
			const int32 _userid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_lp_data_for_related_competencies_section : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_lp_data_for_related_competencies_section"), Category = "Moodle API Calls")
		static Utool_lp_data_for_related_competencies_section* tool_lp_data_for_related_competencies_section(
			const FString ServerURL,
			const FString Token,
			const int32 _competencyid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_lp_data_for_template_competencies_page : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_lp_data_for_template_competencies_page"), Category = "Moodle API Calls")
		static Utool_lp_data_for_template_competencies_page* tool_lp_data_for_template_competencies_page(
			const FString ServerURL,
			const FString Token,
			const int32 _templateid,
			const int32 _pagecontextcontextid = 0,
			const FString _pagecontextcontextlevel = "",
			const int32 _pagecontextinstanceid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_lp_data_for_templates_manage_page : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_lp_data_for_templates_manage_page"), Category = "Moodle API Calls")
		static Utool_lp_data_for_templates_manage_page* tool_lp_data_for_templates_manage_page(
			const FString ServerURL,
			const FString Token,
			const int32 _pagecontextcontextid = 0,
			const FString _pagecontextcontextlevel = "",
			const int32 _pagecontextinstanceid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_lp_data_for_user_competency_summary : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_lp_data_for_user_competency_summary"), Category = "Moodle API Calls")
		static Utool_lp_data_for_user_competency_summary* tool_lp_data_for_user_competency_summary(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _competencyid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_lp_data_for_user_competency_summary_in_course : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_lp_data_for_user_competency_summary_in_course"), Category = "Moodle API Calls")
		static Utool_lp_data_for_user_competency_summary_in_course* tool_lp_data_for_user_competency_summary_in_course(
			const FString ServerURL,
			const FString Token,
			const int32 _userid,
			const int32 _competencyid,
			const int32 _courseid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_lp_data_for_user_competency_summary_in_plan : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_lp_data_for_user_competency_summary_in_plan"), Category = "Moodle API Calls")
		static Utool_lp_data_for_user_competency_summary_in_plan* tool_lp_data_for_user_competency_summary_in_plan(
			const FString ServerURL,
			const FString Token,
			const int32 _competencyid,
			const int32 _planid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_lp_data_for_user_evidence_list_page : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_lp_data_for_user_evidence_list_page"), Category = "Moodle API Calls")
		static Utool_lp_data_for_user_evidence_list_page* tool_lp_data_for_user_evidence_list_page(
			const FString ServerURL,
			const FString Token,
			const int32 _userid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_lp_data_for_user_evidence_page : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_lp_data_for_user_evidence_page"), Category = "Moodle API Calls")
		static Utool_lp_data_for_user_evidence_page* tool_lp_data_for_user_evidence_page(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_lp_list_courses_using_competency : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_lp_list_courses_using_competency"), Category = "Moodle API Calls")
		static Utool_lp_list_courses_using_competency* tool_lp_list_courses_using_competency(
			const FString ServerURL,
			const FString Token,
			const int32 _id
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_lp_search_cohorts : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_lp_search_cohorts"), Category = "Moodle API Calls")
		static Utool_lp_search_cohorts* tool_lp_search_cohorts(
			const FString ServerURL,
			const FString Token,
			const FString _query,
			const int32 _contextcontextid = 0,
			const FString _contextcontextlevel = "",
			const int32 _contextinstanceid = 0,
			const FString _includes = "parents",
			const int32 _limitfrom = 0,
			const int32 _limitnum = 25
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_lp_search_users : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_lp_search_users"), Category = "Moodle API Calls")
		static Utool_lp_search_users* tool_lp_search_users(
			const FString ServerURL,
			const FString Token,
			const FString _query,
			const FString _capability,
			const int32 _limitfrom = 0,
			const FString _limitnum = "100"
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_mobile_call_external_functions : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_mobile_call_external_functions"), Category = "Moodle API Calls")
		static Utool_mobile_call_external_functions* tool_mobile_call_external_functions(
			const FString ServerURL,
			const FString Token,
			const FString _requestsfunction,
			const FString _requestsarguments = "{}",
			const int32 _requestssettingraw = 0,
			const int32 _requestssettingfilter = 0,
			const int32 _requestssettingfileurl = 1,
			const FString _requestssettinglang = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_mobile_get_autologin_key : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_mobile_get_autologin_key"), Category = "Moodle API Calls")
		static Utool_mobile_get_autologin_key* tool_mobile_get_autologin_key(
			const FString ServerURL,
			const FString Token,
			const FString _privatetoken
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_mobile_get_config : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_mobile_get_config"), Category = "Moodle API Calls")
		static Utool_mobile_get_config* tool_mobile_get_config(
			const FString ServerURL,
			const FString Token,
			const FString _section = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_mobile_get_content : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_mobile_get_content"), Category = "Moodle API Calls")
		static Utool_mobile_get_content* tool_mobile_get_content(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const FString _method = "",
			const FString _argsname = "",
			const FString _argsvalue = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_mobile_get_plugins_supporting_mobile : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_mobile_get_plugins_supporting_mobile"), Category = "Moodle API Calls")
		static Utool_mobile_get_plugins_supporting_mobile* tool_mobile_get_plugins_supporting_mobile(
			const FString ServerURL,
			const FString Token
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_mobile_get_public_config : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_mobile_get_public_config"), Category = "Moodle API Calls")
		static Utool_mobile_get_public_config* tool_mobile_get_public_config(
			const FString ServerURL,
			const FString Token
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_mobile_get_tokens_for_qr_login : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_mobile_get_tokens_for_qr_login"), Category = "Moodle API Calls")
		static Utool_mobile_get_tokens_for_qr_login* tool_mobile_get_tokens_for_qr_login(
			const FString ServerURL,
			const FString Token,
			const FString _qrloginkey,
			const int32 _userid
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_mobile_validate_subscription_key : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_mobile_validate_subscription_key"), Category = "Moodle API Calls")
		static Utool_mobile_validate_subscription_key* tool_mobile_validate_subscription_key(
			const FString ServerURL,
			const FString Token,
			const FString _key
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_moodlenet_search_courses : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_moodlenet_search_courses"), Category = "Moodle API Calls")
		static Utool_moodlenet_search_courses* tool_moodlenet_search_courses(
			const FString ServerURL,
			const FString Token,
			const FString _searchvalue
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_moodlenet_verify_webfinger : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_moodlenet_verify_webfinger"), Category = "Moodle API Calls")
		static Utool_moodlenet_verify_webfinger* tool_moodlenet_verify_webfinger(
			const FString ServerURL,
			const FString Token,
			const FString _profileurl,
			const int32 _course,
			const int32 _section
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_policy_get_policy_version : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_policy_get_policy_version"), Category = "Moodle API Calls")
		static Utool_policy_get_policy_version* tool_policy_get_policy_version(
			const FString ServerURL,
			const FString Token,
			const int32 _versionid,
			const int32 _behalfid = 0
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_policy_submit_accept_on_behalf : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_policy_submit_accept_on_behalf"), Category = "Moodle API Calls")
		static Utool_policy_submit_accept_on_behalf* tool_policy_submit_accept_on_behalf(
			const FString ServerURL,
			const FString Token,
			const FString _jsonformdata
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_templatelibrary_list_templates : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_templatelibrary_list_templates"), Category = "Moodle API Calls")
		static Utool_templatelibrary_list_templates* tool_templatelibrary_list_templates(
			const FString ServerURL,
			const FString Token,
			const FString _component = "",
			const FString _search = "",
			const FString _themename = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_templatelibrary_load_canonical_template : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_templatelibrary_load_canonical_template"), Category = "Moodle API Calls")
		static Utool_templatelibrary_load_canonical_template* tool_templatelibrary_load_canonical_template(
			const FString ServerURL,
			const FString Token,
			const FString _component,
			const FString _template
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_usertours_complete_tour : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_usertours_complete_tour"), Category = "Moodle API Calls")
		static Utool_usertours_complete_tour* tool_usertours_complete_tour(
			const FString ServerURL,
			const FString Token,
			const int32 _tourid,
			const int32 _context,
			const FString _pageurl,
			const int32 _stepid,
			const int32 _stepindex
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_usertours_fetch_and_start_tour : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_usertours_fetch_and_start_tour"), Category = "Moodle API Calls")
		static Utool_usertours_fetch_and_start_tour* tool_usertours_fetch_and_start_tour(
			const FString ServerURL,
			const FString Token,
			const int32 _tourid,
			const int32 _context,
			const FString _pageurl
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_usertours_reset_tour : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_usertours_reset_tour"), Category = "Moodle API Calls")
		static Utool_usertours_reset_tour* tool_usertours_reset_tour(
			const FString ServerURL,
			const FString Token,
			const int32 _tourid,
			const int32 _context,
			const FString _pageurl
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_usertours_step_shown : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_usertours_step_shown"), Category = "Moodle API Calls")
		static Utool_usertours_step_shown* tool_usertours_step_shown(
			const FString ServerURL,
			const FString Token,
			const int32 _tourid,
			const int32 _context,
			const FString _pageurl,
			const int32 _stepid,
			const int32 _stepindex
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

UCLASS()
class MOODLEAPIWRAPPER_API Utool_xmldb_invoke_move_action : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	TSharedPtr<IHttpRequest> APIRequest;
	void OnServerAnswer(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	public:
		UFUNCTION(BlueprintCallable, meta = (AdvancedDisplay = "2", DisplayName = "tool_xmldb_invoke_move_action"), Category = "Moodle API Calls")
		static Utool_xmldb_invoke_move_action* tool_xmldb_invoke_move_action(
			const FString ServerURL,
			const FString Token,
			const FString _action,
			const FString _dir,
			const FString _table,
			const int32 _position,
			const FString _field = "",
			const FString _key = "",
			const FString _index = ""
		);

		virtual void Activate() override;

		UPROPERTY(BlueprintAssignable, Category = "Moodle API Calls")
		FAPICallOutputPin Finished;
};

