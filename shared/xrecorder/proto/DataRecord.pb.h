// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: xrecorder/proto/DataRecord.proto

#ifndef PROTOBUF_xrecorder_2fproto_2fDataRecord_2eproto__INCLUDED
#define PROTOBUF_xrecorder_2fproto_2fDataRecord_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
#include "mixr/recorder/protobuf_v2/proto/DataRecord.pb.h"
// @@protoc_insertion_point(includes)

namespace mixr {
namespace xrecorder {
namespace proto {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_xrecorder_2fproto_2fDataRecord_2eproto();
void protobuf_AssignDesc_xrecorder_2fproto_2fDataRecord_2eproto();
void protobuf_ShutdownFile_xrecorder_2fproto_2fDataRecord_2eproto();

class MyDataMsg;

// ===================================================================

class MyDataMsg : public ::google::protobuf::Message {
 public:
  MyDataMsg();
  virtual ~MyDataMsg();

  MyDataMsg(const MyDataMsg& from);

  inline MyDataMsg& operator=(const MyDataMsg& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const MyDataMsg& default_instance();

  void Swap(MyDataMsg* other);

  // implements Message ----------------------------------------------

  MyDataMsg* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const MyDataMsg& from);
  void MergeFrom(const MyDataMsg& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required uint32 fee = 1;
  inline bool has_fee() const;
  inline void clear_fee();
  static const int kFeeFieldNumber = 1;
  inline ::google::protobuf::uint32 fee() const;
  inline void set_fee(::google::protobuf::uint32 value);

  // required uint32 fi = 2;
  inline bool has_fi() const;
  inline void clear_fi();
  static const int kFiFieldNumber = 2;
  inline ::google::protobuf::uint32 fi() const;
  inline void set_fi(::google::protobuf::uint32 value);

  // required uint32 fo = 3;
  inline bool has_fo() const;
  inline void clear_fo();
  static const int kFoFieldNumber = 3;
  inline ::google::protobuf::uint32 fo() const;
  inline void set_fo(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:mixr.xrecorder.proto.MyDataMsg)
 private:
  inline void set_has_fee();
  inline void clear_has_fee();
  inline void set_has_fi();
  inline void clear_has_fi();
  inline void set_has_fo();
  inline void clear_has_fo();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::uint32 fee_;
  ::google::protobuf::uint32 fi_;
  ::google::protobuf::uint32 fo_;
  friend void  protobuf_AddDesc_xrecorder_2fproto_2fDataRecord_2eproto();
  friend void protobuf_AssignDesc_xrecorder_2fproto_2fDataRecord_2eproto();
  friend void protobuf_ShutdownFile_xrecorder_2fproto_2fDataRecord_2eproto();

  void InitAsDefaultInstance();
  static MyDataMsg* default_instance_;
};
// ===================================================================

static const int kMyDataMsgFieldNumber = 1000;
extern ::google::protobuf::internal::ExtensionIdentifier< ::mixr::recorder::protobuf_v2::proto::DataRecord,
    ::google::protobuf::internal::MessageTypeTraits< ::mixr::xrecorder::proto::MyDataMsg >, 11, false >
  my_data_msg;
static const int kFooFieldNumber = 100;
extern ::google::protobuf::internal::ExtensionIdentifier< ::mixr::recorder::protobuf_v2::proto::MarkerMsg,
    ::google::protobuf::internal::PrimitiveTypeTraits< ::google::protobuf::uint32 >, 13, false >
  foo;

// ===================================================================

// MyDataMsg

// required uint32 fee = 1;
inline bool MyDataMsg::has_fee() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void MyDataMsg::set_has_fee() {
  _has_bits_[0] |= 0x00000001u;
}
inline void MyDataMsg::clear_has_fee() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void MyDataMsg::clear_fee() {
  fee_ = 0u;
  clear_has_fee();
}
inline ::google::protobuf::uint32 MyDataMsg::fee() const {
  // @@protoc_insertion_point(field_get:mixr.xrecorder.proto.MyDataMsg.fee)
  return fee_;
}
inline void MyDataMsg::set_fee(::google::protobuf::uint32 value) {
  set_has_fee();
  fee_ = value;
  // @@protoc_insertion_point(field_set:mixr.xrecorder.proto.MyDataMsg.fee)
}

// required uint32 fi = 2;
inline bool MyDataMsg::has_fi() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void MyDataMsg::set_has_fi() {
  _has_bits_[0] |= 0x00000002u;
}
inline void MyDataMsg::clear_has_fi() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void MyDataMsg::clear_fi() {
  fi_ = 0u;
  clear_has_fi();
}
inline ::google::protobuf::uint32 MyDataMsg::fi() const {
  // @@protoc_insertion_point(field_get:mixr.xrecorder.proto.MyDataMsg.fi)
  return fi_;
}
inline void MyDataMsg::set_fi(::google::protobuf::uint32 value) {
  set_has_fi();
  fi_ = value;
  // @@protoc_insertion_point(field_set:mixr.xrecorder.proto.MyDataMsg.fi)
}

// required uint32 fo = 3;
inline bool MyDataMsg::has_fo() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void MyDataMsg::set_has_fo() {
  _has_bits_[0] |= 0x00000004u;
}
inline void MyDataMsg::clear_has_fo() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void MyDataMsg::clear_fo() {
  fo_ = 0u;
  clear_has_fo();
}
inline ::google::protobuf::uint32 MyDataMsg::fo() const {
  // @@protoc_insertion_point(field_get:mixr.xrecorder.proto.MyDataMsg.fo)
  return fo_;
}
inline void MyDataMsg::set_fo(::google::protobuf::uint32 value) {
  set_has_fo();
  fo_ = value;
  // @@protoc_insertion_point(field_set:mixr.xrecorder.proto.MyDataMsg.fo)
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace xrecorder
}  // namespace mixr

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_xrecorder_2fproto_2fDataRecord_2eproto__INCLUDED
