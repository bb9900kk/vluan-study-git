// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MyProtoJava.proto

#include "MyProtoJava.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)
namespace MyTestProtobufJava {
class SendMyDataTestDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<SendMyDataTest>
      _instance;
} _SendMyDataTest_default_instance_;
}  // namespace MyTestProtobufJava
namespace protobuf_MyProtoJava_2eproto {
void InitDefaultsSendMyDataTestImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  {
    void* ptr = &::MyTestProtobufJava::_SendMyDataTest_default_instance_;
    new (ptr) ::MyTestProtobufJava::SendMyDataTest();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::MyTestProtobufJava::SendMyDataTest::InitAsDefaultInstance();
}

void InitDefaultsSendMyDataTest() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsSendMyDataTestImpl);
}

::google::protobuf::Metadata file_level_metadata[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::MyTestProtobufJava::SendMyDataTest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::MyTestProtobufJava::SendMyDataTest, name_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::MyTestProtobufJava::SendMyDataTest, id_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::MyTestProtobufJava::SendMyDataTest, salary1_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::MyTestProtobufJava::SendMyDataTest, salary2_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::MyTestProtobufJava::SendMyDataTest, keyprivate_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::MyTestProtobufJava::SendMyDataTest)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::MyTestProtobufJava::_SendMyDataTest_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "MyProtoJava.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\021MyProtoJava.proto\022\022MyTestProtobufJava\""
      "`\n\016SendMyDataTest\022\014\n\004name\030\001 \001(\t\022\n\n\002id\030\002 "
      "\001(\005\022\017\n\007salary1\030\003 \001(\002\022\017\n\007salary2\030\004 \001(\001\022\022\n"
      "\nkeyPrivate\030\005 \001(\014B+\n\022MyTestProtobufJavaB"
      "\025MyTestProtobufJavaMsgb\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 190);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "MyProtoJava.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_MyProtoJava_2eproto
namespace MyTestProtobufJava {

// ===================================================================

void SendMyDataTest::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int SendMyDataTest::kNameFieldNumber;
const int SendMyDataTest::kIdFieldNumber;
const int SendMyDataTest::kSalary1FieldNumber;
const int SendMyDataTest::kSalary2FieldNumber;
const int SendMyDataTest::kKeyPrivateFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

SendMyDataTest::SendMyDataTest()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_MyProtoJava_2eproto::InitDefaultsSendMyDataTest();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:MyTestProtobufJava.SendMyDataTest)
}
SendMyDataTest::SendMyDataTest(const SendMyDataTest& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.name().size() > 0) {
    name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.name_);
  }
  keyprivate_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.keyprivate().size() > 0) {
    keyprivate_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.keyprivate_);
  }
  ::memcpy(&id_, &from.id_,
    static_cast<size_t>(reinterpret_cast<char*>(&salary2_) -
    reinterpret_cast<char*>(&id_)) + sizeof(salary2_));
  // @@protoc_insertion_point(copy_constructor:MyTestProtobufJava.SendMyDataTest)
}

void SendMyDataTest::SharedCtor() {
  name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  keyprivate_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&id_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&salary2_) -
      reinterpret_cast<char*>(&id_)) + sizeof(salary2_));
  _cached_size_ = 0;
}

SendMyDataTest::~SendMyDataTest() {
  // @@protoc_insertion_point(destructor:MyTestProtobufJava.SendMyDataTest)
  SharedDtor();
}

void SendMyDataTest::SharedDtor() {
  name_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  keyprivate_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void SendMyDataTest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SendMyDataTest::descriptor() {
  ::protobuf_MyProtoJava_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_MyProtoJava_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const SendMyDataTest& SendMyDataTest::default_instance() {
  ::protobuf_MyProtoJava_2eproto::InitDefaultsSendMyDataTest();
  return *internal_default_instance();
}

SendMyDataTest* SendMyDataTest::New(::google::protobuf::Arena* arena) const {
  SendMyDataTest* n = new SendMyDataTest;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void SendMyDataTest::Clear() {
// @@protoc_insertion_point(message_clear_start:MyTestProtobufJava.SendMyDataTest)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  keyprivate_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&id_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&salary2_) -
      reinterpret_cast<char*>(&id_)) + sizeof(salary2_));
  _internal_metadata_.Clear();
}

bool SendMyDataTest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:MyTestProtobufJava.SendMyDataTest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // string name = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_name()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->name().data(), static_cast<int>(this->name().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "MyTestProtobufJava.SendMyDataTest.name"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // int32 id = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &id_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // float salary1 = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(29u /* 29 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &salary1_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // double salary2 = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(33u /* 33 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &salary2_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // bytes keyPrivate = 5;
      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(42u /* 42 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_keyprivate()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:MyTestProtobufJava.SendMyDataTest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:MyTestProtobufJava.SendMyDataTest)
  return false;
#undef DO_
}

void SendMyDataTest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:MyTestProtobufJava.SendMyDataTest)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string name = 1;
  if (this->name().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->name().data(), static_cast<int>(this->name().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "MyTestProtobufJava.SendMyDataTest.name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->name(), output);
  }

  // int32 id = 2;
  if (this->id() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->id(), output);
  }

  // float salary1 = 3;
  if (this->salary1() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(3, this->salary1(), output);
  }

  // double salary2 = 4;
  if (this->salary2() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(4, this->salary2(), output);
  }

  // bytes keyPrivate = 5;
  if (this->keyprivate().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      5, this->keyprivate(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:MyTestProtobufJava.SendMyDataTest)
}

::google::protobuf::uint8* SendMyDataTest::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:MyTestProtobufJava.SendMyDataTest)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string name = 1;
  if (this->name().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->name().data(), static_cast<int>(this->name().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "MyTestProtobufJava.SendMyDataTest.name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->name(), target);
  }

  // int32 id = 2;
  if (this->id() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->id(), target);
  }

  // float salary1 = 3;
  if (this->salary1() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(3, this->salary1(), target);
  }

  // double salary2 = 4;
  if (this->salary2() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(4, this->salary2(), target);
  }

  // bytes keyPrivate = 5;
  if (this->keyprivate().size() > 0) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        5, this->keyprivate(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:MyTestProtobufJava.SendMyDataTest)
  return target;
}

size_t SendMyDataTest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:MyTestProtobufJava.SendMyDataTest)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // string name = 1;
  if (this->name().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->name());
  }

  // bytes keyPrivate = 5;
  if (this->keyprivate().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::BytesSize(
        this->keyprivate());
  }

  // int32 id = 2;
  if (this->id() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->id());
  }

  // float salary1 = 3;
  if (this->salary1() != 0) {
    total_size += 1 + 4;
  }

  // double salary2 = 4;
  if (this->salary2() != 0) {
    total_size += 1 + 8;
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void SendMyDataTest::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:MyTestProtobufJava.SendMyDataTest)
  GOOGLE_DCHECK_NE(&from, this);
  const SendMyDataTest* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const SendMyDataTest>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:MyTestProtobufJava.SendMyDataTest)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:MyTestProtobufJava.SendMyDataTest)
    MergeFrom(*source);
  }
}

void SendMyDataTest::MergeFrom(const SendMyDataTest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:MyTestProtobufJava.SendMyDataTest)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.name().size() > 0) {

    name_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.name_);
  }
  if (from.keyprivate().size() > 0) {

    keyprivate_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.keyprivate_);
  }
  if (from.id() != 0) {
    set_id(from.id());
  }
  if (from.salary1() != 0) {
    set_salary1(from.salary1());
  }
  if (from.salary2() != 0) {
    set_salary2(from.salary2());
  }
}

void SendMyDataTest::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:MyTestProtobufJava.SendMyDataTest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SendMyDataTest::CopyFrom(const SendMyDataTest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:MyTestProtobufJava.SendMyDataTest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SendMyDataTest::IsInitialized() const {
  return true;
}

void SendMyDataTest::Swap(SendMyDataTest* other) {
  if (other == this) return;
  InternalSwap(other);
}
void SendMyDataTest::InternalSwap(SendMyDataTest* other) {
  using std::swap;
  name_.Swap(&other->name_);
  keyprivate_.Swap(&other->keyprivate_);
  swap(id_, other->id_);
  swap(salary1_, other->salary1_);
  swap(salary2_, other->salary2_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata SendMyDataTest::GetMetadata() const {
  protobuf_MyProtoJava_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_MyProtoJava_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace MyTestProtobufJava

// @@protoc_insertion_point(global_scope)
