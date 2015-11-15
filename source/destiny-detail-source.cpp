#include <obs-module.h>

static const char * destiny_detail_get_name(void *data)
{
	UNUSED_PARAMETER(data);
	return "Destiny Detail";
}

struct destiny_detail_data
{
	int64_t account_id;
};

// TODO: Create the source data
// have to create a type of data to return
static void* destiny_detail_create(obs_data_t *settings, obs_source_t *source)
{
	destiny_detail_data* detail_data = new destiny_detail_data();

	//detail_data->account_id = 1;

	return detail_data;
}

// TODO: Destroy any data
static void destiny_detail_destroy(void *data)
{
	destiny_detail_data* context = (destiny_detail_data*)data;

	// Unload anything I need to first

	delete context;
}

static uint32_t destiny_detail_get_width(void *data)
{
	return 100;
}

static uint32_t destiny_detail_get_height(void *data)
{
	return 100;
}

// Assign defaults to whatever data we need for this source
static void destiny_detail_get_defaults(obs_data_t *settings)
{
	obs_data_set_default_int(settings, "account_id", 1);
}

// Creates all of the properties or "settings" for our source
static obs_properties_t *destiny_detail_properties(void *data)
{
	UNUSED_PARAMETER(data);

	obs_properties_t *props = obs_properties_create();

	obs_properties_add_int(
		props,
		"account_id",
		"AccountID",
		0,
		INT_MAX,
		1);

	return props;
}

// This is called when the settings page has been closed (new settings)
static void destiny_detail_update(void *data, obs_data_t *settings)
{
	destiny_detail_data *detail_data = (destiny_detail_data*)data;

	detail_data->account_id = obs_data_get_int(settings, "account_id");
}


static void destiny_detail_show(void *data)
{

}

static void destiny_detail_hide(void *data)
{

}

static void destiny_detail_render(void *data, gs_effect_t *effect)
{
	gs_reset_blend_state();

	vec4 clear_color;
	vec4_zero(&clear_color);

	clear_color.w = 1.0;
	clear_color.y = 255;

	// This clears the entire view
	gs_clear(GS_CLEAR_COLOR, &clear_color, 0.0f, 0);
}

static struct obs_source_info destiny_detail_info;

OBS_DECLARE_MODULE();

bool obs_module_load(void)
{
	destiny_detail_info.id = "destiny_detail_source";
	destiny_detail_info.type = OBS_SOURCE_TYPE_INPUT;
	destiny_detail_info.output_flags = OBS_SOURCE_VIDEO;
	destiny_detail_info.get_name = destiny_detail_get_name;
	destiny_detail_info.create = destiny_detail_create;
	destiny_detail_info.destroy = destiny_detail_destroy;
	destiny_detail_info.update = destiny_detail_update;
	destiny_detail_info.get_defaults = destiny_detail_get_defaults;
	destiny_detail_info.show = destiny_detail_show;
	destiny_detail_info.hide = destiny_detail_hide;
	destiny_detail_info.get_width = destiny_detail_get_width;
	destiny_detail_info.get_height = destiny_detail_get_height;
	destiny_detail_info.video_render = destiny_detail_render;
	destiny_detail_info.get_properties = destiny_detail_properties;

	obs_register_source(&destiny_detail_info);
	return true;
}