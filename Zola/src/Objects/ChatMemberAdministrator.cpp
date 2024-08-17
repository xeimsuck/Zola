#include <Zola/Objects/ChatMemberAdministrator.hpp>

using namespace Zola;
using namespace Zola::Objects;
using namespace nlohmann;

ChatMemberAdministrator::ChatMemberAdministrator() {
	status = Status::administrator;
}

ChatMemberAdministrator::ChatMemberAdministrator(const json &data) {
	status = Status::administrator;
	user = User(data["user"]);
	is_anonymous = data["is_anonymous"];
	can_be_edited = data["can_be_edited"];
	can_manage_chat = data["can_manage_chat"];
	can_delete_messages = data["can_delete_messages"];
	can_manage_video_chats = data["can_manage_video_chats"];
	can_restrict_members = data["can_restrict_members"];
	can_promote_members = data["can_promote_members"];
	can_change_info = data["can_change_info"];
	can_invite_users = data["can_invite_users"];
	can_post_stories = data["can_post_stories"];
	can_edit_stories = data["can_edit_stories"];
	can_delete_stories = data["can_delete_stories"];
	if(data.contains("can_post_messages")) can_post_messages = data["can_post_messages"];
	if(data.contains("can_edit_messages")) can_edit_messages = data["can_edit_messages"];
	if(data.contains("can_pin_messages")) can_pin_messages = data["can_pin_messages"];
	if(data.contains("can_manage_topics")) can_manage_topics = data["can_manage_topics"];
	if(data.contains("custom_title")) custom_title = data["custom_title"];
}

json ChatMemberAdministrator::toJson() const {
	json data;
	data["status"] = "administrator";
	data["user"] = user.toJson();
	data["is_anonymous"] = is_anonymous;
	data["can_be_edited"] = can_be_edited;
	data["can_manage_chat"] = can_manage_chat;
	data["can_delete_messages"] = can_delete_messages;
	data["can_manage_video_chats"] = can_manage_video_chats;
	data["can_restrict_members"] = can_restrict_members;
	data["can_promote_members"] = can_promote_members;
	data["can_change_info"] = can_change_info;
	data["can_invite_users"] = can_invite_users;
	data["can_post_stories"] = can_post_stories;
	data["can_edit_stories"] = can_edit_stories;
	data["can_delete_stories"] = can_delete_stories;
	if(can_post_messages) data["can_post_messages"] = can_post_messages.value();
	if(can_edit_messages) data["can_edit_messages"] = can_edit_messages.value();
	if(can_pin_messages) data["can_pin_messages"] = can_pin_messages.value();
	if(can_manage_topics) data["can_manage_topics"] = can_manage_topics.value();
	if(custom_title) data["custom_title"] = custom_title.value();
	return data;
}

