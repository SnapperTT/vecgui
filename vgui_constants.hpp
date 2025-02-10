#define VC_STRINGIFY(X) #X
#define VC_ENUM_WRITE(NS,X) writeValue(writer, VGUI_STRING(#X)); return;
#define VC_ENUM_TO_SWITCH_CASE(NS,X) case NS::X: VC_ENUM_WRITE(NS,X)
#define VC_ENUM_FROM_IF_CASE(y, z, NS,X) if (y == #X) *z = NS::X; 

#ifndef VGUI_CONSTANTS_HPP
#define VGUI_CONSTANTS_HPP

#include <cstdint>

enum class Vgui_Alignment {
	VGUI_LEFT,
	VGUI_TOP,
	VGUI_CENTER,
	VGUI_RIGHT,
	VGUI_BOTTOM,
	VGUI_JUSTIFIED
	};
	
enum class Vgui_DimMode {
	VGUI_DIM_COORDINATE,	// Size is in points/pixels
	VGUI_DIM_EM,			// Size is in element padding numbers
	VGUI_DIM_PERCENT,		// Size is % of parent's inner size
	VGUI_DIM_TEXT,			// Size is the size of the text contained within
	VGUI_DIM_CHILD,			// Size is the size of the child elements
	VGUI_DIM_TEXT_ROWS		// Size is the number of text rows
	};
	
enum class Vgui_PosMode {
	VGUI_POS_COORDINATE,	// Pos is in points/pixels
	VGUI_POS_EM,			// Size is in element padding numbers
	VGUI_POS_PERCENT,		// Pos is % of parent's inner size
	VGUI_POS_TEXT_ROWS,		// Size is the number of text rows
	VGUI_POS_TEXT_LEN		// Sylte only - Size is % of the parents text
	};
	
enum class Vgui_TextEditEvent {
	VGUI_TEXTEDIT_INSERT,
	VGUI_TEXTEDIT_BACKSPACE,
	VGUI_TEXTEDIT_DELETE,
	VGUI_TEXTEDIT_CUT,
	VGUI_TEXTEDIT_COPY,
	VGUI_TEXTEDIT_CURSOR_LEFT,
	VGUI_TEXTEDIT_CURSOR_RIGHT,
	VGUI_TEXTEDIT_CURSOR_UP,
	VGUI_TEXTEDIT_CURSOR_DOWN
	};

	
constexpr uint8_t VGUI_MB_LEFT   = 1 << 0;
constexpr uint8_t VGUI_MB_RIGHT  = 1 << 1;
constexpr uint8_t VGUI_MB_MIDDLE = 1 << 2;
constexpr float VGUI_PI = 3.14159265358979323846;

#ifdef STTR_ENABLED

namespace jv_helper {
	static void writeValue_Vgui_TextEditEvent(rapidjson_writer * writer, Vgui_TextEditEvent const & obj) {
		switch (obj) {
			VC_ENUM_TO_SWITCH_CASE(Vgui_TextEditEvent,VGUI_TEXTEDIT_INSERT)
			VC_ENUM_TO_SWITCH_CASE(Vgui_TextEditEvent,VGUI_TEXTEDIT_BACKSPACE)
			VC_ENUM_TO_SWITCH_CASE(Vgui_TextEditEvent,VGUI_TEXTEDIT_DELETE)
			VC_ENUM_TO_SWITCH_CASE(Vgui_TextEditEvent,VGUI_TEXTEDIT_CUT)
			VC_ENUM_TO_SWITCH_CASE(Vgui_TextEditEvent,VGUI_TEXTEDIT_COPY)
			VC_ENUM_TO_SWITCH_CASE(Vgui_TextEditEvent,VGUI_TEXTEDIT_CURSOR_LEFT)
			VC_ENUM_TO_SWITCH_CASE(Vgui_TextEditEvent,VGUI_TEXTEDIT_CURSOR_RIGHT)
			VC_ENUM_TO_SWITCH_CASE(Vgui_TextEditEvent,VGUI_TEXTEDIT_CURSOR_UP)
			VC_ENUM_TO_SWITCH_CASE(Vgui_TextEditEvent,VGUI_TEXTEDIT_CURSOR_DOWN)
			}
		VC_ENUM_WRITE(Vgui_TextEditEvent,VGUI_TEXTEDIT_INSERT); // Default value
		}
	template<> inline void writeValue(rapidjson_writer * writer, Vgui_TextEditEvent const & obj) { writeValue_Vgui_TextEditEvent(writer, obj); }

	static void fetchGeneric_Vgui_TextEditEvent(Vgui_TextEditEvent * dst, const rapidjson::Value & v) {
		VGUI_STRING value; jv_helper::fetchString(value, v);
		VC_ENUM_FROM_IF_CASE(value, dst, Vgui_TextEditEvent,VGUI_TEXTEDIT_INSERT)
		else VC_ENUM_FROM_IF_CASE(value, dst, Vgui_TextEditEvent,VGUI_TEXTEDIT_BACKSPACE)
		else VC_ENUM_FROM_IF_CASE(value, dst, Vgui_TextEditEvent,VGUI_TEXTEDIT_DELETE)
		else VC_ENUM_FROM_IF_CASE(value, dst, Vgui_TextEditEvent,VGUI_TEXTEDIT_CUT)
		else VC_ENUM_FROM_IF_CASE(value, dst, Vgui_TextEditEvent,VGUI_TEXTEDIT_COPY)
		else VC_ENUM_FROM_IF_CASE(value, dst, Vgui_TextEditEvent,VGUI_TEXTEDIT_CURSOR_LEFT)
		else VC_ENUM_FROM_IF_CASE(value, dst, Vgui_TextEditEvent,VGUI_TEXTEDIT_CURSOR_RIGHT)
		else VC_ENUM_FROM_IF_CASE(value, dst, Vgui_TextEditEvent,VGUI_TEXTEDIT_CURSOR_UP)
		else VC_ENUM_FROM_IF_CASE(value, dst, Vgui_TextEditEvent,VGUI_TEXTEDIT_CURSOR_DOWN)
		else *dst = Vgui_TextEditEvent::VGUI_TEXTEDIT_INSERT;
		}
	template<> inline void fetchGeneric<Vgui_TextEditEvent>(Vgui_TextEditEvent * dst, const rapidjson::Value & v) { fetchGeneric_Vgui_TextEditEvent(dst, v); }
		
	static void writeValue_Vgui_Alignment(rapidjson_writer * writer, Vgui_Alignment const & obj) {
		switch (obj) {
			VC_ENUM_TO_SWITCH_CASE(Vgui_Alignment,VGUI_LEFT)
			VC_ENUM_TO_SWITCH_CASE(Vgui_Alignment,VGUI_TOP)
			VC_ENUM_TO_SWITCH_CASE(Vgui_Alignment,VGUI_CENTER)
			VC_ENUM_TO_SWITCH_CASE(Vgui_Alignment,VGUI_RIGHT)
			VC_ENUM_TO_SWITCH_CASE(Vgui_Alignment,VGUI_BOTTOM)
			VC_ENUM_TO_SWITCH_CASE(Vgui_Alignment,VGUI_JUSTIFIED)
			}
		return VC_ENUM_WRITE(Vgui_Alignment,VGUI_LEFT); // Default value
		}
	template<> inline void writeValue(rapidjson_writer * writer, Vgui_Alignment const & obj) { writeValue_Vgui_Alignment(writer, obj); }
		
	static void fetchGeneric_Vgui_Alignment(Vgui_Alignment * dst, const rapidjson::Value & v) {
		VGUI_STRING value; jv_helper::fetchString(value, v);
		VC_ENUM_FROM_IF_CASE(value, dst, Vgui_Alignment,VGUI_LEFT)
		else VC_ENUM_FROM_IF_CASE(value, dst, Vgui_Alignment,VGUI_TOP)
		else VC_ENUM_FROM_IF_CASE(value, dst, Vgui_Alignment,VGUI_CENTER)
		else VC_ENUM_FROM_IF_CASE(value, dst, Vgui_Alignment,VGUI_RIGHT)
		else VC_ENUM_FROM_IF_CASE(value, dst, Vgui_Alignment,VGUI_BOTTOM)
		else VC_ENUM_FROM_IF_CASE(value, dst, Vgui_Alignment,VGUI_JUSTIFIED)
		else *dst = Vgui_Alignment::VGUI_LEFT;
		}
	template<> inline void fetchGeneric<Vgui_Alignment>(Vgui_Alignment * dst, const rapidjson::Value & v) { fetchGeneric_Vgui_Alignment(dst, v); }
		
	static void writeValue_Vgui_PosMode(rapidjson_writer * writer, Vgui_PosMode const & obj) {
		switch (obj) {
			VC_ENUM_TO_SWITCH_CASE(Vgui_PosMode,VGUI_POS_COORDINATE)
			VC_ENUM_TO_SWITCH_CASE(Vgui_PosMode,VGUI_POS_EM)
			VC_ENUM_TO_SWITCH_CASE(Vgui_PosMode,VGUI_POS_PERCENT)
			VC_ENUM_TO_SWITCH_CASE(Vgui_PosMode,VGUI_POS_TEXT_ROWS)
			VC_ENUM_TO_SWITCH_CASE(Vgui_PosMode,VGUI_POS_TEXT_LEN)
			}
		return VC_ENUM_WRITE(Vgui_PosMode,VGUI_POS_COORDINATE); // Default value
		}
	template<> inline void writeValue(rapidjson_writer * writer, Vgui_PosMode const & obj) { writeValue_Vgui_PosMode(writer, obj); }

	static void fetchGeneric_Vgui_PosMode(Vgui_PosMode * dst, const rapidjson::Value & v) {
		VGUI_STRING value; jv_helper::fetchString(value, v);
		VC_ENUM_FROM_IF_CASE(value, dst, Vgui_PosMode,VGUI_POS_COORDINATE)
		else VC_ENUM_FROM_IF_CASE(value, dst, Vgui_PosMode,VGUI_POS_EM)
		else VC_ENUM_FROM_IF_CASE(value, dst, Vgui_PosMode,VGUI_POS_PERCENT)
		else VC_ENUM_FROM_IF_CASE(value, dst, Vgui_PosMode,VGUI_POS_TEXT_ROWS)
		else VC_ENUM_FROM_IF_CASE(value, dst, Vgui_PosMode,VGUI_POS_TEXT_LEN)
		else *dst = Vgui_PosMode::VGUI_POS_COORDINATE;
		}
	template<> inline void fetchGeneric<Vgui_PosMode>(Vgui_PosMode * dst, const rapidjson::Value & v) { fetchGeneric_Vgui_PosMode(dst, v); }

	static void writeValue_Vgui_DimMode(rapidjson_writer * writer, Vgui_DimMode const & obj) {
		switch (obj) {
			VC_ENUM_TO_SWITCH_CASE(Vgui_DimMode,VGUI_DIM_COORDINATE)
			VC_ENUM_TO_SWITCH_CASE(Vgui_DimMode,VGUI_DIM_EM)
			VC_ENUM_TO_SWITCH_CASE(Vgui_DimMode,VGUI_DIM_PERCENT)
			VC_ENUM_TO_SWITCH_CASE(Vgui_DimMode,VGUI_DIM_TEXT)
			VC_ENUM_TO_SWITCH_CASE(Vgui_DimMode,VGUI_DIM_CHILD)
			VC_ENUM_TO_SWITCH_CASE(Vgui_DimMode,VGUI_DIM_TEXT_ROWS)
			}
		return VC_ENUM_WRITE(Vgui_DimMode,VGUI_DIM_COORDINATE); // Default value
		}
	template<> inline void writeValue(rapidjson_writer * writer, Vgui_DimMode const & obj) { writeValue_Vgui_DimMode(writer, obj); }

	static void fetchGeneric_Vgui_DimMode(Vgui_DimMode * dst, const rapidjson::Value & v) {
		VGUI_STRING value; jv_helper::fetchString(value, v);
		VC_ENUM_FROM_IF_CASE(value, dst, Vgui_DimMode,VGUI_DIM_COORDINATE)
		else VC_ENUM_FROM_IF_CASE(value, dst, Vgui_DimMode,VGUI_DIM_EM)
		else VC_ENUM_FROM_IF_CASE(value, dst, Vgui_DimMode,VGUI_DIM_PERCENT)
		else VC_ENUM_FROM_IF_CASE(value, dst, Vgui_DimMode,VGUI_DIM_TEXT)
		else VC_ENUM_FROM_IF_CASE(value, dst, Vgui_DimMode,VGUI_DIM_CHILD)
		else VC_ENUM_FROM_IF_CASE(value, dst, Vgui_DimMode,VGUI_DIM_TEXT_ROWS)
		else *dst = Vgui_DimMode::VGUI_DIM_COORDINATE;
		}
	template<> inline void fetchGeneric<Vgui_DimMode>(Vgui_DimMode * dst, const rapidjson::Value & v) { fetchGeneric_Vgui_DimMode(dst, v); }
	
	}

#endif
#endif
