#include <Zola/Objects/ChatMemberRestricted.hpp>

using namespace Zola;
using namespace Zola::Objects;
using namespace nlohmann;

ChatMemberRestricted::ChatMemberRestricted() {
	status = Status::restricted;
}

ChatMemberRestricted::ChatMemberRestricted(const json &data) {
	status = Status::restricted;
	user = User(data["user"]);
	is_member = data["is_member"];
	can_send_message = data["can_send_message"];
	can_send_audio = data["can_send_audio"];
	can_send_document = data["can_send_document"];
	can_send_photos = data["can_send_photos"];
	can_send_video = data["can_send_video"];
	can_send_video_notes = data["can_send_video_notes"];
	can_send_voice_notes = data["can_send_voice_notes"];
	can_send_polls = data["can_send_polls"];
	can_send_other_messages = data["can_send_other_messages"];
	can_add_web_page_previews = data["can_add_web_page_previews"];
	can_change_info = data["can_change_info"];
	can_invite_users = data["can_invite_users"];
	can_pin_messages = data["can_pin_messages"];
	can_manage_topics = data["can_manage_topics"];
	until_date = data["until_date"];
}

json ChatMemberRestricted::toJson() const {
	json data;
	data["status"] = status;
	data["user"] = user.toJson();
	data["is_member"] = is_member;
	data["can_send_message"] = can_send_message;
	data["can_send_audio"] = can_send_audio;
	data["can_send_document"] = can_send_document;
	data["can_send_photos"] = can_send_photos;
	data["can_send_video"] = can_send_video;
	data["can_send_video_notes"] = can_send_video_notes;
	data["can_send_voice_notes"] = can_send_voice_notes;
	data["can_send_polls"] = can_send_polls;
	data["can_send_other_messages"] = can_send_other_messages;
	data["can_add_web_page_previews"] = can_add_web_page_previews;
	data["can_change_info"] = can_change_info;
	data["can_invite_users"] = can_invite_users;
	data["can_pin_messages"] = can_pin_messages;
	data["can_manage_topics"] = can_manage_topics;
	data["until_date"] = until_date;
	return data;
}

